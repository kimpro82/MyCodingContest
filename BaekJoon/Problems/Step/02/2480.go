package main
import (
    "fmt"
    // "math"
)

func main() {
    var a, b, c int
    fmt.Scanln(&a, &b, &c)

    var prize int
    if (a == b && b == c) {
        prize = 10000 + a * 1000
    } else if (a == b) {
        prize = 1000 + a * 100
    } else if (b == c) {
        prize = 1000 + b * 100
    } else if (c == a) {
        // trial 3
        prize = 1000 + c * 100        // I missed it!
    } else {
        // trial 1 : false
        // var max int = int(math.Max(math.Max(float64(a), float64(b)), float64(c)))

        // trial 2 : false
        var max int = a
        if (max < b) {
            max = b
        }
        if (max < c) {
            max = c
        }

        prize = max * 100
    }

    fmt.Println(prize)
}