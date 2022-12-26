package main
import (
    "fmt"
    "bufio"                                                 // default size : 4096 byte
    "os"
    // "time"
)

func main() {

    // Make it faster
    // var reader = bufio.NewReader(os.Stdin)
    var reader = bufio.NewReaderSize(os.Stdin, 80000004)
    // var writer = bufio.NewWriter(os.Stdout)
    var writer = bufio.NewWriterSize(os.Stdout, 80000004)
    defer writer.Flush()

    var n int                                               // n <= 500,000
    fmt.Scanln(&n)

    // Input
    var card [20000001]bool
    for i := 0; i < n; i++ {
        var temp int
        fmt.Fscan(reader, &temp)
        card[10000000+temp] = true
    }

    // Wait until the reader buffer has been empty
    for reader.Buffered() > 1 {
        // time.Sleep(time.Millisecond)
        // fmt.Println(reader.Buffered())
    }

    var m int                                               // m <= 500,000
    fmt.Scanln(&m)

    // Find if exists and output
    var exist int
    for i := 0; i < m; i++ {
        var temp int
        fmt.Fscan(reader, &temp)
        if card[10000000+temp] == true {
            exist = 1
        } else {
            exist = 0
        }

        if i < m - 1 {
            fmt.Fprint(writer, exist, " ")
        } else {
            fmt.Fprintln(writer, exist)
        }
    }
}