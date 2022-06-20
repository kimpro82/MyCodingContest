package main
import (
    "fmt"
    "strings"
)

func main() {

    // Input
    var s string
    var sp2 = [7]string {"c=", "c-", "d-", "lj", "nj", "s=", "z="}
    var sp3 = [1]string {"dz="}
    fmt.Scanln(&s)

    // Count substrings
    var letter string
    var count int = len(s)
    for _, letter = range sp2 {
        count -= strings.Count(s, letter)
    }
    for _, letter = range sp3 {
        count -= strings.Count(s, letter)        // not * 2 because "z-" are already counted
    }
    
    // Output
    fmt.Println(count)
}