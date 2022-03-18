package main
import "fmt"

func main() {
	var n, x int
	fmt.Scanln(&n, &x)

    for i := 0; i < n; i++ {
        var num int
	    fmt.Scanf("%d", &num)
        if num < x {
            fmt.Printf("%d ", num)
        }
    }
    // fmt.Println("\b")                // causes wrong?
}