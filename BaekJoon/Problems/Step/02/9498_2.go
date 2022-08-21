package main
import "fmt"

func main() {
    var input int
    fmt.Scanln(&input)

    var tenth int = input / 10;
    var grade string
    switch tenth {
        case 10 :
            fallthrough
        case 9 :
            grade = "A"
        case 8 :
            grade = "B"
        case 7 :
            grade = "C"
        case 6 :
            grade = "D"
        default :
            grade ="F"
    }

    fmt.Println(grade)
}