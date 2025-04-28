package main

import (
	"context"
	"fmt"
	"time"

	"github.com/segmentio/kafka-go"
)

func main() {
	// 定义topic 和 partition
	topic := "test"
	partition := 0
	// dialLeader
	conn, err := kafka.DialLeader(context.Background(), "tcp", "21.91.223.151:9092", topic, partition)
	if err != nil {
		fmt.Println("Faile to connect to kafak", err)
		return
	}
	defer conn.Close()
	// SetWriteDeadline
	conn.SetWriteDeadline(time.Now().Add(10 * time.Second))
	// WriteMessage
	// 如何填 msgs ...kafka.Message 参数？
	// 如何填 []byte 参数？
	cnt, err := conn.WriteMessages(
		kafka.Message{Value: []byte("one")},
		kafka.Message{Value: []byte("two")},
		kafka.Message{Value: []byte("three")},
	)
	if err == nil {
		fmt.Println("successfully write ", cnt, "message to kafka")
	} else {
		fmt.Println("failed to write message into kafka", err)
	}
	// close
}
