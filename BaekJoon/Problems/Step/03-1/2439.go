package main
import (
    "fmt"
    "strings"
)

func main() {
    var n int
    fmt.Scanln(&n)

    for i := 1; i <= n; i++ {
        fmt.Println(strings.Repeat(" ", n - i) + strings.Repeat("*", i ))   // not , but +
    }
}