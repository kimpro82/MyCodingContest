package main

import "fmt"

func main() {

    // Input a string s
	var s string                                       // len(s) <= 1,000
	fmt.Scanln(&s)
    var length int = len(s)

	// Make a map of substrings
	var subStr map[string]int = make(map[string]int)
	var temp string
    for i := 0; i < length; i++ {                      // i : starting index
        for j := i + 1; j <= length ; j++ {            // j : ending index, <= length
            temp = s[i:j]
            subStr[temp] = 1

            // test
            // fmt.Println(i, j, temp)
        }
	}

	// Output
    fmt.Println(len(subStr))
}