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

    var n int
    fmt.Scanln(&n)

    var arr []int = make([]int, n)

    var max int = -1000000
    var min int = 1000000
    for i := 0; i < n; i++ {
        fmt.Fscan(reader, &arr[i])

        if arr[i] > max {
            max = arr[i]
        }
        if arr[i] < min {
            min = arr[i]
        }
    }

    fmt.Println(min, max)
}