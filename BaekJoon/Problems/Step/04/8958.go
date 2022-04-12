package main
import "fmt"

func main() {
    var n, score, combo, length int
    var ox string
    fmt.Scanln(&n)

    for i := 0; i < n; i++ {
        score = 0
        combo = 0

        fmt.Scan(&ox)
        length = len(ox)

        for j := 0; j < length; j++ {
            if (ox[j] == 'O') {
                combo += 1
                score += combo
            } else {
                combo = 0
            }
        }

        fmt.Println(score)
    }
}