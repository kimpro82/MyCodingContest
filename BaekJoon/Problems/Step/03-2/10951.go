package main
import (
    "fmt"
    "strconv"
)

func main() {
    for true {
        var a, b string
        var aInt, bInt int

        fmt.Scanln(&a, &b)
        if a == "" {
            break
        }

        aInt, _ = strconv.Atoi(a)
        bInt, _ = strconv.Atoi(b)
        fmt.Println(aInt + bInt)
    }
}