## BAEKJOON Online Judge

# 문제 > 단계별로 풀어보기 > 4. while문

(2021.05.26) - `C++`  
(2022.02.02) - `Bash`

https://www.acmicpc.net/step/2


### **List**

- [10952. A+B - 5](#10952-ab---5)
- [10951. A+B - 4](#10951-ab---4)
- [1110. 더하기 사이클](#1110-더하기-사이클)

**※ Note**  

&nbsp;&nbsp; - All the codes of any language for the same problem have basically the same result.  
&nbsp;&nbsp; - `Bash` : skipped the first line; `#!/bin/bash`  
&nbsp;&nbsp; - `C++` : skipped `main()` function's brace(`{}`) and its outside


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


## [1110. 더하기 사이클](#list)

> 26 55 1 0 (vertically)

> 4 3 60 1 (vertically)

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