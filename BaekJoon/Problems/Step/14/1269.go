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

    var n, m int                                             // n, m <= 200,000
    fmt.Scanln(&n, &m)

    // Input n + m integers into a map[int]int
    var nm map[int]int = make(map[int]int)
    var temp int
    for i := 0; i < n + m; i++ {
        fmt.Fscan(reader, &temp)
        nm[temp]++
    }

    // Count the difference set
    var count int = 0
    for _, v := range nm {
        if v == 1 {
            count++
        }
    }

    // Output
    fmt.Fprintln(writer, count)
}