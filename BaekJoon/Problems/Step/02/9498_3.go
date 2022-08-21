package main
import "fmt"

func main() {
    var input int
    fmt.Scanln(&input)

    grade := [11]string{"F", "F", "F", "F", "F", "F", "D", "C", "B", "A", "A"}
    fmt.Println(grade[input / 10])
}