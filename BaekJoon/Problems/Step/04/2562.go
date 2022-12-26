package main
import "fmt"

func main() {
    var n int
    var max int = 0
    var maxIdx int

    for i := 0; i < 9; i++ {
        fmt.Scanf("%d", &n)
        
        if n > max {
            max = n
            maxIdx = i
        }
    }

    fmt.Println(max, maxIdx + 1)
}