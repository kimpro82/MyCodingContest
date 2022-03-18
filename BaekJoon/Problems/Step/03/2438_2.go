package main
import "fmt"

func main() {
	var n int
	fmt.Scanln(&n)

    var star string = ""
    for i := 1; i <= n; i++ {
        star += "*"
        fmt.Println(star)
    }
}