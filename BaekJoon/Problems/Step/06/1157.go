package main

import (
	"fmt"
    "bufio"
    "os"
	"strings"
)

func main() {

    // Input data (faster)
    var reader = bufio.NewReader(os.Stdin)
    var s string                                // length : < 1,000,000
    fmt.Fscan(reader, &s)

    // Change all letters to upper case
    var length int = len(s)
    // var s2 string = ""                       // string in Golang is immutable
    // for i := 0; i < length; i++ {
    //     s2 += strings.ToUpper(string(s[i]))
    // }
    var s2 string = strings.ToUpper(s)          // can convert just at once

    // Count each alphabet
    var alphabet []int = make([]int, 26)        // [0, 0, ……, 0]
    for j := 0; j < length; j++ {
        alphabet[s2[j]-'A']++
    }

    // Find the max value
    var max int = 0
    var maxIdx int
    for k := 0; k < 26; k++ {
        if alphabet[k] > max {
            max = alphabet[k]
            maxIdx = k
        }
    }

    // Determine if the max value is unique
    var ifUnique int = 0
    for l := 0; l < 26; l++ {
        if alphabet[l] == max {
            ifUnique++
        }
    }

    // test
    // fmt.Println(max, maxIdx, ifUnique)

    // Output
    if ifUnique > 1 {
        fmt.Println("?")                        // not '?'
    } else {
        fmt.Println(string(maxIdx + 'A'))
    }
}