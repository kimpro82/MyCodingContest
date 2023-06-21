package main
import (
    "fmt"
    "strconv"
)

func main() {

    // Input a, b as string
    var a, b string
    fmt.Scanln(&a, &b)

    // Reverse a, b
    var aRev, bRev string = "", ""
    for i:= 0; i < 3; i++ {
        aRev += string([]rune(a)[3 - i - 1])    // crazy
        bRev += string([]rune(b)[3 - i - 1])
    }

    // Output
    var aInt, bInt int
    aInt, _ = strconv.Atoi(aRev)
    bInt, _ = strconv.Atoi(bRev)
    if aInt > bInt {                            // a != b
        fmt.Println(aInt)
    } else {
        fmt.Println(bInt)
    }
}