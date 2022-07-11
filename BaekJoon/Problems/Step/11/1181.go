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

    var n int                                        // n <= 20,000
    fmt.Scanln(&n)
    var words []string

    // Input
    for i := 0; i < n; i++ {
        var temp string
        fmt.Fscanln(reader, &temp)
        words = append(words, temp)
    }

    // Sort
    sort.SliceStable(words, func(i, j int) bool {
        if len(words[i]) == len(words[j]) {
            return words[i] < words[j]
        } else {
            return len(words[i]) < len(words[j])
        }
    })

    // Output
    for i := 0; i < n; i++ {
        // It would be better to use set but …… (Golang has not set)
        if i == 0 {
            fmt.Fprintln(writer, words[i])            
        } else if words[i] != words[i-1] {
            fmt.Fprintln(writer, words[i])            
        }
    }
}