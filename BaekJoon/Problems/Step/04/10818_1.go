package main
import "fmt"

func main() {
    var n int
    fmt.Scanln(&n)

    var arr []int = make([]int, n)
    
    var max int = -1000000
    var min int = 1000000
    for i := 0; i < n; i++ {
        fmt.Scanf("%d", &arr[i])
        
        if arr[i] > max {
            max = arr[i]
        }
        if arr[i] < min {
            min = arr[i]
        }
    }

    fmt.Println(min, max)
}