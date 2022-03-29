package main
import "fmt"

func main() {
    var t int
    fmt.Scanln(&t)

    for i := 1; i <= t; i++ {
        var a, b int
        fmt.Scanln(&a, &b)
        fmt.Printf("Case #%d: %d + %d = %d\n", i, a, b, a + b)
    }
}