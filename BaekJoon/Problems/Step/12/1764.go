package main

import (
	"bufio"
	"fmt"
	"os"
    "sort"
)

func main() {

	// Make it faster
	var reader = bufio.NewReader(os.Stdin)
	var writer = bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	var n, m int                                             // n, m <= 500,000
	fmt.Scanln(&n, &m)

	// Input a map[string]int
	var nameMap map[string]int = make(map[string]int)
	var temp string
    for i := 0; i < n + m; i++ {
		fmt.Fscanln(reader, &temp)
        nameMap[temp]++
	}

	// Make []string from nm with value 2 and sort it
	var nameSorted []string
    for k, v := range nameMap {
        if v > 1 {
            nameSorted = append(nameSorted, k)
        }
    }
    sort.Strings(nameSorted)

	// Input m questions and get answers
    var length int = len(nameSorted)
    fmt.Fprintln(writer, length)
	for _, name := range nameSorted {
        fmt.Fprintln(writer, name)
	}
}