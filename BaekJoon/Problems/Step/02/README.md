## [BAEKJOON Online Judge](/README.md#baekjoon-online-judge)

# 문제 > 단계별로 풀어보기 > 2. 조건문

(2021.05.24) - `C++`  
(2021.07.14) - `R`  
(2022.01.29) - `Bash`  
(2022.03.14) - `Golang`  
(2023.12.22) - `Rust`  

https://www.acmicpc.net/step/4


### **List**

- [1330. 두 수 비교하기](#1330-두-수-비교하기)
- [9498. 시험 성적](#9498-시험-성적)
- [2753. 윤년](#2753-윤년)
- [14681. Quadrant Selection](#14681-quadrant-selection)
- [2884. SPAVANAC](#2884-spavanac)
- [2525. 오븐 시계](#2525-오븐-시계)
- [2480. 주사위 세개](#2480-주사위-세개)

**※ Note**  
&nbsp;&nbsp; - All the codes of any language for the same problem have basically the same result.  
&nbsp;&nbsp; - Typical headers like the below are basically skipped, but they are noted seperately when there are any additional line.  
&nbsp;&nbsp;&nbsp;&nbsp; · *Bash* : `#!/bin/bash`  
&nbsp;&nbsp;&nbsp;&nbsp; · *C++* : `#include <iostream>` `#define endl '\n';` `using namespace std;` `int main() {}`  
&nbsp;&nbsp;&nbsp;&nbsp; · *Golang* : `package main` `import "fmt"` `func main() {}`  
&nbsp;&nbsp;&nbsp;&nbsp; · *Rust* : `use std::io;` `fn main() {}`  
&nbsp;&nbsp; - *R* : Some answers occur runtime errors with unknowable reason in the BOJ grading machine.   


## [1330. 두 수 비교하기](#list)

> 1 2, 10 2, 5 5 (independently)

> \<  
> \>  
> \=\=

#### Bash (2022.01.29)
```bash
read a b

if [ $a -gt $b ] ; then echo ">"        # gt : >, ge : >=
elif [ $a -lt $b ] ; then echo "<"      # lt : <, le : <=
else echo "=="
fi                                      # fi : (maybe) finish if …… or simply reversed "if"?

# read
```

#### C++ (2021.05.24)
```cpp
int a, b;
cin >> a >> b;          // 1 2, 10 2, 5 5

if (a > b)
{
    cout << ">" << endl;
} else if (a < b)
{
    cout << "<" << endl;
} else
{
    cout << "==" << endl;
}

return 0;
```

#### Golang (2022.03.14)
```go
var a, b int
fmt.Scanln(&a, &b)

if (a > b) {
    fmt.Println(">")
} else if (a < b) {
    fmt.Println("<")
} else {
    fmt.Println("==")
}
```

#### R (2021.07.14)
```R
data <- scan("stdin")
# data <- c(1,2)        # test

a <- data[1]
b <- data[2]

if (a > b)
{
    cat(">")
} else if (a < b)
{
    cat("<")
} else 
{
    cat("==")
}
```

#### Rust (2023.12.22)
```rust
let mut input = String::new();
io::stdin().read_line(&mut input).unwrap();

let numbers: Vec<i32> = input
    .split_whitespace()
    .map(|s| s.parse::<i32>().unwrap())
    .collect();

let a = numbers[0];
let b = numbers[1];
let ans: String =                                       // works?
    if a > b { ">".to_string() }
    else if a < b { "<".to_string() }
    else { "==".to_string() };

println!("{}", ans);
```


## [9498. 시험 성적](#list)

> 99, 82, 79, 60, 37 (independently)

> A B C D F

#### Bash (2022.01.29)
```bash
# test
# echo [ 3 -gt 2 ]                      # doesn't work
# echo [ 3 -lt 2 ]                      # doesn't work
# echo $((3 > 2))                       # 1
# echo $((3 < 2))                       # 0

read n

# if $(($n >= 90)) ; then echo 'A'      # doesn't work
if [ $n -ge 90 ] ; then echo 'A'
elif [ $n -ge 80 ] ; then echo 'B'
elif [ $n -ge 70 ] ; then echo 'C'
elif [ $n -ge 60 ] ; then echo 'D'
else echo 'F'
fi

# read
```

#### C++ (2021.05.24)
```cpp
int a;
cin >> a;                   // 99, 82, 79, 60, 37

if (a >= 90)
{
    cout << "A" << endl;
} else if (a >= 80)
{
    cout << "B" << endl;
} else if (a >= 70)
{
    cout << "C" << endl;
} else if (a >= 60)
{
    cout << "D" << endl;
} else
{
    cout << "F" << endl;
}

return 0;
```

#### Golang - trial 1 (2022.03.14)
use `if ~ else if ~ else` statement
```go
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
```

#### Golang - trial 2 (2022.03.14)
use `switch ~ case` statement
```go
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
```

#### Golang - trial 3 (2022.03.14)
use `array` trickily
```go
var input int
fmt.Scanln(&input)

grade := [11]string{"F", "F", "F", "F", "F", "F", "D", "C", "B", "A", "A"}
fmt.Println(grade[input / 10])
```

#### R (2021.07.14)
```R
a <- scan("stdin")
# a <- 100          # test

if (a >= 90)
{
    cat("A\n")
} else if (a >= 80)
{
    cat("B\n")
} else if (a >= 70)
{
    cat("C\n")
} else if (a >= 60)
{
    cat("D\n")
} else 
{
    cat("F\n")
}
```

#### Rust - trial 1 (2023.12.22)
```rust
let mut input = String::new();
io::stdin().read_line(&mut input).unwrap();

let n: i32 = input.trim().parse().unwrap();
let ans: char =
    if n >= 90 { 'A' }
    else if n >= 80 { 'B' }
    else if n >= 70 { 'C' }
    else if n >= 60 { 'D' }
    else { 'F' };

println!("{}", ans);                                    // "{}", not '{}'
```

#### Rust - trial 2 (2023.12.22)
```rust
let mut input = String::new();
io::stdin().read_line(&mut input).unwrap();

let n: i32 = input.trim().parse().unwrap();
let v = vec!['F', 'F', 'F', 'F', 'F', 'F', 'D', 'C', 'B', 'A', 'A'];
// [], not {}

println!("{}", &v[(n/10) as usize]);
// neither [n/10] nor [n/10 as usize]
```


## [2753. 윤년](#list)

> 2021 2000 1999 (independently)

> 0 1 0

#### Bash (2022.01.29)
```bash
read n

# Test : all cases work
# if [ $(($n % 4)) == 0 ] ; then
#     echo "success 1"
# fi
# if [ $(($n%100)) == 0 ] ; then
#     echo "success 2"
# fi
# if [ $(($n % 400)) == 0 ] ; then
#     echo "success 3"
# fi

if [ $(($n % 4)) == 0 ] ; then
    if [ $(($n%100)) != 0 ] || [ $(($n % 400)) == 0 ] ; then    # failed to write 3 conditions in a line
        echo 1
    else
        echo 0
    fi
else
    echo 0
fi

# read
```

#### C++ (2021.05.24)
```cpp
int a;
cin >> a;                                           // 2021, 2000, 1900

if (a % 4 == 0 && (a % 100 != 0 || a % 400 == 0))
{
    cout << 1 << endl;
} else
{
    cout << 0 << endl;
}

return 0;
```

#### Golang (2022.03.14)
```go
var n int
fmt.Scanln(&n)

var answer int
if (n % 4 == 0 && (n % 100 != 0 || n % 400 == 0)) {
    answer = 1
} else {
    answer = 0
}

fmt.Println(answer)
```

#### R (2021.07.14)
```R
n <- scan("stdin")
# n <- 2000                                             # test

if (n %% 4 == 0 && (n %% 100 != 0 || n %% 400 == 0))    # not %
{
    cat("1\n")
} else
{
    cat("0\n")
}
```
> Runtime Error???

#### Rust (2023.12.22)
```rust
let mut input = String::new();
io::stdin().read_line(&mut input).unwrap();

let n: i32 = input.trim().parse().unwrap();
let ans: i32 =
    if n % 4 == 0 && (n % 100 != 0 || n % 400 == 0) { 1 }
    else { 0 };

println!("{}", ans);
```


## [14681. Quadrant Selection](#list)

> 12 5, 9 -13 (independently)

> 1  
> 4

#### Bash (2022.01.29)
```bash
read x
read y

if [ $x -gt 0 ] && [ $y -gt 0 ] ; then
    echo 1
elif [ $x -lt 0 ] && [ $y -gt 0 ] ; then
    echo 2
elif [ $x -lt 0 ] && [ $y -lt 0 ] ; then
    echo 3
else
    echo 4
fi
```

#### C++ (2021.05.24)
```cpp
int a, b;
cin >> a >> b;           // 12 5, 9 -13
// A given condition : Neither of the two coordinates will be 0.

if (a > 0 && b > 0)
{
    cout << 1 << endl;
} else if (a < 0 && b > 0)
{
    cout << 2 << endl;
} else if (a < 0 && b < 0)
{
    cout << 3 << endl;
} else
{
    cout << 4 << endl;
}

return 0;
```

#### Golang (2022.03.14)
```go
var x, y int
fmt.Scanln(&x)
fmt.Scanln(&y)

var dim int
if (x > 0 && y > 0) {
    dim = 1
} else if (x < 0 && y > 0) {
    dim = 2
} else if (x < 0 && y < 0) {
    dim = 3
} else {
    dim = 4
}

fmt.Println(dim)
```

#### R (2021.07.14)
```R
data <- scan("stdin")
# data <- c(12, 5)          # test

x <- data[1]
y <- data[2]

if (x > 0 && y > 0)
{
    cat("1\n")
} else if (x < 0 && y > 0)
{
    cat("2\n")
} else if (x < 0 && y < 0)
{
    cat("3\n")
} else 
{
    cat("4\n")
}
```

#### Rust (2023.12.22)
```rust
let mut input1 = String::new();
let mut input2 = String::new();

io::stdin().read_line(&mut input1).unwrap();
io::stdin().read_line(&mut input2).unwrap();

let a: i32 = input1.trim().parse().unwrap();
let b: i32 = input2.trim().parse().unwrap();

let ans =
    if a > 0
    {
        if b > 0 { 1 }
        else { 4 }
    }
    else
    {
        if b > 0 { 2 }
        else { 3 }
    };

println!("{}", ans);
```


## [2884. SPAVANAC](#list)

> 10 10, 0 30, 23 40 (independently)

> 9 25  
> 23 45  
> 22 55

#### Bash (2022.01.29)
```bash
read h m

if [ $m -lt 45 ] ; then
    let "h -= 1"
    let "m += 60"
fi

if [ $h -lt 0 ] ; then
    let "h += 24"
fi

echo $h $(($m - 45))
```

#### C++ (2021.05.24)
```cpp
int a, b;
cin >> a >> b;           // 10 10, 0 30, 23 40

if (b < 45)
{
    a--;
    b += 60;
}
if (a < 0)
{
    a += 24;
}

cout << a << " " << b - 45 << endl;

return 0;
```

#### Golang (2022.03.14)
```go
var h, m int
fmt.Scanln(&h, &m)

if (m < 45) {
    h--
    m += 60
}
if (h < 0) {
    h += 24
}

fmt.Println(h, m - 45)
```

#### R (2021.07.14)
```R
data <- scan("stdin")
# data <- c(10, 10)          # test

a <- data[1]
b <- data[2]

if (b < 45)
{
    a = a - 1
    b = b + 60
}
if (a < 0)
{
    a = a + 24
}

cat(a, b - 45, "\n")
```
> Runtime Error???????

#### Rust (2023.12.22)
```rust
let mut input = String::new();
io::stdin().read_line(&mut input).unwrap();

let numbers: Vec<i32> = input
    .split_whitespace()
    .map(|s| s.parse::<i32>().unwrap())
    .collect();

let mut a = numbers[0] + 24;
let mut b = numbers[1];

if b >= 45
{
    b -= 45;
}
else
{
    a -= 1;
    b += 60 - 45;
}
a %= 24;

println!("{} {}", a, b);
```


## [2525. 오븐 시계](#list)

> 23 48  
> 25

> 0 13

#### Golang (2022.03.14)
```go
var a, b, c int
fmt.Scanln(&a, &b)
fmt.Scanln(&c)

b += c
for (b > 59) {      // Golang has no While statement!
    a++
    b -= 60        
}                   // actually not necessary to use loop

a %= 24

fmt.Println(a, b)
```

#### Rust (2023.12.22)
```rust
let mut input1 = String::new();
let mut input2 = String::new();

io::stdin().read_line(&mut input1).unwrap();
io::stdin().read_line(&mut input2).unwrap();

let numbers: Vec<i32> = input1
    .split_whitespace()
    .map(|s| s.parse::<i32>().unwrap())
    .collect();
let numbers2: i32 = input2.trim().parse().unwrap();

let mut a = numbers[0];
let mut b = numbers[1];
let c = numbers2;

b += c;
a += b / 60;
b %= 60;
a %= 24;

println!("{} {}", a, b);
```


## [2480. 주사위 세개](#list)

> 3 3 6, 2 2 2, 6 2 5 (independently)

> 1300  
> 12000  
> 600

#### Golang - trial 1 (2022.03.14)
```go
package main
import (
    "fmt"
    "math"
)
```
```go
var a, b, c int
fmt.Scanln(&a, &b, &c)

var prize int
if (a == b && b == c) {
    prize = 10000 + a * 1000
} else if (a == b) {
    prize = 1000 + a * 100
} else if (b == c) {
    prize = 1000 + b * 100
} else {
    // trial 1 : false
    var max int = int(math.Max(math.Max(float64(a), float64(b)), float64(c)))

    prize = max * 100
}

fmt.Println(prize)
```

#### Golang - trial 2 (2022.03.14)
```go
    ……
    // trial 2 : false
    var max int = a
    if (max < b) {
        max = b
    }
    if (max < c) {
        max = c
    }
    ……
```

#### Golang - trial 3 (2022.03.14)
```go
    ……
    } else if (c == a) {
        // trial 3
        prize = 1000 + c * 100        // I missed it!
    } else {
    ……
```

#### Rust (2023.12.22)
```rust
let mut input = String::new();

io::stdin().read_line(&mut input).unwrap();

let numbers: Vec<i32> = input
    .split_whitespace()
    .map(|s| s.parse::<i32>().unwrap())
    .collect();

let a = numbers[0];
let b = numbers[1];
let c = numbers[2];

let ans =
    if a == b && b == c { 10000 + a * 1000 }
    else if a == b { 1000 + a * 100 }
    else if b == c { 1000 + b * 100 }
    else if c == a { 1000 + c * 100 }
    else
    {
        if a > b && a > c { a * 100 }
        else if b > a && b > c { b * 100 }
        else { c * 100 }
    };

println!("{}", ans);
```
