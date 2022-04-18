package main
// import "fmt"

func sum(a []int) int {            // int == int64 in 64 bit env.
    var ans int = 0

    for _, el := range a {
        ans += el                  // not a[i] !!!
    }

    return ans
}

// Test
// func main() {
//     a := []int{1, 2, 3, 4, 5}
//     fmt.Println(sum(a))
// }