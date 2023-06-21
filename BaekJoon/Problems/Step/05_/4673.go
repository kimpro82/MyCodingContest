package main
import "fmt"

func digitadition(num int) int {

    var d int = num

    if num > 999 {
        d += num / 1000
    }
    if num > 99 {
        d += (num % 1000) / 100
    }
    if num > 9 {
        d += (num % 100) / 10
    }
    d += num % 10

    return d
}

func main() {

    var n int = 10001                            // n = 101 for test
    
    // Generate an array {1, 2, ……, 9999}
    var arr []int = make([]int, n)
    for i := 1; i < n; i++ {
        arr[i] = 1
    }

    // Remove non-self numbers from the array
    var temp int
    for i := 1; i < n; i++ {
        temp = digitadition(i)
        if temp < n {
            arr[temp] = 0
        }
    }

    // Output
    for i := 1; i < n; i++ {
        if arr[i] == 1 {
            fmt.Println(i)
        }
    }
}