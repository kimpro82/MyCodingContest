package main
import "fmt"

func main() {
	var n int
	fmt.Scanln(&n)

    var sum = n * (n + 1) / 2

    fmt.Println(sum)
}