package main
import "fmt"

func main() {
    var n, a, b int                    // n < 100
    fmt.Scanln(&n)    

    var t int = 0
    var ab = n

    for true {
        a = ab / 10
        b = ab % 10
        ab = a + b

        if (ab < 10) {
            ab += b * 10
        } else {
            ab = b * 10 + ab % 10
        }

        t++

        if (n == ab){
        break;
        }
    }

    fmt.Println(t)
}