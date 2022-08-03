package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
    // "reflect"
    "strconv"
)

type Pokemon struct {
	name string
	no   int
}

func main() {

	// Make it faster
	var reader = bufio.NewReader(os.Stdin)
	var writer = bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	var n, m int                                             // n, m <= 100,000
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
