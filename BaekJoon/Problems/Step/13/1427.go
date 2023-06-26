package main
import (
    "fmt"
    "strconv"
)

func main() {

    // Input
    var n string
    fmt.Scanln(&n)
    var nLen = len(n)

    // Convert n to an array
    var arr [10]int
    for i := 0; i < nLen; i++ {
        arr[n[i] - '0']++
    }

    // Output
    for i := 9; i >= 0; i-- {
        for j := 0; j < arr[i]; j++ {
            fmt.Printf(strconv.Itoa(i))
        }
    }
    fmt.Println()
}