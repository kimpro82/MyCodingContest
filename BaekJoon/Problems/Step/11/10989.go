package main
import (
    "fmt"
    "bufio"
    "os"
)

func main() {

    // Make it faster
    var reader = bufio.NewReader(os.Stdin)
    var writer = bufio.NewWriter(os.Stdout)
    defer writer.Flush()

    var n int                                        // n <= 1,000,000
    fmt.Scanln(&n)
    var num [10001]int

    // Input
    for i := 0; i < n; i++ {
        var temp int
        fmt.Fscanln(reader, &temp)
        num[temp]++
    }

    // Output
    for i := 0; i < 10001; i++ {
        for j := 0; j < num[i]; j++ {
            fmt.Fprintln(writer, i)
        }
    }
}