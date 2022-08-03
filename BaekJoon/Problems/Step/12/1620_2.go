package main

import (
	"bufio"
	"fmt"
	"os"
    "strconv"
)

func main() {

	// Make it faster
	var reader = bufio.NewReader(os.Stdin)
	var writer = bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	var n, m int                                             // n, m <= 100,000
	fmt.Scanln(&n, &m)

	// Input n strings with no.
	var pokedexByNo map[int]string = make(map[int]string)
	var temp string
    for i := 1; i <= n; i++ {
		fmt.Fscanln(reader, &temp)
        pokedexByNo[i] = temp
	}

	// Make a map[string]int from map[int]string
	var pokedexByName map[string]int = make(map[string]int)
    for no, name := range pokedexByNo {
        pokedexByName[name] = no
    }

	// Input m questions and get answers
    var idx int
	for i := 1; i <= m; i++ {
		fmt.Fscanln(reader, &temp)
		if temp[0] >= 'A' && temp[0] <= 'z' {
            fmt.Fprintln(writer, pokedexByName[temp])
		} else {
            idx, _ = strconv.Atoi(temp)
			fmt.Fprintln(writer, pokedexByNo[int(idx)])
		}
	}
}