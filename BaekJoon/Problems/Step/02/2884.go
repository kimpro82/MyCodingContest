package main
import "fmt"

func main() {
    var h, m int
    fmt.Scanln(&h, &m)

    if (m < 45) {
        h--
        m += 60
    }
    if (h < 0) {
        h += 24
    }

    fmt.Println(h, m - 45)
}