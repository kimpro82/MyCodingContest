package main
import (
    "fmt"
    "bufio"
    "os"
    "sort"
)

type member struct {
    no int
    age int
    name string
}

func main() {

    // Make it faster
    var reader = bufio.NewReader(os.Stdin)
    var writer = bufio.NewWriter(os.Stdout)
    defer writer.Flush()

    var n int                                               // n <= 100,000
    fmt.Scanln(&n)
    var members []member

    // Input
    for i := 0; i < n; i++ {
        var temp member
        temp.no = i
        fmt.Fscanln(reader, &temp.age, &temp.name)
        members = append(members, temp)
    }

    // Sort
    sort.SliceStable(members, func(i, j int) bool {
        if members[i].age != members[j].age {
            return members[i].age < members[j].age
        } else {
            return members[i].no < members[j].no            // maintain the existing order
        }
    })

    // Output
    for i := 0; i < n; i++ {
        fmt.Fprintln(writer, members[i].age, members[i].name)
    }
}