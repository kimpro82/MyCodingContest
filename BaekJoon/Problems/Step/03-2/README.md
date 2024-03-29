## [BAEKJOON Online Judge](../../../../README.md#baekjoon-online-judge)

# 문제 > 단계별로 풀어보기 > 3. 반복문 - 2) while문

https://www.acmicpc.net/step/3 ~https://www.acmicpc.net/step/2~

(2021.05.26) - `C++`  
(2022.02.02) - `Bash`  
(2022.03.29) - `Golang`  
(2023.12.23) - `Rust`  


### **List**

- [10952. A+B - 5](#10952-ab---5)
- [10951. A+B - 4](#10951-ab---4)

#### (Depreciated)
- [1110. 더하기 사이클](#1110-더하기-사이클)


**※ Note**  

&nbsp;&nbsp; - All the codes of any language for the same problem have basically the same result.  
&nbsp;&nbsp; - Typical headers like the below are basically skipped, but they are noted seperately when there are any additional line.  
&nbsp;&nbsp;&nbsp;&nbsp; · *Bash* : `#!/bin/bash`  
&nbsp;&nbsp;&nbsp;&nbsp; · *C++* : `#include <iostream>` `#define endl '\n';` `using namespace std;` `int main() {}`  
&nbsp;&nbsp;&nbsp;&nbsp; · *Golang* : `package main` `import "fmt"` `func main() {}`  
&nbsp;&nbsp;&nbsp;&nbsp; · *Rust* : `use std::io;` `fn main() {}`  


## [10952. A+B - 5](#list)

> 1 1  
> 2 3  
> 3 4  
> 9 8  
> 5 2  
> 0 0

> 2 5 7 17 7 (vertically)

#### Bash (2022.02.02)
```bash
while true
do
    read a b
    let "sum = a + b"

    if [ $sum -gt 0 ] ; then
        echo $sum
    else
        break
    fi
done
```

#### C++ (2021.05.26)
```cpp
int a, b;

while (true)
{
    cin >> a >> b;
    if (a != 0 || b != 0)       // Readability? vs (a == 0 && b == 0)
    {
        cout << a + b << endl;            
    } else
    {
        break;
    }
}

return 0;
```

#### Golang (2022.03.21)
```golang
var a, b int

for true {
    fmt.Scanln(&a, &b)

    if a == 0 && b == 0 {
        break
    }

    fmt.Println(a + b)
}
```

#### Rust (2023.12.23)
```rust
loop
{
    let mut input = String::new();
    io::stdin().read_line(&mut input).unwrap();
    let numbers: Vec<i32> = input
        .split_whitespace()
        .map(|s| s.parse::<i32>().unwrap())
        .collect();

    if numbers.len() == 0 { break; }                    // EOF
    else
    {
        let sum: i32 = numbers[0] + numbers[1];
        println!("{}", sum);
    };
}
```


## [10951. A+B - 4](#list)

> 1 1  
> 2 3  
> 3 4  
> 9 8  
> 5 2

> 2 5 7 17 7 (vertically)

#### Bash (2022.02.02)
```bash
while true
do
    read a b

    if [ $a -ne $? ] ; then     # it works but return this message > [: -ne: unary operator expected
        let "sum = a + b"
        echo $sum
    else
        break
    fi
done
```

#### C++ (2021.05.26)
```cpp
int a, b;

while (true)
{

    cin >> a >> b;              // wrong when this line is located after cin.eof()
    if (cin.eof() == true)      // find if the input data finish (EOF; End Of File)
    {
        break;
    } else
    {
        cout << a + b << endl;            
    }
}

return 0;
```

#### Golang (2022.03.29)
```golang
import (
    "fmt"
    "strconv"
)
```
```golang
for true {
    var a, b string
    var aInt, bInt int

    fmt.Scanln(&a, &b)
    if a == "" {
        break
    }

    aInt, _ = strconv.Atoi(a)
    bInt, _ = strconv.Atoi(b)
    fmt.Println(aInt + bInt)
}
```

#### Rust (2023.12.23)
```rust
loop
{
    let mut input = String::new();
    io::stdin().read_line(&mut input).unwrap();
    let numbers: Vec<i32> = input
        .split_whitespace()
        .map(|s| s.parse::<i32>().unwrap())
        .collect();

    let a = numbers[0];
    let b = numbers[1];

    if a == 0 && b == 0 { break; }
    else { println!("{}", a + b) };
}
```


## [1110. 더하기 사이클](#list)

> 26 55 1 0 (independently)

> 4 3 60 1

#### Bash (2022.02.02)
```bash
read n

let "ab = n"
let "t = 0"

while true
do
    let "a = ab / 10"
    let "b = ab % 10"
    let "ab = a + b"

    if [ $ab -lt 10 ]; then
        let "ab += b * 10"
    else
        let "ab = b * 10 + ab % 10"
    fi

    let "t += 1"

    # test
    # echo "t: $t, a: $a, b: $b, ab: $ab"

    if [ $ab -eq $n ]; then
        break
    fi
done

echo $t
```

#### C++ (2021.05.26)
```cpp
int n, a, b, ab, t = 0;         // 0 <= n <= 99, n = a * 10 + b, ab = a + b
cin >> n ;                      // n  = 26

ab = n;                         // ab = 26

while (true)
{
    a = ab / 10;                // a  = 2   6
    b = ab % 10;                // b  = 6   8
    ab = a + b;                 // ab = 8   14

    if (ab < 10)
    {
        ab += b * 10;           // ab = 68  

    } else
    {
        ab = b * 10 + ab % 10;  // ab =     84
    }

    t++;

    // Test
    // cout << "n: " << n << " t: " << t << " a: " << a << " b: " << b << " ab: " << ab << '\n';

    if (n == ab)
    {
        break;
    }
}

cout << t << '\n';

return 0;
```

#### Golang (2022.03.29)
```golang
var n, a, b int                    // n < 100
fmt.Scanln(&n)    

var t int = 0
var ab = n

for true {
    a = ab / 10
    b = ab % 10
    ab = a + b

    if (ab < 10) {
        ab += b * 10
    } else {
        ab = b * 10 + ab % 10
    }

    t++

    if (n == ab) {
        break;
    }
}

fmt.Println(t)
```