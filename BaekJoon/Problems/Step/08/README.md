## [BAEKJOON Online Judge](/README.md#baekjoon-online-judge)

# 문제 > 단계별로 풀어보기 > 8. 일반 수학 1

https://www.acmicpc.net/step/8

(2021.07.12, 2023.06.28) - `C++`  
(2022.03.11) - `Bash`  
(2024.04.03) - `Rust`


## **List**

- [2745. 진법 변환](#2745-진법-변환) *(new)*
- [11005. 진법 변환 2](#11005-진법-변환-2) *(new)*
- [2720. Quick Change (세탁소 사장 동혁)](#2720-quick-change-세탁소-사장-동혁) *(new)*
- [2903. PLANINA (중앙 이동 알고리즘)](#2903-planina-중앙-이동-알고리즘) *(new)*
- [2292. 벌집](#2292-벌집)
- [1193. 분수찾기](#1193-분수찾기)
- [2869. PUŽ (달팽이는 올라가고 싶다)](#2869-puž-달팽이는-올라가고-싶다)

#### (Depreciated)
- [1011. Fly me to the Alpha Centauri](#1011-fly-me-to-the-alpha-centauri)
- [1712. 손익분기점](#1712-손익분기점)
- [2775. 부녀회장이 될테야](#2775-부녀회장이-될테야)
- [10250. ACM Hotel (ACM 호텔)](#10250-acm-hotel-acm-호텔)
- [10757. 큰 수 A+B](#10757-큰-수-ab)


**※ Note**

&nbsp;&nbsp; - All the code of any language for the same problem has basically the same result.  
&nbsp;&nbsp; - Typical headers like the below are basically skipped, but they are noted seperately when there are any additional line.    
&nbsp;&nbsp;&nbsp;&nbsp; · *Bash* : `#!/bin/bash`  
&nbsp;&nbsp;&nbsp;&nbsp; · *C++* : `#include <iostream>` `#define endl '\n';` `using namespace std;`  
&nbsp;&nbsp;&nbsp;&nbsp; · *Rust* : `use std::io;`  


## [2745. 진법 변환](#list)

```txt
ZZZZZ 36
```
```txt
60466175
```

<details>
  <summary>C++ (2023.06.27)</summary>

```cpp
#include <iostream>
#include <cmath>

// #define test
#define endl '\n'

using namespace std;
```
```cpp
int main()
{
    // Input : N <= 10^9, 2 <= B <= 36
    string N;
    int B;
    cin >> N >> B;

    // Operate
    int len = N.size();
    int sum = 0;
    char c;
    for (int i = 0; i < len; i++)
    {
        c = N[len-i-1];
        if (c <= '9') sum += (c - '0')  * int(pow(B, i));
        else sum += (c - 'A' + 10) * int(pow(B, i));

        #ifdef test
            printf("%d %c %d\n", i, c, sum);
        #endif
    }

    // Output
    cout << sum << endl;

    return 0;
}
```
</details>
<details>
  <summary>Rust (2024.04.03)</summary>

```rust

```
</details>


## [11005. 진법 변환 2](#list)

```txt
60466175 36
```
```txt
ZZZZZ
```

<details>
  <summary>C++ (2023.06.28)</summary>

```cpp
#include <iostream>
#include <vector>

// #define test
#define endl '\n'

using namespace std;
```
```cpp
int main()
{
    // Input : N <= 10^9, 2 <= B <= 36
    int N, B;
    cin >> N >> B;

    // Operate
    vector<char> v;
    int temp;
    char c;
    while (N > 0)
    {
        temp = N % B;                                       // temp must be less than B
        if (temp < 10) c = char(temp + '0');
        else c = char(temp - 10 + 'A');
        v.push_back(c);
        N /= B;

        #ifdef test
            printf("N:%d temp:%d char:%c\n", N, temp, c);
        #endif
    }

    // Output
    int len = v.size();
    for (int i = 0; i < len; i++) cout << v[len-i-1];
    cout << endl;

    return 0;
}
```
</details>
<details>
  <summary>Rust (2024.04.03)</summary>

```rust

```
</details>


## [2720. Quick Change (세탁소 사장 동혁)](#list)

```txt
3
124
25
194
```
```txt
4 2 0 4
1 0 0 0
7 1 1 4
```

<details>
  <summary>C++ (2023.06.28)</summary>

```cpp
#include <iostream>
#include <vector>

#define endl '\n'

using namespace std;
```
```cpp
int main()
{
    // Input : 1 <= C <= 500
    int T, c;
    cin >> T;
    vector<int> C;
    for (int t = 0; t < T; t++)
    {
        cin >> c;
        C.push_back(c);
    }

    // Operate & Output
    vector<int> v = {25, 10, 5, 1};
    int len = v.size();
    for (int t = 0; t < T; t++)
    {
        vector<int> cnt(len, 0);
        for (int i = 0; i < len; i++)
        {
            cnt[i] += C[t] / v[i];
            C[t] -= cnt[i] * v[i];

            cout << cnt[i] << ' ';
        }
        cout << endl;
    }

    return 0;
}
```
</details>
<details>
  <summary>Rust (2024.04.03)</summary>

```rust

```
</details>


## [2903. PLANINA (중앙 이동 알고리즘)](#list)

```txt
5
```
```txt
1089
```

<details>
  <summary>C++ (2023.06.28)</summary>

```cpp
int main()
{
    // Input : 1 <= N <= 15
    int N;
    cin >> N;

    // Operate : avoid pow() because it returns wrong values in MinGWs
    int quad = 1;
    for (int i = 0; i < N; i++) quad *= 2;
    int ans = (quad + 1) *  (quad + 1);                     // max < 2.1b when N = 15

    // Output
    cout << ans << endl;

    return 0;
}
```
</details>
<details>
  <summary>Rust (2024.04.03)</summary>

```rust

```
</details>


## [2292. 벌집](#list)

```txt
13
```
```txt
3
```

<details>
  <summary>Bash (2022.03.11)</summary>

```bash
read n

let "move = 0"

while [ $n -gt 1 ]
do
    ((move++))
    let "n -= 6 * move"

    # test
    # echo $n $move
done

echo $((move + 1))
```
</details>
<details>
  <summary>C++ (2022.07.12)</summary>

```cpp
int main()
{
    int a;
    cin >> a;

    int move = 0;
    while (a > 1)
    {
        move++;
        a -= 6 * move;

        // test
        // cout << a << " " << move << endl;
    }

    cout << move + 1 << endl;

    return 0;
}
```
</details>
<details>
  <summary>Rust (2024.04.03)</summary>

```rust

```
</details>


## [1193. 분수찾기](#list)

```txt
14
```
```txt
14 1 1  
14 2 3  
14 3 6  
14 4 10  
14 5 15  
2/4
```

<details>
  <summary>Bash (2022.03.11)</summary>

```bash
read x

let "zigzag = 0"
let "sum = 0"

while [ $x -gt $sum ]
do
    ((zigzag++))
    let "sum += zigzag"

    # test
    # echo $x $zigzag $sum
done

let "numerator = 0"
let "denominator = 0"

if [[ $((zigzag % 2)) == 0 ]]; then
    let "denominator = sum - x + 1"
    let "numerator = zigzag - denominator + 1"
else
    let "numerator = sum - x + 1"
    let "denominator = zigzag - numerator + 1"
fi

echo ${numerator}/${denominator}
```
</details>
<details>
  <summary>C++ (2022.07.12)</summary>

```cpp
int main()
{
    int x;
    cin >> x;

    int zigzag = 0, sum = 0;
    while (x > sum)
    {
        zigzag++;
        sum += zigzag;

        // test
        cout << x << " " << zigzag << " " << sum << endl;
    }

    int numerator, denominator;
    if (zigzag % 2 == 0)
    {
        denominator = sum - x + 1;
        numerator = zigzag - denominator + 1;         
    } else
    {
        numerator = sum - x + 1;
        denominator = zigzag - numerator + 1;
    }

    cout << numerator << '/' << denominator << endl;

    return 0;
}
```
</details>
<details>
  <summary>Rust (2024.04.03)</summary>

```rust

```
</details>


## [2869. PUŽ (달팽이는 올라가고 싶다)](#list)

```txt
5 1 6
```
```txt
1 5 -1  
2 9 3  
2
```

<details>
  <summary>Bash (2022.03.11)</summary>

```bash
read a b v

let "day = (v - b) / (a - b) - 1"
let "location = (a - b) * day"

while true
do
    ((day++))
    let "location += a"

    # test
    # echo $day $location $((location - v))

    if [ $location -ge $v ]; then
        break
    else
        let "location -= b"
    fi
done

echo $day
```
</details>
<details>
  <summary>C++ (2022.07.12)</summary>

```cpp
int main()
{
    int a, b, v;
    // a : climb upwards in a day
    // b : back down each night, always a > b
    // v : wooden pole's height
    cin >> a >> b >> v;

    // Find the minimum day
    int day = (v - b) / (a - b) - 1;
    int location = (a - b) * day;

    // Climb
    while (true)
    {
        day++;
        location += a;
        
        // test
        cout << day << " " << location << " " << location - v << endl;

        if (location >= v)
        {
            break;
        }
        location -= b;
    }

    // Output
    cout << day << endl;

    return 0;
}
```
</details>
<details>
  <summary>Rust (2024.04.03)</summary>

```rust

```
</details>


## [1011. Fly me to the Alpha Centauri](#list)

```txt
3
0 3
1 5
45 50
```
```txt
3
3
4
```

<details>
  <summary>C++ - Trial 1 (2022.07.12)</summary>

```cpp
/*
(ex) n = 3
    1 + 2 + 1
    = (1 + 2) * 2 - 2
    = {(n + 1)/2 * [{(n + 1)/2 + 1}/2] * 2 - (n + 1)/2
    * t = (n + 1)/2
    = t * (t + 1) - t
    = t^2
    = {(n + 1)/2}^2

(ex) n = 4
    1 + 2 + 2 + 1
    = (1 + 2) * 2
    = {(n/2) * (n/2 + 1)}/2 * 2
    = (n/2) * (n/2 + 1)
    = (n^2 + 2n + 1 - 1)/4
    = {(n + 1)^2 - 1}/4
*/
```
```cpp
#pragma GCC optimize ("O2")
#pragma GCC target ("avx")

#include <iostream>
#include <cmath>
#include<bits/stdc++.h>

using namespace std;
#define endl '\n'
```
```cpp
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int T;
    cin >> T;

    // Test T times
    for (int t = 0; t < T; t++)
    {
        int x, y;
        cin >> x >> y;

        int distance = y - x, move = 0, turn = 0;
        while (true)
        {
            turn++;
            
            if (turn % 2 == 1) move = pow((turn + 1)/2, 2);
            else move = (pow(turn + 1, 2) - 1)/4;

            // test
            cout << turn << " " << move << " " << distance << " " << move - distance << endl;

            if (move >= distance) break;
        }

        // Output
        cout << turn << endl;
    }

    return 0;
}
```
> 1 1 3 -2  
> 2 2 3 -1  
> 3 4 3 1  
> 3  
> ……

> Time Litmit Exceeded?
</details>
<details>
  <summary>C++ - Trial 2 (2022.07.12)</summary>

```cpp
// n is even : distance = {(n + 1)/2}^2
// → n = 2 * sqrt(distance) - 1
// n is odd  : distance = {(n + 1)^2 - 1}/4
```
```cpp
#pragma GCC optimize ("Ofast")
……
```
```cpp
        ……
        int distance = y - x, move = 0;
        int turn = 2 * sqrt(distance) - 2;
        ……
```
> 2 2 3 -1  
> 3 4 3 1  
> 3  
> 3 4 4 0  
> 3  
> 3 4 5 -1  
> 4 6 5 1  
> 4

> Time Litmit Exceeded?
</details>
<details>
  <summary>C++ - Trial 3 (2022.07.12)</summary>

```cpp
……
using ll = long long;
……
```
```cpp
        ……
        ll x, y;                            // int x, y : causes SOF!
        ……

        ll distance = y - x, move = 0;
        ……
```
> Accepted
</details>


## [1712. 손익분기점](#list)

```txt
1000 70 170
```
```txt
11
```

<details>
  <summary>Bash (2022.03.11)</summary>

```bash
read a b c

let "margin = c - b"

if [ $margin -gt 0 ]; then
    echo $((a / margin + 1))
else
    echo -1
fi
```
</details>
<details>
  <summary>C++ (2022.07.12)</summary>

```cpp
int main()
{
    int a, b, c;
    cin >> a >> b >> c;

    int margin = c - b;
    if (c - b > 0)                      // Find if price(c) - variable cost(b) > 0
    {
        cout << a / margin + 1 << endl;
    } else                              // Never can reach BEP
    {
        cout << -1 << endl;
    }

    return 0;
}
```
</details>


## [2775. 부녀회장이 될테야](#list)

```txt
2  
1  
3  
2  
3
```
```txt
6  
10
```

<details>
  <summary>Bash (2022.03.11)</summary>

Rumor has it that there's a tricky way to use **2d array** in Bash although isn't supplied regularly, but I feel quite annoyed today ……
</details>
<details>
  <summary>C++ (2022.07.12)</summary>

```cpp
int main()
{
    int T;
    cin >> T;

    // Test T times
    for (int t = 0; t < T; t++)
    {
        int K, N;
        cin >> K >> N;

        int resident[15][15] = {};      // assumed 0-th floor and 0-th room
        for (int k = 0; k <= K; k++)
        {
            for (int n = 0; n <= N; n++)
            {
                if (k == 0) resident[k][n] = n;
                else if (n <= 1) resident[k][n] = n;
                else resident[k][n] = resident[k-1][n] + resident[k][n-1];
            }
        }

        // Output
        cout << resident[K][N] << endl;
    }

    return 0;
}
```
</details>


## [10250. ACM Hotel (ACM 호텔)](#list)

```txt
2  
6 12 10  
30 50 72
```
```txt
402  
1203
```

<details>
  <summary>Bash (2022.03.11)</summary>

```bash
read t

for ((i = 0; i < t; i++))
do
    read h w n

    let "room = (n - 1) / h + 1"
    let "floor = n % h"

    if [ $floor -eq 0 ]; then
        let "floor = h"
    fi

    if [ $room -lt 10 ]; then
        echo ${floor}0${room}
    else
        echo ${floor}${room}
    fi
done
```
</details>
<details>
  <summary>C++ (2022.07.12)</summary>

```cpp
int main()
{
    int T, H, W, N;
    // T : the number of test cases
    // H : the number of floors, < 99
    // W : the number of rooms on each floor, < 99
    // N : the index of the arrival time of the guest, < H * W 
    cin >> T;

    // Test T times
    for (int t = 0; t < T; t++)
    {
        cin >> H >> W >> N;

        // Operation
        int room = (N - 1) / H + 1; // room is prior to floor
        int floor = N % H;          // the first floor's room number is 1XX
        if (floor == 0)
        {
            floor = H;
        }

        // Output
        if (room < 10)
        {
            cout << floor << 0 << room << endl;
        } else
        {
            cout << floor << room << endl;
        }
    }

    return 0;
}
```
</details>


## [10757. 큰 수 A+B](#list)

```txt
9223372036854775807 9223372036854775808
```
```txt
51615590737044764481  
18446744073709551615
```

<details>
  <summary>Bash (2022.03.11)</summary>

```bash
read a b
let "aLen = ${#a}"
let "bLen = ${#b}"

if [ $aLen -ge $bLen ]; then
    let "maxSize = aLen"
    let "minSize = bLen"
else
    let "maxSize = bLen"
    let "minSize = aLen"
fi

let "buffer = 0"

# test
# echo $maxSize $minSize
```
```bash
# Sum each digit (1) : 0 ~ minSize - 1
for ((i = 0; i < minSize; i++))
do
    let "buffer += ${a:$((aLen-1-i)):1} + ${b:$((bLen-1-i)):1}"     # it works!
    if [ $buffer -lt 10 ]; then
        let "sum[i] = buffer"
        let "buffer = 0"
    else
        let "sum[i] = buffer - 10"
        let "buffer = 1"
    fi

    # test
    # echo $i $buffer ${sum[$i]}
done
```
```bash
# Sum each digit (2) : minSize ~ maxSize - 1
for ((j = minSize; j < maxSize; j++))
do
    if [ $aLen -gt $bLen ]; then
        let "buffer += ${a:$((aLen-1-j)):1}"
    else
        let "buffer += ${b:$((bLen-1-j)):1}"
    fi

    if [ $buffer -lt 10 ]; then
        let "sum[j] = buffer"
        let "buffer = 0"
    else
        let "sum[j] = buffer - 10"
        let "buffer = 1"
    fi

    # test
    # echo $i $buffer ${sum[$i]}
done
```
```bash
# Sum each digit (3) : maxSize
if [ $buffer -eq 1 ]; then
    let "sum[maxSize] = 1"
    let "maxSize++"
fi
# test
# echo $((maxSize-1)) $buffer ${sum[$((maxSize-1))]}
```
```bash
# Output
for ((k = 0; k < maxSize; k++))
do
    echo -n "${sum[$((maxSize-1-k))]}"                              # don't confuse the indexing syntax between array and string!
done
echo
```
> Time Litmit Exceeded
</details>
<details>
  <summary>C++ (2022.07.12)</summary>

```cpp
#include <iostream>
#include <string>

using namespace std;
#define endl '\n'
```
```cpp
int main()
{
    string a, b;
    char sum[10002];
    cin >> a >> b;

    int aSize = a.size(), bSize = b.size();
    int minSize = min(aSize, bSize);
    int maxSize = max(aSize, bSize);
    int buffer = 0;

    // test
    // cout << minSize << " " << maxSize << endl;   // 19 19 - OK

    // Sum each digit : 0 ~ minSize - 1
    // sum contains numbers in reverse order
    for (int i = 0; i < minSize; i++)
    {
        buffer += (a[aSize - 1 - i] - '0') + (b[bSize - 1 - i] - '0');
        if (buffer < 10)
        {
            sum[i] = (char) (buffer + '0');
            buffer = 0;
        } else
        {
            sum[i] = (char) (buffer - 10 + '0');
            buffer = 1;
        }

        // test
        cout << i << " " << a[aSize - 1 - i] << " " << b[bSize - 1 - i] << " " << buffer << " " << sum[i] << endl; 
    }

    // Residual digit : minSize ~ maxSize - 1
    for (int j = minSize; j < maxSize; j++)
    {
        if (aSize > bSize) buffer += a[aSize - 1 - j] - '0';
        else buffer += b[bSize - 1 - j] - '0';   

        if (buffer < 10)
        {
            sum[j] = (char) (buffer + '0');
            buffer = 0;
        } else
        {
            sum[j] = (char) (buffer - 10 + '0');
            buffer = 1;
        }
    }

    // Residual digit : maxSize
    if (buffer == 1)
    {
        sum[maxSize] = '1';
        maxSize++;
    }

    // test
    cout << sum << endl;

    // Output
    for (int l = 0; l < maxSize; l++)
    {
        cout << sum[maxSize - 1 - l];
    }
    cout << endl;

    return 0;
}
```
</details>
