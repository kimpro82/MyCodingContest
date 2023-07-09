// 10816. 숫자 카드 2
// 2023.07.08

/* Sample input & output data
10
6 3 2 10 10 10 -10 -10 7 3
8
10 9 -5 2 3 4 5 -10

3 0 0 1 2 0 0 2
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
    var mp map[int]int = make(map[int]int)
    var temp int
    for i := 0; i < n; i++ {
        fmt.Fscan(reader, &temp)
        mp[temp]++                                          // default value : 0
    }

    // Input 2 & Operate
    var m int
    fmt.Fscan(reader, &m)
    var v []int
    for i := 0; i < m; i++ {
        fmt.Fscan(reader, &temp)
        v = append(v, mp[temp])
    }

    // Output
    for i := 0; i < m; i++ {
        fmt.Fprint(writer, v[i], " ")
    }
    fmt.Fprintln(writer)
}
