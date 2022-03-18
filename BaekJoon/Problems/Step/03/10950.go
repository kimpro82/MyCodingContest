package main
import "fmt"

func main() {
    var t int
    fmt.Scanln(&t)

    for i := 0; i < t; i++ {
        var a, b int
        fmt.Scanln(&a, &b)

        fmt.Println(a + b)
    }
}