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
	// dial leader
	conn, err := kafka.DialLeader(context.Background(), "tcp", "21.91.223.151:9092", topic, partition)
	if err != nil {
		log.Fatal("failed to connect to kafka", err)
	}
	defer conn.Close()

	// set deadline
	conn.SetReadDeadline(time.Now().Add(10 * time.Second))
	// read batch
	batch := conn.ReadBatch(5, 1e6)

	// 注意 SetReadDeadline 和 ReadBatch 的工作原理：ReadBatch 最少读取10KB数据，该方法会阻塞 直到读到10KB数据或者SetReadDeadline的时间超时
	buf := make([]byte, 10e3)
	defer batch.Close()

	// batch read
	for {
		n, err := batch.Read(buf)
		if err != nil {
			break
		}
		fmt.Println(string(buf[:n]))
	}
}
