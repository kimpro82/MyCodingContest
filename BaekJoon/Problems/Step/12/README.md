## BAEKJOON Online Judge

# # 문제 > 단계별로 풀어보기 > 12. 집합과 맵

https://www.acmicpc.net/step/49

(2022.08.03) - `Golang`


## **List**

- [10815. 숫자 카드](#10815숫자-카드)
- [14425. 문자열 집합](#14425문자열-집합)
- [1620. 나는야 포켓몬 마스터 이다솜](#1620나는야-포켓몬-마스터-이다솜)
- [10816. 숫자 카드 2](#10816숫자-카드-2)
- [1764. 듣보잡](#1764듣보잡)
- [1269. 대칭 차집합](#1269대칭-차집합)
- [11478. 서로 다른 부분 문자열의 개수](#11478서로-다른-부분-문자열의-개수)


**※ Note**  

&nbsp;&nbsp; - All the codes of any language for the same problem have basically the same result.  
&nbsp;&nbsp; - Typical headers like the below are basically skipped, but they are noted seperately when theere are any additional line.  
&nbsp;&nbsp;&nbsp;&nbsp; · `Golang` : `package main` `import "fmt"`  


## [10815. 숫자 카드](#list)

> 5  
> 6 3 2 10 -10  
> 8  
> 10 9 -5 2 3 4 5 -10

> 1 0 0 1 1 0 0 1

#### Golang - Trial 1
(2022.07.13)
```go
package main
import (
    "fmt"
    "bufio"                                                 // default size : 4096 byte
    "os"
    // "time"
)
```
```go
func main() {

    // Make it faster
    // var reader = bufio.NewReader(os.Stdin)
    var reader = bufio.NewReaderSize(os.Stdin, 80000004)
    // var writer = bufio.NewWriter(os.Stdout)
    var writer = bufio.NewWriterSize(os.Stdout, 80000004)
    defer writer.Flush()

    var n int                                               // n <= 500,000
    fmt.Scanln(&n)

    // Input
    var card [20000001]bool
    for i := 0; i < n; i++ {
        var temp int
        fmt.Fscan(reader, &temp)
        card[10000000+temp] = true
    }

    // Wait until the reader buffer has been empty
    for reader.Buffered() > 1 {
        // time.Sleep(time.Millisecond)
        // fmt.Println(reader.Buffered())
    }

    var m int                                               // m <= 500,000
    fmt.Scanln(&m)

    // Find if exists and output
    var exist int
    for i := 0; i < m; i++ {
        var temp int
        fmt.Fscan(reader, &temp)
        if card[10000000+temp] == true {
            exist = 1
        } else {
            exist = 0
        }

        if i < m - 1 {
            fmt.Fprint(writer, exist, " ")
        } else {
            fmt.Fprintln(writer, exist)
        }
    }
}
```
> 시간 초과

#### Golang - Trial 2
(2022.07.13)
```go
……
import (
    ……
    "sort"
)
```
```go
func main() {

    // Make it faster
    var reader = bufio.NewReader(os.Stdin)
    var writer = bufio.NewWriter(os.Stdout)
    ……

    ……

    // Input and sort
    var card []int
    var temp int
    for i := 0; i < n; i++ {
        ……
        card = append(card, temp)
    }
    sort.Ints(card)

    ……

    // Find if exists and output
    var idx, ans int
    for i := 0; i < m; i++ {
        ……

        // sort.SearchInts() : return the index to insert x if x is not present (it could be len(a))
        idx = sort.SearchInts(card, temp)
        if temp == card[idx] {
            ans = 1
        } else {
            ans = 0
        }
        
        if i < m - 1 {
            fmt.Fprint(writer, ans, " ")
        } else {
            fmt.Fprintln(writer, ans)
        }
    }
}
```
> 틀렸습니다

#### Golang - Trial 3 (advanced from Trial 1)
(2022.07.15)
```go
……

func main() {

    // Make it faster
    var reader = bufio.NewReaderSize(os.Stdin, 90000000)
    var writer = bufio.NewWriterSize(os.Stdout, 90000000)
    ……

    ……
}
```
> 틀렸습니다


## [14425. 문자열 집합](#list)

> 5 11  
> baekjoononlinejudge  
> startlink  
> ……  
> icerink

> 4

#### Golang - Trial 1
(2022.08.02)
```go
package main
import (
	"bufio"
	"fmt"
	"os"
	"sort"
)
```
```go
func main() {

    // Make it faster
    var reader = bufio.NewReader(os.Stdin)
    var writer = bufio.NewWriter(os.Stdout)
    defer writer.Flush()

    var n, m int                                            // n, m <= 10,000
    fmt.Scanln(&n, &m)

    // Input n strings
    var ns []string
    for i := 0; i < n; i++ {
        var temp string
        fmt.Fscanln(reader, &temp)
        ns = append(ns, temp)
    }

    // Sort n strings
    sort.Strings(ns)

    // Input m strings and count intersaction with n strings
    var ms string
    var count int = 0
    for i := 0; i < m; i++ {
        fmt.Fscanln(reader, &ms)
        if ns[sort.SearchStrings(ns, ms)] == ms {
        // SearchStrings searches for x in a sorted slice of strings and returns the index as specified by Search.
        // The return value is the index to insert x if x is not present (it could be len(a)).
        // The slice must be sorted in ascending order.
        // → inferred as a binary search
            count++
        }
    }

    // Output
    fmt.Fprintln(writer, count)
}
```
> 런타임 에러 (IndexOutOfRange)

#### Golang - Trial 2
(2022.08.02)
```go
……

func main() {

    ……

    // Input m strings and count intersaction with n strings
    ……
    var nsIdx int
    ……
    for i := 0; i < m; i++ {
        ……
        nsIdx = sort.SearchStrings(ns, ms)
        ……
        if nsIdx < n {
        // nsIdx == n means not present
            if ns[nsIdx] == ms {
                count++
            }
        }
    }

    // Output
    fmt.Fprintln(writer, count)
}
```
> 맞았습니다!!


## [1620. 나는야 포켓몬 마스터 이다솜](#list)

Crazy problem explanation ……

> 26 5  
> Bulbasaur  
> Ivysaur  
> ……  
> Kakuna

> Pikachu  
> 26  
> Venusaur  
> 16  
> 14

#### Golang - Trial 1
(2022.08.02)
```go
package main

import (
    "bufio"
    "fmt"
    "os"
    "sort"
    // "reflect"
    "strconv"
)
```
```go
type Pokemon struct {
    name string
    no   int
}
```
```go
func main() {

    // Make it faster
    var reader = bufio.NewReader(os.Stdin)
    var writer = bufio.NewWriter(os.Stdout)
    defer writer.Flush()

    var n, m int                                            // n, m <= 100,000
    fmt.Scanln(&n, &m)

    // Input n strings with no.
    var pokedexByNo []Pokemon
    for i := 1; i <= n; i++ {
        var temp Pokemon
        fmt.Fscanln(reader, &temp.name)
        temp.no = i
        pokedexByNo = append(pokedexByNo, temp)
    }

    // Sort by Name and make its slice
    var pokedexByName []Pokemon
    var pokedexByNameIdx []string
    copy(pokedexByNo, pokedexByName)
    sort.SliceStable(pokedexByName, func(i, j int) bool {
        return pokedexByName[i].name < pokedexByName[j].name
    })
    for _, el := range pokedexByName {
        pokedexByNameIdx = append(pokedexByNameIdx, el.name)
    }

    // Input m questions and get answers
    var temp string
    var idx int
    for i := 1; i <= m; i++ {
        fmt.Fscanln(reader, &temp)
        if temp[0] >= 'A' && temp[0] <= 'z' {
            idx = sort.SearchStrings(pokedexByNameIdx, temp)
            // fmt.Fprintln(writer, reflect.ValueOf(pokedexByName).FieldByIndex([]int {idx, 1}))
            fmt.Fprintln(writer, idx)
        } else {
            idx, _ = strconv.Atoi(temp)
            fmt.Fprintln(writer, pokedexByNo[idx-1].name)
        }
    }
}
```
> Not solved entirely

#### Golang - Trial 2
(2022.08.03)
```go
func main() {

    ……

    // Input n strings with no.
    var pokedexByNo map[int]string = make(map[int]string)
    var temp string
    for i := 1; i <= n; i++ {
        ……
        pokedexByNo[i] = temp
    }

    // Make a map[string]int from map[int]string
    var pokedexByName map[string]int = make(map[string]int)
    for no, name := range pokedexByNo {
        pokedexByName[name] = no
    }

    // Input m questions and get answers
    ……
    for i := 1; i <= m; i++ {
        ……
        if temp[0] >= 'A' && temp[0] <= 'z' {
            fmt.Fprintln(writer, pokedexByName[temp])
        } else {
            ……
            fmt.Fprintln(writer, pokedexByNo[int(idx)])
        }
    }
}
```
> 맞았습니다!!


## [10816. 숫자 카드 2](#list)

> 10  
> 6 3 2 10 10 10 -10 -10 7 3  
> 8  
> 10 9 -5 2 3 4 5 -10

> 3 0 0 1 2 0 0 2

#### Golang
(2022.08.03)
```go
package main

import (
    "bufio"
    "fmt"
    "os"
)
```
```go
func main() {

    // Make it faster
    var reader = bufio.NewReader(os.Stdin)
    var writer = bufio.NewWriter(os.Stdout)
    defer writer.Flush()

    var n int                                                 // n <= 500,000
    fmt.Scanln(&n)

    // Input n map[int]int
    var nm map[int]int = make(map[int]int)
    var temp int
    for i := 0; i < n; i++ {
        fmt.Fscan(reader, &temp)
        nm[temp]++
    }

    var m int                                                 // m <= 500,000
    fmt.Scanln(&m)

    // Input m numbers and get answers
    for i := 0; i < m - 1; i++ {
        fmt.Fscan(reader, &temp)
        fmt.Fprint(writer, nm[temp], " ")
    }
    fmt.Fscan(reader, &temp)
    fmt.Fprint(writer, nm[temp])                              // crazy
    fmt.Fprintln(writer)
}
```
> 출력 초과

## [1764. 듣보잡](#list)

> 3 4  
> ohhenrie  
> charlie  
> ……  
> clinton

> 2  
> baesangwook  
> ohhenrie

#### Golang
(2022.08.03)
```go
package main

import (
    "bufio"
    "fmt"
    "os"
    "sort"
)
```
```go
func main() {

    // Make it faster
    var reader = bufio.NewReader(os.Stdin)
    var writer = bufio.NewWriter(os.Stdout)
    defer writer.Flush()

    var n, m int                                             // n, m <= 500,000
    fmt.Scanln(&n, &m)

    // Input a map[string]int
    var nameMap map[string]int = make(map[string]int)
    var temp string
    for i := 0; i < n + m; i++ {
        fmt.Fscanln(reader, &temp)
        nameMap[temp]++
    }

    // Make []string from nm with value 2 and sort it
    var nameSorted []string
    for k, v := range nameMap {
        if v > 1 {
            nameSorted = append(nameSorted, k)
        }
    }
    sort.Strings(nameSorted)

    // Input m questions and get answers
    var length int = len(nameSorted)
    fmt.Fprintln(writer, length)
    for _, name := range nameSorted {
        fmt.Fprintln(writer, name)
    }
}
```
> 맞았습니다!!


## [1269. 대칭 차집합](#list)

> 3 5  
> 1 2 4  
> 2 3 4 5 6

> 4

#### Golang
(2022.08.03)
```go
package main

import (
    "bufio"
    "fmt"
    "os"
)
```
```go
func main() {

    // Make it faster
    var reader = bufio.NewReader(os.Stdin)
    var writer = bufio.NewWriter(os.Stdout)
    defer writer.Flush()

    var n, m int                                             // n, m <= 200,000
    fmt.Scanln(&n, &m)

    // Input n + m integers into a map[int]int
    var nm map[int]int = make(map[int]int)
    var temp int
    for i := 0; i < n + m; i++ {
        fmt.Fscan(reader, &temp)
        nm[temp]++
    }

    // Count the difference set
    var count int = 0
    for _, v := range nm {
        if v == 1 {
            count++
        }
    }

    // Output
    fmt.Fprintln(writer, count)
}
```
> 맞았습니다!!


## [11478. 서로 다른 부분 문자열의 개수](#list)

> ababc

> 12

#### Golang
(2022.08.03)
```go
func main() {

    // Input a string s
    var s string                                            // len(s) <= 1,000
    fmt.Scanln(&s)
    var length int = len(s)

    // Make a map of substrings
    var subStr map[string]int = make(map[string]int)
    var temp string
    for i := 0; i < length; i++ {                           // i : starting index
        for j := i + 1; j <= length ; j++ {                 // j : ending index, <= length
            temp = s[i:j]
            subStr[temp] = 1

            // test
            // fmt.Println(i, j, temp)
        }
    }

    // Output
    fmt.Println(len(subStr))
}
```
> 맞았습니다!!