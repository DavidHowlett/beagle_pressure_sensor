package main

import (
	//"time"
	"fmt"
	"github.com/kidoman/embd"
)

func main() {
	//bus := embd.NewI2CBus(1)
	for {
		print("foo\n")
		//x, err := bus.ReadByte(0x78)
		//fmt.Print(x)
		//fmt.Print(err)
        fmt.Print(embd.DetectHost())
		//embd.LEDToggle("LED0")
		//time.Sleep(2000 * time.Millisecond)

	}

}
