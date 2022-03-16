package main
import "fmt"

func main() {
    var x, y int
    fmt.Scanln(&x)
    fmt.Scanln(&y)

    var dim int
    if (x > 0 && y > 0) {
        dim = 1
    } else if (x < 0 && y > 0) {
        dim = 2
    } else if (x < 0 && y < 0) {
        dim = 3
    } else {
        dim = 4
    }

    fmt.Println(dim)
}