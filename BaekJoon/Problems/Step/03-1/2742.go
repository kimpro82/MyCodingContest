package main
import (
    "fmt"
    "bufio"
    "os"
)

func main() {
    // reader := bufio.NewReader(os.Stdin)      // do not need
    var writer = bufio.NewWriter(os.Stdout)
    defer writer.Flush()

    var n int
    fmt.Scanln(&n)

    for i := n; i > 0; i-- {
       fmt.Fprintln(writer, i)
    }
}