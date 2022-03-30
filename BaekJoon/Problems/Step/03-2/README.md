## BAEKJOON Online Judge

# 문제 > 단계별로 풀어보기 > 3. 반복문 - 2) while문

https://www.acmicpc.net/step/3 ~https://www.acmicpc.net/step/2~

(2021.05.26) - `C++`  
(2022.02.02) - `Bash`  
(2022.03.29) - `Golang`


### **List**

- [10952. A+B - 5](#10952-ab---5)
- [10951. A+B - 4](#10951-ab---4)
- [1110. 더하기 사이클](#1110-더하기-사이클)


**※ Note**  

&nbsp;&nbsp; - All the codes of any language for the same problem have basically the same result.  
&nbsp;&nbsp; - `Bash` : skipped the first line; `#!/bin/bash`  
&nbsp;&nbsp; - `C++`* : skipped `main()` function's brace(`{}`) and its outside including two header lines; `#include <iostream>` `using namespace std;`  
&nbsp;&nbsp; - `Golang`* : skipped `main()` function's brace(`{}`) and its outside including two header lines; `package main` `import "fmt"`  
&nbsp;&nbsp; * When any additional header is used, the header block is also noted seperately.


## [10952. A+B - 5](#list)

> 1 1  
> 2 3  
> 3 4  
> 9 8  
> 5 2  
> 0 0

> 2 5 7 17 7 (vertically)

#### Bash
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

#### C++
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

#### Golang
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


## [10951. A+B - 4](#list)

> 1 1  
> 2 3  
> 3 4  
> 9 8  
> 5 2

> 2 5 7 17 7 (vertically)

#### Bash
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

#### C++
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

#### Golang
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


## [1110. 더하기 사이클](#list)

> 26 55 1 0 (independently)

> 4 3 60 1

#### Bash
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

#### C++
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

#### Golang
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