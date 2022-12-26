package main
import "fmt"

func main() {
    var input int
    fmt.Scanln(&input)

    var grade string
    if (input >= 90) {
        grade = "A"
    } else if (input >= 80) {
        grade = "B"
    } else if (input >= 70) {
        grade = "C"
    } else if (input >= 60) {
        grade = "D"
    } else {
        grade ="F"
    }

    fmt.Println(grade)
}