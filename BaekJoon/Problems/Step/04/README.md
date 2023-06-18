## [BAEKJOON Online Judge](../../../../README.md#baekjoon-online-judge)

# 문제 > 단계별로 풀어보기 > 4. 1차원 배열

(2021.06.14, 2023.06.18) - `C++`  
(2022.02.03) - `Bash`  
(2022.04.12) - `Golang`

https://www.acmicpc.net/step/6  


## **List**

- [10807. 개수 세기](#10807-개수-세기) *(new)*
- [10871. X보다 작은 수](#10871-x보다-작은-수)
- [10818. 최소, 최대](#10818-최소-최대)
- [2562. 최댓값](#2562-최댓값)
- [10810. 공 넣기](#10810-공-넣기) *(new)*
- [10813. 공 바꾸기](#10813-공-바꾸기) *(new)*
- [5597. 未提出者は誰だ (과제 안 내신 분..?)](#5597-未提出者は誰だ-과제-안-내신-분) *(new)*
- [3052. MODULO](#3052-modulo)
- [10811. 바구니 뒤집기](#10811-바구니-뒤집기) *(new)*
- [1546. 평균](#1546-평균)

#### (Depreciated)
- [2577. 숫자의 개수](#2577-숫자의-개수)
- [8958. Score](#8958-score)
- [4344. Above Average](#4344-above-average)


**※ Note**  

&nbsp;&nbsp; - All the codes of any language for the same problem have basically the same result.  
&nbsp;&nbsp; - `Bash` : skipped the first line; `#!/bin/bash`  
&nbsp;&nbsp; - `C++`* : skipped `main()` function's brace(`{}`) and its outside including two header lines; `#include <iostream>` `using namespace std;`  
&nbsp;&nbsp; - `Golang`* : skipped `main()` function's brace(`{}`) and its outside including two header lines; `package main` `import "fmt"`  
&nbsp;&nbsp; * When any additional header is used, the header block is also noted seperately.


## [10807. 개수 세기](#list)

(2023.06.18)

> 11  
> 1 4 1 2 4 2 4 2 3 4 4  
> 2

> 3

#### C++
```cpp
#include <iostream>
#include <vector>

using namespace std;

#define endl '\n'
```
```cpp
// Declare
int n, v, temp;
vector<int> arr;

// Input
std::cin >> n;
for (int i = 0; i < n; i++)
{
    std::cin >> temp;
    arr.push_back(temp);
}
std::cin >> v;

// Count
int count = 0;
for (int i = 0; i < n; i++) if (arr[i] == v) count++;

// Output
std::cout << count << endl;

return 0;
```


## [10871. X보다 작은 수](#list)

(2021.05.25)

> 10 5  
> 1 10 4 9 2 3 8 5 7 6

> 1 4 2 3

#### Bash
```bash
read n x
read list

for num in $list
do
    if [ $num -lt $x ]; then
        echo -n "$num "
    fi
done

echo ' '

# read
```

#### C++
```cpp
int n, x;
int arr[10000];                 // .exe file stops when int arr[n], although compilation succeeded
cin >> n >> x;

for (int i = 0; i < n; i++)
{
    cin >> arr[i];
    if (arr[i] < x)
    {
        cout << arr[i] << ' ';
    }
}
cout << '\n';

return 0;
```


#### Golang
```go
var n, x int
fmt.Scanln(&n, &x)

for i := 0; i < n; i++ {
    var num int
    fmt.Scanf("%d", &num)
    if num < x {
        fmt.Printf("%d ", num)
    }
}
// fmt.Println("\b")            // causes wrong?
```


## [10818. 최소, 최대](#list)

> 5  
> 20 10 35 30 7

> 7 35

#### Bash
```bash
# ulimit -q 64
# -d : The maximum size of a process’s data segment (kbytes)
# -p : The pipe buffer size
# Error message > ulimit: pipe size: cannot modify limit: Invalid argument
# -q : The maximum number of bytes in POSIX message queues
# Error message > -q: invalid option
```
```bash
read n

# Set min, max
let "min = 10 ** 6"
let "max = -(10 ** 6)"

# Read data as an array
read -a arr

# Find the min and max values
for i in ${arr[@]}
do
    if [ $i -lt $min ]; then
        let "min = i"
    fi

    if [ $i -gt $max ]; then
        let "max = i"
    fi
done

# Output
echo $min $max
```
> 메모리 초과

#### C++ - Trial 1
```cpp
#include <iostream>
#include <cmath>    // for using min() & max(), but I really hate it
```
```cpp
int t;
cin >> t;

int arr[t];
int minValue = 1000000, maxValue = -1000000, temp;

for (int i = 0; i < t; i++)
{
    cin >> temp;
    arr[i] = temp;
    maxValue = max(maxValue, arr[i]);
    minValue = min(minValue, arr[i]);        
}

cout << minValue << " " << maxValue << endl;

return 0;
```

#### C++ - Trial 2
```cpp
// I really don't want to use for loop with math.max(), math.min().  
// But, consequantially, it was a kind of the lesser evil.
```
```cpp
#include <iostream>
// #include <cstdarg>   // for using va_list, but it can't adopt minmax()
// #include <utility>   // likewise, for using pair<> related with minmax()
#include <vector>       // need to understand by comparing with other similar containers
#include <algorithm>    // for using min_element() and max_element()
```
```cpp
int t;
cin >> t;

vector<int> vec;            // not arr[], because vector<> has variable size
int temp;
for (int i = 0; i < t; i++)
{
    cin >> temp;
    vec.push_back(temp);
}

// pair <int, int> answer;  // for getting output from minmax()
// minmax() requires list<>, not va_list
int minValue = *min_element(vec.begin(), vec.end());    
int maxValue = *max_element(vec.begin(), vec.end());
cout << minValue << " " << maxValue << endl;    // inefficient, crazy

return 0;
```

#### Golang - Trial 1
```golang
var n int
fmt.Scanln(&n)

var arr []int = make([]int, n)

var max int = -1000000
var min int = 1000000
for i := 0; i < n; i++ {
    fmt.Scanf("%d", &arr[i])
    
    if arr[i] > max {
        max = arr[i]
    }
    if arr[i] < min {
        min = arr[i]
    }
}

fmt.Println(min, max)
```
> 시간 초과

#### Golang - Trial 2
```golang
import (
    "fmt"
    "bufio"
    "os"
)
```
```golang
var reader = bufio.NewReader(os.Stdin)
var writer = bufio.NewWriter(os.Stdout)
defer writer.Flush()

var n int
fmt.Scanln(&n)

var arr []int = make([]int, n)

var max int = -1000000
var min int = 1000000
for i := 0; i < n; i++ {
    fmt.Fscan(reader, &arr[i])

    if arr[i] > max {
        max = arr[i]
    }
    if arr[i] < min {
        min = arr[i]
    }
}

fmt.Println(min, max)
```

#### Golang - Trial 3
```golang
import (
    "fmt"
    "bufio"
    "os"
    "sort"
)
```
```golang
var reader = bufio.NewReader(os.Stdin)
var writer = bufio.NewWriter(os.Stdout)
defer writer.Flush()

var n int
fmt.Scanln(&n)

var arr []int = make([]int, n)

for i := 0; i < n; i++ {
    fmt.Fscan(reader, &arr[i])
}

// using sort.Sort()
sort.Sort(sort.IntSlice(arr))
fmt.Println(arr[0], arr[n - 1])
```


## [2562. 최댓값](#list)

> 3  
> 29  
> 38  
> 12  
> 57  
> 74  
> 40  
> 85  
> 61

> 85  
> 8

#### Bash
```bash
# Set max
let "max = 0"

# Read data as an array
for i in {0..8}                             # Its length is fixed as 9.
do
    read temp
    let "arr[i] = temp"
done

:<<'Comment'
    It's not necessary to use an array,
    but this is the chapter to learn array
Comment

# Find the max value
for i in {0..8} 
do
    if [ ${arr[$i]} -gt $max ]; then
        let "max = arr[i]"
        let "order = i + 1"
    fi

    # test
    # echo $i ${arr[$i]} $max $order
done

# Output
echo -e "${max}\n${order}"
```

#### C++
```cpp
const int length = 9;       // the length of arr[] is fixed as 9
int arr[length];
int maxValue = 0, temp, loc = 0;

for (int i = 0; i < length; i++)
{
    cin >> temp;
    arr[i] = temp;

    if (arr[i] > maxValue)  // all elements of arr[] are different from each other
    {
        maxValue = arr[i];
        loc = i + 1;
    }
}

cout << maxValue << "\n" << loc << endl;

return 0;
```

#### Golang
```golang
var n int
var max int = 0
var maxIdx int

for i := 0; i < 9; i++ {
    fmt.Scanf("%d", &n)
    
    if n > max {
        max = n
        maxIdx = i
    }
}

fmt.Println(max, maxIdx + 1)
```


## [10810. 공 넣기](#list)

(2023.06.18)

> 5 4  
> 1 2 3  
> 3 4 4  
> 1 4 1  
> 2 2 2

> 1 2 1 1 0

#### C++
```cpp
#include <iostream>
#include <vector>

#define endl '\n'

using namespace std;
```
```cpp
// Declare
int n, m;
int i, j, k;

// Input
std::cin >> n >> m;
vector<int> arr(n + 1, 0);
for (int a = 0; a < m; a++)
{
    std::cin >> i >> j >> k;
    for (int b = i; b <= j; b++) arr[b] = k;
}

// Output
for (int a = 1; a < n + 1; a++) std::cout << arr[a] << ' ';
std::cout << endl;

return 0;
```


## [10813. 공 바꾸기](#list)

(2023.06.18)

> 5 4  
> 1 2  
> 3 4  
> 1 4  
> 2 2

> 3 1 4 2 5

#### C++
```cpp
#include <iostream>
#include <vector>

#define endl '\n'

using namespace std;
```
```cpp
// Declare
int n, m;
int i, j;

// Input & Swap
std::cin >> n >> m;
vector<int> arr(n + 1);
for (int a = 0; a < n + 1; a++) arr[a] = a;
for (int a = 0; a < m; a++)
{
    std::cin >> i >> j;
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

// Output
for (int a = 1; a < n + 1; a++) std::cout << arr[a] << ' ';
std::cout << endl;

return 0;
```


## [5597. 未提出者は誰だ (과제 안 내신 분..?)](#list)

(2023.06.18)

> 3  
> 1  
> 4  
> ……  
> 30

> 2  
> 8

#### C++
```cpp
#include <iostream>
#include <vector>

#define endl '\n'

using namespace std;
```
```cpp
// Declare & Input
vector<int> arr(31, 0);
int n;
for (int i = 0; i < 28; i++)
{
    std::cin >> n;
    arr[n] = 1;
}

// Output
for (int i = 1; i < 31; i++) if (arr[i] == 0) std::cout << i << endl;

return 0;
```


## [3052. MODULO](#list)

> 39  
> 40  
> 41  
> 42  
> 43  
> 44  
> 82  
> 83  
> 84  
> 85

> 6

#### Bash
```bash
# Input data
for i in {0..9}         # the size 10 is fixed
do
    read n
    let "modulo = n % 42"
    let "arr[$modulo]++"
done

:<<"Comment"
    The array in bash doesn't need to have strictly continuous indices.
    So we can use array like <set> by this feature 
Comment

# Output
echo ${#arr[@]}
```

#### C++
```cpp
// modulo : 나머지
// distinct number : 서로 다른 숫자 ≒ 중복되지 않는 숫자
```
```cpp
#include <iostream>
#include <set>
```
```cpp
const int length = 10;
int input[length];
set<int> modulo;

for (int i = 0; i < length; i++)
{
    cin >> input[i];
    modulo.insert(input[i] % 42);
}

cout << modulo.size() << endl;

return 0;
```

#### Golang
```golang
var n, mod int
var modulo map[int]int
modulo = make(map[int]int)

for i := 0; i < 10; i++ {
    fmt.Scanln(&n)

    mod = n % 42
    _, exists := modulo[mod]
    if !exists {
        modulo[mod] = 1
    } else {
        modulo[mod]++            // not necessary but I dream better code
    }
}

// test
// for j := 0; j < 42; j++ {
//     val, exists := modulo[j]
//     if exists {
//         fmt.Println(j, val)
//     }
// }

fmt.Println(len(modulo))
```


## [10811. 바구니 뒤집기](#list)

(2023.06.18)

> 5 4  
> 1 2  
> 3 4  
> 1 4  
> 2 2

> 3 4 1 2 5

#### C++
```cpp
#include <iostream>
#include <vector>
#include <algorithm>

// #define test
#define endl '\n'

using namespace std;
```
```cpp
// Declare
int n, m;
int i, j;

// Input & Reverse partially
std::cin >> n >> m;
vector<int> arr(n + 1);
for (int a = 0; a < n + 1; a++) arr[a] = a;
for (int b = 0; b < m; b++)
{
    std::cin >> i >> j;
    std::reverse(arr.begin() + i, arr.begin() + j + 1);

    // test
    #ifdef test
        for (int a = 1; a < n + 1; a++) std::cout << arr[a] << ' ';
        std::cout << endl;
    #endif
}

// Output
for (int a = 1; a < n + 1; a++) std::cout << arr[a] << ' ';
std::cout << endl;

return 0;
```


## [1546. 평균](#list)

> 3  
> 40 80 60

> 75

#### Bash
```bash
# Input data
read n
read -a arr

# Find the max score
let "max = 0"
for i in ${arr[@]}
do
    if [ $i -gt $max ]; then
        let "max = i"
    fi
done
# echo $max                                     # test

# Operation to fake scores
let "sum = 0"
for ((i = 0; i < n; i++))
do
    let "sum += (arr[i] * 100 * 1000 / max)"    # don't forget "* 1000"
done
# echo $sum                                     # test

# Output
let "average = sum / n"
printf "%.2f\n" $((average))e-3                 # MAGIC!!
```

#### C++
```cpp
int t;
cin >> t;

double score[t], maxValue = 0, sum = 0;
for (int i = 0; i < t; i++)
{
    cin >> score[i];
    maxValue = max(maxValue, score[i]);
}

for (int j = 0; j < t; j++)
{
    score[j] *= (1 / maxValue) * 100;
    sum += score[j];
}

cout << sum / t << endl;

return 0;
```

#### Golang
```golang
var n int
fmt.Scanln(&n)

var score []float32 = make([]float32, n)
var max float32 = 0
for i := 0; i < n; i++ {
    fmt.Scan(&score[i])

    if score[i] > max {
        max = score[i]
    }
}

// test
// fmt.Println(score, max)

var sum float32 = 0
for i := 0; i < n; i++ {
    score[i] *= float32(1 / max) * 100
    sum += score[i]

    // test
    // fmt.Println(score, sum)
}

fmt.Printf("%.3f\n", sum / float32(n))
```


## [2577. 숫자의 개수](#list)

> 150  
> 266  
> 427

> 3 1 0 2 0 0 0 2 0 0 (vertically)

#### Bash
```bash
# Input data
read a
read b
read c

# Get the product and its length as a string
let "prod = a * b * c"
let "len = ${#prod}"
# echo $prod $len                               # test

# Initialize arr
for i in {0..9}
do
    let "arr[$i] = 0"
done

:<<"Comment"
    It's not neccesary to initialize an array basically in Bash,
    but empty indices should have their value '0' for solving this problem.
Comment

# Operation to count each digit
for ((i = 0; i < len; i++))
do
    let "arr[${prod:i:1}] += 1"

    # test
    # echo $i ${prod:i:1} ${arr[${prod:i:1}]}
done

# Output
for i in {0..9}
do
    echo ${arr[$i]}
done
```

#### C++
```cpp
int a, b, c;                        // 100 <= a, b, c < 1000
cin >> a >> b >> c;

string prod = to_string(a * b * c); 
int length = sizeof(prod);
int arr[length] = {};               // initialize arr[] as {0, 0, ……, 0}

for (int i = 0; i < length; i++)
{
    arr[prod[i]-'0']++;             // I did this amazing code! 
}

for (int j = 0; j < 10; j++)
{
    cout << arr[j] << endl;
}

return 0;
```

#### Golang
```golang
import (
    "fmt"
    "strconv"
)
```
```golang
var a, b, c int
fmt.Scanln(&a)
fmt.Scanln(&b)
fmt.Scanln(&c)

var prod string = strconv.Itoa(a * b * c)
var length int = len(prod)

var arr [10]int
for i := 0; i < length; i++ {
    arr[prod[i] - '0']++
}

for j := 0; j < 10; j++ {
    fmt.Println(arr[j])
}
```


## [8958. Score](#list)

> 5  
> OOXXOXXOOO  
> OOXXOOXXOO  
> OXOXOXOXOXOXOX  
> OOOOOOOOOO  
> OOOOXOOOOXOOOOX  

> 10  
> ……

#### Bash
```bash
read t

# Operation to grade and output
for ((i = 0; i < t; i++))
do
    read ox

    let "len = ${#ox}"
    let "score = 0"
    let "combo = 0"

    for ((j = 0; j < len; j++))
    do
        if [ "${ox:j:1}" = "O" ]; then
            let "combo += 1"
            let "score += combo"
        else
            let "combo = 0"
        fi

        # test
        # echo $i $j ${ox:j:1} $combo $score
    done

    echo $score
done
```

#### C++
```cpp
int t;
cin >> t;

string input[t];

for (int i = 0; i < t; i++)
{
    cin >> input[i];

    int score = 0, combo = 0;
    for (int j = 0; j < input[i].length(); j++)
    // sizeof() : get memory size of array, not length that I mean
    {
        if (input[i][j] == 'O')
        {
            combo += 1;
            score += combo;
        } else
        {
            combo = 0;
        }

        // test
        cout << "(" << i << ", " << j << ") " 
            << input[i][j] << " " << combo << " " << score << endl;
    }

    cout << score << endl;

}

return 0;
```

#### Golang
```golang
var n, score, combo, length int
var ox string
fmt.Scanln(&n)

for i := 0; i < n; i++ {
    score = 0
    combo = 0

    fmt.Scan(&ox)
    length = len(ox)

    for j := 0; j < length; j++ {
        if (ox[j] == 'O') {
            combo += 1
            score += combo
        } else {
            combo = 0
        }
    }

    fmt.Println(score)
}
```


## [4344. Above Average](#list)

> 5  
> 5 50 50 70 80 100  
> 7 100 95 90 80 70 60 50  
> 3 70 90 80  
> 3 70 90 81  
> 9 100 99 98 97 96 95 94 93 91

> 40.000%  
> 57.143%  
> ……

#### Bash
```bash
read c

# Operation to grade and output
for ((i = 0; i < c; i++))
do
    # Read an array
    read -a arr

    let "len = arr[0]"
    let "sum = 0"

    # Get the array's sum and average
    for ((j = 1; j < len + 1; j++))
    do
        let "sum += ${arr[j]}"
    done
    let "average = sum * 10 / len"                      # don't forget sum * 10

    # test
    # echo $i $sum $len $average

    # Count freshmen over the average score
    let "count = 0"
    for ((j = 1; j < len + 1; j++))
    do
        let "score = ${arr[j]} * 10"
        if [ $score -gt $average ]; then
            let "count += 1"
        fi
    done

    # Output
    printf "%.3f%%\n" $((count * 10 ** 8 / len))e-6
    # * 10 ** 6 & e-4 : fail (maybe concerned with rounding ……)
done
```

#### C++
```cpp
int c;
cin >> c;

for (int i = 0; i < c; i++)
{
    int n;
    cin >> n;

    // get sum and average
    int scores[n], sum = 0, average;
    for (int j = 0; j < n; j++)
    {
        cin >> scores[j];
        sum += scores[j];
    }
    average = sum / n;

    // get percentage of students whose grade is above average
    double aboveAverage = 0;
    for (int k = 0; k < n; k++)
    {
        if (scores[k] > average)
        {
            aboveAverage += 1;
        }
    }

    // test
    cout << n << " " << sum << " " << average << " " << aboveAverage << endl;

    // ouput
    double aboveAverageRatio = (double) (aboveAverage / n) * 100;
    cout << fixed;      // output 40.000, not 40
    cout.precision(3);  // 3 : 3 ciphers under decimal point
    cout << aboveAverageRatio << '%' << endl;
}

return 0;
```

#### Golang
```golang
var c, n int
fmt.Scanln(&c)

for i := 0; i < c; i++ {
    fmt.Scan(&n)

    var score []float32 = make([]float32, n)                            // don't forget make()!
    var sum, average float32
    var aboveAverage int

    // Get sum and average
    sum = 0
    for j := 0; j < n; j++ {
        fmt.Scan(&score[j])
        sum += score[j]
    }
    average = sum / float32(n)

    // test : ok
    // fmt.Println(score, sum, average)

    // Get percentage of students whose grades are above average
    aboveAverage = 0
    for j := 0; j < n; j++ {
        if score[j] > average {
            aboveAverage++
        }
    }

    // test : ok
    // fmt.Println(n, aboveAverage)

    // Output
    fmt.Printf("%.3f%%\n", float32(aboveAverage) / float32(n) * 100)    // not \%, but %%
}
```