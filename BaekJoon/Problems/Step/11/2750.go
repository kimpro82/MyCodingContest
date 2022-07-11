package main
import (
    "fmt"
    "sort"
)

func main() {

    var n int                                   // n <= 1,000
    fmt.Scanln(&n)
    var num []int

    for i := 0; i < n; i++ {
        // Input
        var temp int
        fmt.Scanln(&temp)
        num = append(num, temp)                 // not slow?
    }

    // Sort
    sort.Ints(num)

    // Output
    for i := 0; i < n; i++ {
        fmt.Println(num[i])
    }
}