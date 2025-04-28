package main

import (
	"context"
	"fmt"
	"log"
	"time"

	"github.com/segmentio/kafka-go"
)

func main() {
	topic := "test"
	partition := 0
	targetTime := time.Date(2025, 4, 28, 14, 4, 18, 0, time.UTC) // 收到消息: {Topic:test Partition:0 Offset:69 HighWaterMark:72 Key:[] Value:[111 110 101] Headers:[] WriterData:<nil> Time:2025-04-28 14:04:18.901 +0000 UTC}
	fmt.Println(targetTime)
	address := "21.91.223.151:9092"

	conn, err := kafka.DialLeader(context.Background(), "tcp", address, topic, partition)
	if err != nil {
		log.Fatal("连接失败:", err)
	}
	defer conn.Close()

	fmt.Println("successfully get conn")

	// 2. 查询时间戳对应的偏移量
	offset, err := conn.ReadOffset(targetTime)
	if err != nil {
		log.Fatal("failed to get offset")
	}

	fmt.Println("offset:", offset)

	reader := kafka.NewReader(kafka.ReaderConfig{
		Brokers:          []string{address},
		Topic:            topic,
		Partition:        partition,
		ReadBatchTimeout: 2 * time.Second,
	})
	reader.SetOffset(offset)
	defer reader.Close()
	for {
		// 创建带超时的context
		ctx, cancel := context.WithTimeout(context.Background(), 3*time.Second)
		m, err := reader.ReadMessage(ctx)
		cancel()
		if err != nil {
			if err == context.DeadlineExceeded {
				fmt.Println("等待消息超时")
				continue
			}
			log.Fatal(err)
		}
		fmt.Printf("收到消息: %+v\n", m)
	}
}
