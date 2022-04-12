package main
import (
    "fmt"
    "strconv"
)

func main() {
    var a, b, c int
    fmt.Scanln(&a)
    fmt.Scanln(&b)
    fmt.Scanln(&c)

    var prod string = strconv.Itoa(a * b * c)
    var length int = len(prod)

    var arr [10]int
    for i := 0; i < length; i++ {
        arr[prod[i] - '0']++
    }

    for j := 0; j < 10; j++ {
        fmt.Println(arr[j])
    }
}