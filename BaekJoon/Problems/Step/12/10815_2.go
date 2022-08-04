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

    var n int                                               // n <= 500,000
    fmt.Scanln(&n)

    // Input and sort
    var card []int
    var temp int
    for i := 0; i < n; i++ {
        fmt.Fscan(reader, &temp)
        card = append(card, temp)
    }
    sort.Ints(card)

    var m int                                               // m <= 500,000
    fmt.Scanln(&m)

    // Find if exists and output
    var idx, ans int
    for i := 0; i < m; i++ {
        fmt.Fscan(reader, &temp)

        // sort.SearchInts() : return the index to insert x if x is not present (it could be len(a))
        idx = sort.SearchInts(card, temp)
        if temp == card[idx] {
            ans = 1
        } else {
            ans = 0
        }
        
        if i < m - 1 {
            fmt.Fprint(writer, ans, " ")
        } else {
            fmt.Fprintln(writer, ans)
        }
    }
}