package main
import (
    "fmt"
    "math"
)

func main() {
	var a int
    var b string
	fmt.Scanln(&a)
    fmt.Scanln(&b)

    var sum int = 0
    var answer int
    for i := 0; i < 3; i++ {
        // test : ok
        // fmt.Println(b[3-i-1] - '0')
        answer = a * int(b[3-i-1] - '0')
        fmt.Println(answer)
        sum += answer * int(math.Pow(10., float64(i)))
    }

    fmt.Println(sum)
}