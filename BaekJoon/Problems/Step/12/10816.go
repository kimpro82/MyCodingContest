package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {

	// Make it faster
	var reader = bufio.NewReader(os.Stdin)
	var writer = bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	var n int                                                 // n <= 500,000
	fmt.Scanln(&n)

	// Input n map[int]int
	var nm map[int]int = make(map[int]int)
	var temp int
    for i := 0; i < n; i++ {
		fmt.Fscan(reader, &temp)
        nm[temp]++
	}

	var m int                                                 // m <= 500,000
	fmt.Scanln(&m)

	// Input m numbers and get answers
	for i := 0; i < m - 1; i++ {
		fmt.Fscan(reader, &temp)
		fmt.Fprint(writer, nm[temp], " ")
	}
    fmt.Fscan(reader, &temp)
	fmt.Fprint(writer, nm[temp])                              // crazy
    fmt.Fprintln(writer)
}