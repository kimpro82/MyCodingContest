package main
import (
    "fmt"
    "bufio"
    "os"
    "sort"
    "math"
)

func main() {

    // Make it faster
    var reader = bufio.NewReader(os.Stdin)

    var n int                                   // n <= 500,000
    fmt.Scanln(&n)

    // Input
    var num []int
    for i := 0; i < n; i++ {
        var temp int
        fmt.Fscanln(reader, &temp)
        num = append(num, temp)
    }

    // 1. Mean
    var sum int = 0                             // sum <= 4,000 * 500,000 < int max
    for i := 0; i < n; i++ {
        sum += num[i]
    }
    var mean int = int(math.Round(float64(sum)/float64(n)))

    // 2. Median
    sort.Ints(num)
    var median int = num[(n-1)/2]               // n is aways odd

    // 3. Mode : crazy~~~
    // 3.1 Get a map consists of num and freq.
    var m map[int]int
    m = make(map[int]int)
    for i := 0; i < n; i++ {
        _, exists := m[num[i]]
        if !exists {
            m[num[i]] = 1
        } else {
            m[num[i]]++
        }
    }
    // 3.2 Find the maximum freq.
    var maxFreq int = 0
    for _, v := range m {
        if v > maxFreq {
            maxFreq = v
        }
    }
    // 3.3 Find all the keys with maximum freq.
    var modes []int
    for k, v := range m {
        if v == maxFreq {
            modes = append(modes, k)
        }
    }
    // 3.4 Find the answer
    var mode int
    var length int = len(modes)
    if length > 1 {
        sort.Ints(modes)
        mode = modes[1]
    } else {
        mode = modes[0]
    }

    // 4. Range
    var Range int = num[n-1] - num[0]

    // Output
    fmt.Println(mean)                           // math.Round() requires float64
    fmt.Println(median)
    fmt.Println(mode)
    fmt.Println(Range)
}