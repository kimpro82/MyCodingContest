package main
import "fmt"

func main() {

    // Input
    var s string
    fmt.Scanln(&s)

    // Declare an array for alphabet
    var alphabet []int
    for i := 0; i < 26; i++ {
        alphabet = append(alphabet, -1)
    }
    // fmt.Println(alphabet)                     // test : ok

    // Find the location
    for i := 0; i < len(s); i++ {
        // fmt.Print(s[i] - 'a')                 // test : ok

        if alphabet[s[i] - 'a'] == -1 {
            alphabet[s[i] - 'a'] = i
        }
    }

    // Output
    // fmt.Println(alphabet)                     // test : [……]
    for i := 0; i < 25; i++ {                    // a ~ y
        fmt.Print(alphabet[i], " ")
    }
    fmt.Println(alphabet[25])                    // z
}