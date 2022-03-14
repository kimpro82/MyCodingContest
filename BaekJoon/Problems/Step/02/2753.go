package main
import "fmt"

func main() {
    var n int
    fmt.Scanln(&n)

    var answer int
    if (n % 4 == 0 && (n % 100 != 0 || n % 400 == 0)) {
        answer = 1
    } else {
        answer = 0
    }

    fmt.Println(answer)
}