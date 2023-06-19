package main
import "fmt"

func main() {

    var n int
    fmt.Scanln(&n)

    // Determine n times
    var count int = 0
    for i := 0; i < n; i++ {

        // Input
        var s string
        fmt.Scanln(&s)
        var sLen int = len(s)
        var sRune = []rune(s)

        // Find if there are seperated same letters
        var alphabet [26]int                        // initialize as {0, ……, 0}
        var isSeperated bool = false
        for j := 0; j < sLen; j++ {
            if alphabet[sRune[j] - 'a'] == 0 {
                alphabet[sRune[j] - 'a']++
            } else {
                if sRune[j] != sRune[j-1] {
                    isSeperated = true
                    break
                }
            }
        }

        // Count
        if (isSeperated == false) {
            count++
        }
    }

    // Output
    fmt.Println(count)
}