package main
import "fmt"

func main() {

    // Input string s
    var s string
    fmt.Scanln(&s)
    var sRune []rune = []rune(s)

    // Operate
    var sLen int = len(s)
    var dial, time, sum int = 0, 0, 0
    for i := 0; i < sLen; i++ {
        if sRune[i] <= 'R' {
            dial = int(sRune[i] - 'A') / 3 + 2
        } else if sRune[i] >= 'S' && sRune[i] <= 'X' {
            dial = int(sRune[i] - 'A' - 1) / 3 + 2
        } else {
            dial = int(sRune[i] - 'A' - 2) / 3 + 2
        }

        time = dial + 1
        sum += time
    }

    // Output
    fmt.Println(sum)
}