package main
import "fmt"

func main() {

    var t, r int
    var s string
    fmt.Scanln(&t)

    for i := 0; i < t; i++ {
        fmt.Scanln(&r, &s)

        for j := 0; j < len(s); j++ {
            for k := 0; k < r; k++ {
                fmt.Print(string(s[j]))
            }
        }
        fmt.Println()
    }
}