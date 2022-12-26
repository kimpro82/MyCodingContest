package main

import "fmt"

func main() {
    var c, n int
    fmt.Scanln(&c)

    for i := 0; i < c; i++ {
        fmt.Scan(&n)

        var score []float32 = make([]float32, n)                            // don't forget make()!
        var sum, average float32
        var aboveAverage int

        // Get sum and average
        sum = 0
        for j := 0; j < n; j++ {
            fmt.Scan(&score[j])
            sum += score[j]
        }
        average = sum / float32(n)

        // test : ok
        // fmt.Println(score, sum, average)

        // Get percentage of students whose grades are above average
        aboveAverage = 0
        for j := 0; j < n; j++ {
            if score[j] > average {
                aboveAverage++
            }
        }

        // test : ok
        // fmt.Println(n, aboveAverage)

        // Output
        fmt.Printf("%.3f%%\n", float32(aboveAverage) / float32(n) * 100)    // not \%, but %%
    }
}