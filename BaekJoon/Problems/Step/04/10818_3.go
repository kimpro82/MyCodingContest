package main
import (
    "fmt"
    "bufio"
    "os"
    "sort"
)

func main() {
    var reader = bufio.NewReader(os.Stdin)
    var writer = bufio.NewWriter(os.Stdout)
    defer writer.Flush()

    var n int
    fmt.Scanln(&n)

    var arr []int = make([]int, n)

    for i := 0; i < n; i++ {
        fmt.Fscan(reader, &arr[i])
    }

    // using sort.Sort()
    sort.Sort(sort.IntSlice(arr))
    fmt.Println(arr[0], arr[n - 1])
}