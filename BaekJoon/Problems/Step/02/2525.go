package main
import "fmt"

func main() {
    var a, b, c int
    fmt.Scanln(&a, &b)
    fmt.Scanln(&c)

    b += c
    for (b > 59) {      // Golang has no While statement!
        a++
        b -= 60        
    }                   // actually not necessary to use loop

    a %= 24

    fmt.Println(a, b)
}