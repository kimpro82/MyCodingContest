package main
import "fmt"

func main() {
    var n int
    fmt.Scanln(&n)

    var score []float32 = make([]float32, n)
    var max float32 = 0
    for i := 0; i < n; i++ {
        fmt.Scan(&score[i])

        if score[i] > max {
            max = score[i]
        }
    }

    // test
    // fmt.Println(score, max)

    var sum float32 = 0
    for i := 0; i < n; i++ {
        score[i] *= float32(1 / max) * 100
        sum += score[i]

        // test
        // fmt.Println(score, sum)
    }

    fmt.Printf("%.3f\n", sum / float32(n))
}