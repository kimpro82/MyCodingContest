package main
import "fmt"

func main() {
    var n, mod int
    var modulo map[int]int
    modulo = make(map[int]int)
    
    for i := 0; i < 10; i++ {
        fmt.Scanln(&n)

        mod = n % 42
        _, exists := modulo[mod]
        if !exists {
            modulo[mod] = 1
        } else {
            modulo[mod]++            // not necessary but I dream better code
        }
    }

    // test
    // for j := 0; j < 42; j++ {
    //     val, exists := modulo[j]
    //     if exists {
    //         fmt.Println(j, val)
    //     }
    // }

    fmt.Println(len(modulo))
}