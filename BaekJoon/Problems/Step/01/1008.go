package main
import "fmt"

func main() {
	var a, b float64
	fmt.Scanln(&a, &b)

    fmt.Printf("%.10f\n", a / b)
}