package main
import "fmt"

func main() {
    var a, b int

    for true {
        fmt.Scanln(&a, &b)

        if a == 0 && b == 0 {
            break
        }

        fmt.Println(a + b)
    }
}