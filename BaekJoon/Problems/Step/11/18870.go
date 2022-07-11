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

    var n int                                        // n <= 1,000,000
    fmt.Scanln(&n)

    // Input
    var arr []int
    var m map[int]int = make(map[int]int)
    for i := 0; i < n; i++ {
        var temp int
        fmt.Fscan(reader, &temp)
        arr = append(arr, temp)

        _, exists := m[temp]
        if !exists {
            m[temp] = 0
        }
    }

    // Get a slice sorted by map's key
    var sortKeys []int
    for i := range m {
        sortKeys = append(sortKeys, i)
    }
    sort.Ints(sortKeys)

    // Count rank
    var rank int = 0
    for _, k := range sortKeys {
        m[k] = rank
        rank++
    }

    // Output
    for i := 0; i < n; i++ {
        fmt.Fprint(writer, m[arr[i]], " ")
    }
    fmt.Fprintln(writer)
}