package main
import (
    "fmt"
    "bufio"
    "os"
    "sort"
)

type point struct {
    x int
    y int
}

func main() {

    // Make it faster
    var reader = bufio.NewReader(os.Stdin)
    var writer = bufio.NewWriter(os.Stdout)
    defer writer.Flush()

    var n int                                               // n <= 100,000
    fmt.Scanln(&n)
    var points []point

    // Input
    for i := 0; i < n; i++ {
        var temp point
        fmt.Fscanln(reader, &temp.x, &temp.y)
        points = append(points, temp)
    }

    // Sort
    sort.SliceStable(points, func(i, j int) bool {
        if points[i].y == points[j].y {
            return points[i].x < points[j].x
        } else {
            return points[i].y < points[j].y
        }
    })

    // Output
    for i := 0; i < n; i++ {
        fmt.Fprintln(writer, points[i].x, points[i].y)
    }
}