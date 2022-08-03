package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

func main() {

    // Make it faster
    var reader = bufio.NewReader(os.Stdin)
    var writer = bufio.NewWriter(os.Stdout)
    defer writer.Flush()

    var n, m int                                            // n, m <= 10,000
    fmt.Scanln(&n, &m)

    // Input n strings
    var ns []string
    for i := 0; i < n; i++ {
        var temp string
        fmt.Fscanln(reader, &temp)
        ns = append(ns, temp)
    }

    // Sort n strings
    sort.Strings(ns)

    // Input m strings and count intersaction with n strings
    var ms string
    var nsIdx int
    var count int = 0
    for i := 0; i < m; i++ {
        fmt.Fscanln(reader, &ms)
        nsIdx = sort.SearchStrings(ns, ms)
        // SearchStrings searches for x in a sorted slice of strings and returns the index as specified by Search.
        // The return value is the index to insert x if x is not present (it could be len(a)).
        // The slice must be sorted in ascending order.
        // → inferred as a binary search
        if nsIdx < n {
        // nsIdx == n means not present
            if ns[nsIdx] == ms {
            count++
            }
        }
    }

    // Output
    fmt.Fprintln(writer, count)
}