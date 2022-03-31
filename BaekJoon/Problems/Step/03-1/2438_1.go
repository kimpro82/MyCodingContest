package main
import (
    "fmt"
    "strings"
)

func main() {
    var n int
    fmt.Scanln(&n)

    var star string = "*"
    for i := 1; i <= n; i++ {
        fmt.Println(strings.Repeat(star, i ))
    }
}