## [BAEKJOON Online Judge](../../../../README.md#baekjoon-online-judge)

# 문제 > 단계별로 풀어보기 > 3. 반복문 - 1) for문

https://www.acmicpc.net/step/3

(2021.05.25) - `C++`  
(2022.01.31) - `Bash`  
(2022.03.18) - `Golang`  


### **List**

- [2739. 구구단](#2739-구구단)
- [10950. A+B - 3](#10950-ab---3)
- [8393. Sum](#8393-sum)
- [25304. 영수증](#25304-영수증) *(new)*
- [25314. 코딩은 체육과목 입니다](#25314-코딩은-체육과목-입니다) *(new)*
- [15552. 빠른 A+B](#15552-빠른-ab)
- [11021. A+B - 7](#11021-ab---7)
- [11022. A+B - 8](#11022-ab---8)
- [2438. 별 찍기 - 1](#2438-별-찍기---1)
- [2439. 별 찍기 - 2](#2439-별-찍기---2)

#### (Depreciated)
- [2741. N 찍기](#2741-n-찍기)
- [2742. 기찍 N](#2742-기찍-n)


**※ Note**  

&nbsp;&nbsp; - All the codes of any language for the same problem have basically the same result.  
&nbsp;&nbsp; - Typical headers like the below are basically skipped, but they are noted seperately when there are any additional line.  
&nbsp;&nbsp;&nbsp;&nbsp; · *Bash* : `#!/bin/bash`  
&nbsp;&nbsp;&nbsp;&nbsp; · *C++* : `#include <iostream>` `#define endl '\n';` `using namespace std;` `int main() {}`  
&nbsp;&nbsp;&nbsp;&nbsp; · *Golang* : `package main` `import "fmt"` `func main() {}`  
&nbsp;&nbsp;&nbsp;&nbsp; · *Rust* : `use std::io;` `fn main() {}`  


## [2739. 구구단](#list)

> 2

> 2 * 1 = 2  
> 2 * 2 = 4  
> ……  
> 2 * 9 = 18

#### Bash (2022.01.31)
```bash
read n

for i in {1..9}
do
    echo $n "*" $i "=" $((n * i))
done

# read
```

#### C++ (2021.05.25)
```cpp
int a;
cin >> a;

for (int i = 1; i <= 9; i++)
{
    cout << a << " * " << i << " = " << a * i << endl;
}

return 0;
```

#### Golang (2022.03.16)
```go
var n int
fmt.Scanln(&n)

for i := 1; i <= 9; i++ {
    fmt.Println(n, "*", i, "=", n * i)
}
```

#### Rust (2023.12.23)
```rust
let mut input = String::new();
io::stdin().read_line(&mut input).unwrap();

let n: i32 = input.trim().parse().unwrap();

for i in 1..10 { println!("{} * {} = {}", n, i, n * i); };
// ; can be skipped
```


## [10950. A+B - 3](#list)

> 5  
> 1 1  
> 2 3  
> 3 4  
> 9 8  
> 5 2

> 2 5 7 17 7 (vertically)

#### Bash (2022.01.31)
```bash
read t

for ((i = 0; i < t; i++))
# for i in {1..$t}          # something wrong
do
    read a b
    echo $((a + b))
done

# read
```

#### C++ (2021.05.25)
```cpp
int t, a, b;
cin >> t;

for (int i = 1; i <= t; i++)
{
    cin >> a >> b;
    cout << a + b << endl;
}

return 0;
```

#### Golang (2022.03.16)
```go
var t int
fmt.Scanln(&t)

for i := 0; i < t; i++ {
    var a, b int
    fmt.Scanln(&a, &b)

    fmt.Println(a + b)
}
```

#### Rust (2023.12.23)
```rust
let mut input1 = String::new();
io::stdin().read_line(&mut input1).unwrap();
let t: i32 = input1.trim().parse().unwrap();

for _i in 0..t
// `_i`, not `i` when intentional
{
    let mut input2 = String::new();
    io::stdin().read_line(&mut input2).unwrap();
    let numbers: Vec<i32> = input2
        .split_whitespace()
        .map(|s| s.parse::<i32>().unwrap())
        .collect();

    let a = numbers[0];
    let b = numbers[1];

    println!("{}", a + b);
}
```


## [8393. Sum](#list)

> 10

> 55

#### Bash (2022.01.31)
```bash
read n
let "sum = 0"

for ((i = 1; i <= n; i++))
do
    let "sum += i"
done

echo $sum

# read
```

#### C++ (2021.05.25)
```cpp
int a;
cin >> a;

int sum = 0;
for (int i = 1; i <= a; i++)
{
    sum += i;
}
cout << sum << endl;

return 0;
```

#### Golang - trial 1 (2022.03.16)
```go
var n int
fmt.Scanln(&n)

var sum int = 0
for i := 1; i <= n; i++ {
    sum += i
}

fmt.Println(sum)
```

#### Golang - trial 2 (2022.03.16)
```go
var n int
fmt.Scanln(&n)

var sum = n * (n + 1) / 2

fmt.Println(sum)
```
> expected to be faster, but not so different from ~~the~~ trial 1  
> (※ my wife claimed "trial 1" doesn't require "the")

#### Rust (2023.12.23)
```rust
let mut input = String::new();
io::stdin().read_line(&mut input).unwrap();

let n: i32 = input.trim().parse().unwrap();

println!("{}", n * (n + 1) / 2);
```


## [15552. 빠른 A+B](#list)

> 5  
> 1 1  
> 12 34  
> 5 500  
> 40 60  
> 1000 1000

> 2 46 505 100 2000 (vertically)

#### Bash - trial 1 (2022.01.31)
```bash
read t

for ((i = 0; i < t; i++))
do
    read a b
    echo $((a + b))
done

# read
```
> 시간 초과

#### Bash - trial 2 (2022.01.31)
```bash
# t test cases
read t

# Initialize file.txt that has 0 bytes
cat /dev/null > file.txt                # /dev/null : null device

# Operation
for ((i = 0; i < t; i++))
do
    read a b
    echo $((a + b)) >> file.txt
done

# Standard output through a file
awk '{ print }' ./file.txt

# read
```
> 런타임 에러

#### C++ (2021.05.25)
```cpp
// make cin/cout faster
cin.tie(NULL);
ios_base::sync_with_stdio(false);

int t, a, b;
cin >> t;

for (int i = 1; i <= t; i++)
{
    cin >> a >> b;
    cout << a + b << '\n';          // \n is faster than endl
}

return 0;
```

#### Golang - trial 1 (2022.03.16)
```go
var t int
fmt.Scanln(&t)

for i := 0; i < t; i++ {
    var a, b int
    fmt.Scanln(&a, &b)
    fmt.Println(a + b)
}
```
> Timeout

#### Golang - trial 2 (2022.03.18)
```go
import (
    "fmt"
    "bufio"
    "os"
)
```
```go
var reader = bufio.NewReader(os.Stdin)
var writer = bufio.NewWriter(os.Stdout)
defer writer.Flush()

var t int
fmt.Scanln(&t)

var a, b int
for i := 0; i < t; i++ {
    fmt.Fscan(reader, &a, &b)
    fmt.Fprintln(writer, a + b)
}
```

#### Rust (2023.12.24)
```rust
let mut input = String::new();

io::stdin().read_to_string(&mut input).unwrap();
let mut input = input
    .split_ascii_whitespace()
    .flat_map(str::parse::<i32>);

let t = input.next().unwrap();
let mut output = String::new();
for _ in 0..t
{
    let a: i32 = input.next().unwrap();
    let b: i32 = input.next().unwrap();

    writeln!(output, "{}", a + b).unwrap();
}
print!("{}", output);
```


## [25304. 영수증](#list)

(2023.06.17)

> 260000  
> 4  
> 20000 5  
> 30000 2  
> 10000 6  
> 5000 8

> Yes

#### C++ (2023.06.17)
```cpp
using ll = long long;
```
```cpp
ll X;
int N;
std::cin >> X >> N;

ll sum = 0;
int a, b;
for (int n = 0; n < N; n++)
{
    std::cin >> a >> b;
    sum += a * b;
}

if (X == sum) std::cout << "Yes" << '\n';
else std::cout << "No" << '\n';

return 0;
```

#### Rust (2023.12.23)
```rust
let mut input1 = String::new();
let mut input2 = String::new();

io::stdin().read_line(&mut input1).unwrap();
io::stdin().read_line(&mut input2).unwrap();

let x: i32 = input1.trim().parse().unwrap();
let n: i32 = input2.trim().parse().unwrap();

let mut sum: i32 = 0;
for _i in 0..n
// `_i`, not `i` when intentional
{
    let mut input3 = String::new();
    io::stdin().read_line(&mut input3).unwrap();
    let numbers: Vec<i32> = input3
        .split_whitespace()
        .map(|s| s.parse::<i32>().unwrap())
        .collect();

    let a = numbers[0];
    let b = numbers[1];

    sum += a * b;
}

let ans: String =
    if sum == x { "Yes".to_string() }
    else { "No".to_string() };

println!("{}", ans);
```


## [25314. 코딩은 체육과목 입니다](#list)

(2023.06.17)

> 20

> long long long long long int

#### C++ (2023.06.17)
```cpp
int N;
cin >> N;
N /= 4;                                                 // always N/4 > 0 and N%4 = 0

string str = "long";
for (int n = 0; n < N; n++) std::cout << str << ' ';
std::cout << "int" << '\n';

return 0;
```

#### Rust (2023.12.23)
```rust
let mut input = String::new();
io::stdin().read_line(&mut input).unwrap();

let mut n: i32 = input.trim().parse().unwrap();

n /= 4;
for _i in 0..n { print!("long ") };
println!("int");
```


## [11021. A+B - 7](#list)

> 5  
> 1 1  
> 2 3  
> 3 4  
> 9 8  
> 5 2  

> Case #1: 2  
> Case #2: 5  
> ……  
> Case #5: 7

#### Bash (2022.01.31)
```bash
read t

for ((i = 1; i <= t; i++))
do
    read a b
    echo "Case #$i: $((a + b))"
done

# read
```

#### C++ (2021.05.25)
```cpp
int t, a, b;
cin >> t;

for (int i = 1; i <= t; i++)
{
    cin >> a >> b;
    cout << "Case #" << i << ": " << a + b << endl;
}

return 0;
```

#### Golang (2022.03.18)
```go
var t int
fmt.Scanln(&t)

for i := 1; i <= t; i++ {
    var a, b int
    fmt.Scanln(&a, &b)
    fmt.Printf("Case #%d: %d\n", i, a + b)
}
```

#### Rust (2023.12.23)
```rust
let mut input1 = String::new();
io::stdin().read_line(&mut input1).unwrap();
let t: i32 = input1.trim().parse().unwrap();

for i in 1..t+1
{
    let mut input2 = String::new();
    io::stdin().read_line(&mut input2).unwrap();
    let numbers: Vec<i32> = input2
        .split_whitespace()
        .map(|s| s.parse::<i32>().unwrap())
        .collect();

    let a = numbers[0];
    let b = numbers[1];

    println!("Case #{}: {}", i, a + b);
}
```


## [11022. A+B - 8](#list)

> 5  
> 1 1  
> 2 3  
> 3 4  
> 9 8  
> 5 2  

> Case #1: 1 + 1 = 2  
> Case #2: 2 + 3 = 5  
> ……  
> Case #5: 5 + 2 = 7

#### Bash (2022.01.31)
```bash
read t

for ((i = 1; i <= t; i++))
do
    read a b
    echo "Case #$i: $a + $b = $((a + b))"
done

# read
```

#### C++ (2021.05.25)
```cpp
int t, a, b;
cin >> t;

for (int i = 1; i <= t; i++)
{
    cin >> a >> b;
    cout << "Case #" << i << ": " << a << " + " << b << " = " << a + b << endl;
}

return 0;
```

#### Golang (2022.03.18)
```go
var t int
fmt.Scanln(&t)

for i := 1; i <= t; i++ {
    var a, b int
    fmt.Scanln(&a, &b)
    fmt.Printf("Case #%d: %d + %d = %d\n", i, a, b, a + b)
}
```

#### Rust (2023.12.23)
```rust
let mut input1 = String::new();
io::stdin().read_line(&mut input1).unwrap();
let t: i32 = input1.trim().parse().unwrap();

for i in 1..t+1
{
    let mut input2 = String::new();
    io::stdin().read_line(&mut input2).unwrap();
    let numbers: Vec<i32> = input2
        .split_whitespace()
        .map(|s| s.parse::<i32>().unwrap())
        .collect();

    let a = numbers[0];
    let b = numbers[1];

    println!("Case #{}: {} + {} = {}", i, a, b, a + b);
}
```


## [2438. 별 찍기 - 1](#list)

> 5

> \*  
> \*\*  
> \*\*\*  
> \*\*\*\*  
> \*\*\*\*\*

#### Bash (2022.01.31)
```bash
read n

for ((i = 1; i <= n; i++))
do
    for ((j = 1; j <= i; j++))
    do
        echo -n '*'
    done

    echo ''
done

# read
```

#### C++ (2021.05.25)
```cpp
int a;
cin >> a;

for (int i = 1; i <= a; i++)
{
    // cout << '*' * i << endl;        // calculate ascii code number(42) * i
    for (int j = 1; j <= i; j++)
    {
        cout << '*' ;
    }
    cout << '\n' ;
}

return 0;
```

#### Golang - trial 1 (2022.03.18)
```go
import (
    "fmt"
    "strings"
)
```
```go
var n int
fmt.Scanln(&n)

var star string = "*"
for i := 1; i <= n; i++ {
    fmt.Println(strings.Repeat(star, i ))
}
```

#### Golang - trial 2 (2022.03.18)
```go
var n int
fmt.Scanln(&n)

var star string = ""
for i := 1; i <= n; i++ {
    star += "*"
    fmt.Println(star)
}
```
> rather slower??

#### Rust (2023.12.23)
```rust
let mut input = String::new();
io::stdin().read_line(&mut input).unwrap();

let n: i32 = input.trim().parse().unwrap();

for _i in 0..n
{
    for _j in 0.._i+1 { print!("*") };
    println!();
};
```


## [2439. 별 찍기 - 2](#list)

> 5

> &nbsp;&nbsp;&nbsp;&nbsp;\*  
> &nbsp;&nbsp;&nbsp;\*\*  
> &nbsp;&nbsp;\*\*\*  
> &nbsp;\*\*\*\*  
> \*\*\*\*\*

#### Bash (2022.01.31)
```bash
read n

for ((i = 1; i <= n; i++))
do
    for ((j = 0; j < n; j++))
    do
        if [ $j -lt $((n - i)) ]; then
            echo -n ' '
        else
            echo -n '*'
        fi
    done

    echo ''
done

# read
```

#### C++ (2021.05.25)
```cpp
int a;
cin >> a;

for (int i = 1; i <= a; i++)
{
    for (int j = 1; j <= a; j++)
    {
        if (i < a - j + 1)
        {
            cout << ' ' ;
        } else {
            cout << '*' ;
        }
    }
    cout << '\n' ;
}

return 0;
```

#### Golang (2022.03.18)
```go
import (
    "fmt"
    "strings"
)
```
```go
var n int
fmt.Scanln(&n)

for i := 1; i <= n; i++ {
    fmt.Println(strings.Repeat(" ", n - i) + strings.Repeat("*", i ))   // not , but +
}
```

#### Rust (2023.12.23)
```rust
let mut input = String::new();
io::stdin().read_line(&mut input).unwrap();

let n: i32 = input.trim().parse().unwrap();

for i in 0..n
{
    for j in 0..n
    {
        if j < n - i - 1 { print!(" ") }
        else { print!("*") }
    }
    println!();
}
```


## [2741. N 찍기](#list)

> 5

> 1 2 3 4 5 (vertically)

#### Bash
```bash
read n

for ((i = 1; i <= n; i++))
do
    echo $i
done

# read
```
> 시간 초과

#### C++
```cpp
// make cin/cout faster
cin.tie(NULL);
ios_base::sync_with_stdio(false);

int a;
cin >> a;

for (int i = 1; i <= a; i++)
{
    cout << i << '\n';              // \n is faster than endl
}

return 0;
```

#### Golang
```go
import (
    "fmt"
    "bufio"
    "os"
)
```
```go
// var reader = bufio.NewReader(os.Stdin)      // do not need
var writer = bufio.NewWriter(os.Stdout)
defer writer.Flush()

var n int
fmt.Scanln(&n)

for i := 1; i <= n; i++ {
    fmt.Fprintln(writer, i)
}
```


## [2742. 기찍 N](#list)

> 5

> 5 4 3 2 1 (vertically)

#### Bash
```bash
read n

for ((i = n; i > 0; i--))
do
    echo $i
done

# read
```
> 시간 초과

#### C++
```cpp
// make cin/cout faster
cin.tie(NULL);
ios_base::sync_with_stdio(false);

int a;
cin >> a;

for (int i = a; i >= 1; i--)
{
    cout << i << '\n';              // \n is faster than endl
}

return 0;
```

#### Golang
```go
import (
    "fmt"
    "bufio"
    "os"
)
```
```go
// var reader = bufio.NewReader(os.Stdin)      // do not need
var writer = bufio.NewWriter(os.Stdout)
defer writer.Flush()

var n int
fmt.Scanln(&n)

for i := n; i > 0; i-- {
    fmt.Fprintln(writer, i)
}
```
