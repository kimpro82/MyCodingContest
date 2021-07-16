## BAEKJOON Online Judge

## 문제 > 단계별로 풀어보기 > 8. 기본 수학 1
(2021.07.12)  
https://www.acmicpc.net/step/8

※ C++ codes : **skipped** `main()` function's brace(`{}`) and its outside  
&nbsp; - Basically, all the codes has the `<iostream>` header and namespace `std` even if there's no mention.  
&nbsp; - When any additional header is used, the header block is also noted seperately.  


### 1712. 손익분기점

#### C++ 
```cpp
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
```

> 1000 70 170

> 11


### 2292. 벌집

#### C++ 
```cpp
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
```

> 13

> 3


### 1193. 분수찾기

#### C++ 
```cpp
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
```

> 14

> 14 1 1  
> 14 2 3  
> 14 3 6  
> 14 4 10  
> 14 5 15  
> 2/4


### 2869. PUŽ

#### C++ 
```cpp
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
```

> 5 1 6

> 1 5 -1  
> 2 9 3  
> 2


### 10250. ACM Hotel

#### C++ 
```cpp
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
```

> 2  
> 6 12 10  
> 30 50 72

> 402  
> 1203


### 2775. 부녀회장이 될테야

#### C++ 
```cpp
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
```

> 2  
> 1  
> 3  
> 2  
> 3

> 6  
> 10


### 2839. ŠEĆER

#### C++ 
```cpp
int N;
cin >> N;       // 3 <= n <= 5000

int bag3 = 0;
bool rest = true;
for (int i = 0; i <= N / 3; i++)
{
    if ((N - i * 3) % 5 == 0)
    {
        bag3 = i;
        rest = false;
        break;
    }
}

// Test
// cout << bag3 << " " << bag3 * 3 << " " << (N - bag3 * 3) << endl;

// Output
if (rest == false)
{
    cout << bag3 + (N - bag3 * 3) / 5 << endl;
} else
{
    cout << -1 << endl;
}

return 0;
```

> 18

> 4


### 10757. 큰 수 A+B

#### C++ 
```cpp
#include <iostream>
#include <string>
```
```cpp
string a, b;
char sum[10002];
cin >> a >> b;

int aSize = a.size(), bSize = b.size();
int minSize = min(aSize, bSize);
int maxSize = max(aSize, bSize);
int buffer = 0;

// test
// cout << minSize << " " << maxSize << endl;   // 19 19 - OK
```
```cpp
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
```
```cpp
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
```
```cpp
// Residual digit : maxSize
if (buffer == 1)
{
    sum[maxSize] = '1';
    maxSize++;
}

// test
cout << sum << endl;
```
```cpp
// Output
for (int l = 0; l < maxSize; l++)
{
    cout << sum[maxSize - 1 - l];
}
cout << endl;

return 0;
```

> 9223372036854775807 9223372036854775808

> 0 7 8 1 5  
> 1 0 0 0 1  
> ……  
> 18 9 9 1 8  
> 51615590737044764481  
> 18446744073709551615


### 1011. Fly me to the Alpha Centauri

#### C++ - Tral 1
```cpp
#pragma GCC optimize ("O2")
#pragma GCC target ("avx")

#include <iostream>
#include <cmath>
#include<bits/stdc++.h>
```
```cpp
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
```
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

> 3  
> 0 3  
> 1 5  
> 45 50

> 1 1 3 -2  
> 2 2 3 -1  
> 3 4 3 1  
> 3  
> ……

> Time Litmit Exceeded?

#### C++ - Tral 2
```cpp
#pragma GCC optimize ("Ofast")
#pragma GCC target ("avx")

#include <iostream>
#include <cmath>
#include<bits/stdc++.h>

using namespace std;
using ll = long long;
#define endl '\n'
```
```cpp
cin.tie(0);
ios::sync_with_stdio(false);

int T;
cin >> T;

// Test T times
for (int t = 0; t < T; t++)
{
    ll x, y;                            // int x, y : causes SOF!
    cin >> x >> y;

    ll distance = y - x, move = 0;
    int turn = 2 * sqrt(distance) - 2;
    
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
```
```cpp
// n is even : distance = {(n + 1)/2}^2
// → n = 2 * sqrt(distance) - 1
// n is odd  : distance = {(n + 1)^2 - 1}/4
```

> 2 2 3 -1  
> 3 4 3 1  
> 3  
> 3 4 4 0  
> 3  
> 3 4 5 -1  
> 4 6 5 1  
> 4

> Accepted


