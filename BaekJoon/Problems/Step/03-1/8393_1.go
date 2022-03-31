package main
import "fmt"

func main() {
    var n int
    fmt.Scanln(&n)

    var sum int = 0
    for i := 1; i <= n; i++ {
       sum += i
    }

    fmt.Println(sum)
}