package main
import (
    "fmt"
    "bufio"
    "os"
    "sort"
)

func main() {

    // Make it faster
    var reader = bufio.NewReader(os.Stdin)
    var writer = bufio.NewWriter(os.Stdout)
    defer writer.Flush()

    var n int                                   // n <= 1,000,000
    fmt.Scanln(&n)
    var num []int

    // Input
    for i := 0; i < n; i++ {
        var temp int
        fmt.Fscanln(reader, &temp)
        num = append(num, temp)
    }

    // Sort
    sort.Ints(num)

    // Output
    for i := 0; i < n; i++ {
        fmt.Fprintln(writer, num[i])
    }
}