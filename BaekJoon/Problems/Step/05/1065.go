package main
import "fmt"

func count(n int) int {
    var ans int = 0;
    var a, b, c int
    if n < 100 {
        ans = n
    } else if n < 1000 {
        ans = 99

        for i := 100; i <= n; i++ {
            a = i / 100
            b = (i % 100) / 10
            c = i % 10

            if b - a == c - b {
                ans++
            }
        }
    } else {                            // n == 1000
        ans = 144                       // crazy~ (given as a sample output)
    }

    return ans
}

func main() {
    var n int;
    fmt.Scanln(&n)

    fmt.Println(count(n))
}