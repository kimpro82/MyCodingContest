// 10815. 숫자 카드
// 2023.07.08

/* Sample input & output data
5
6 3 2 10 -10
8
10 9 -5 2 3 4 5 -10

1 0 0 1 1 0 0 1
*/

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

    // Input 1
    var n int
    fmt.Fscan(reader, &n)
    var mp map[int]bool = make(map[int]bool)
    var temp int
    for i := 0; i < n; i++ {
        fmt.Fscan(reader, &temp)
        mp[temp] = true
    }

    // Input 2 & Operate
    var m int
    fmt.Fscan(reader, &m)
    var v []int
    for i := 0; i < m; i++ {
        fmt.Fscan(reader, &temp)
        if mp[temp] {
            v = append(v, 1)
        } else {
            v = append(v, 0)
        }
    }

    // Output
    for i := 0; i < m; i++ {
        fmt.Fprint(writer, v[i], " ")
    }
    fmt.Fprintln(writer)
}
