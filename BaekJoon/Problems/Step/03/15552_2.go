package main
import (
    "fmt"
    "bufio"
    "os"
)

func main() {
    var reader = bufio.NewReader(os.Stdin)
    var writer = bufio.NewWriter(os.Stdout)
    defer writer.Flush()

	var t int
	fmt.Scanln(&t)

    var a, b int
    for i := 0; i < t; i++ {
        fmt.Fscan(reader, &a, &b)
        fmt.Fprintln(writer, a + b)
    }
}