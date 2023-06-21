package main
import "fmt"

func main() {

    // Input
    var n int
    var num string
    fmt.Scanln(&n)
    fmt.Scanln(&num)

    // Calculate sum
    var sum int = 0
    var digit rune
    for _, digit = range num {
        sum += int(digit - '0')
    }

    // Output
    fmt.Println(sum)
}