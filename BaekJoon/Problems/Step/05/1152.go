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

    var s string
    s, _ = reader.ReadString('\n')                    // not "\n"

    // Split the string and count
    words := strings.Fields(s)
    // reference ☞ https://pkg.go.dev/strings#Fields

    // Output
    fmt.Println(len(words))
}