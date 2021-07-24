## BAEKJOON Online Judge

## 문제 > 단계별로 풀어보기 > 8. 기본 수학 2
(2021.07.20)  
https://www.acmicpc.net/step/10

※ C++ codes : **skipped** `main()` function's brace(`{}`) and its outside  
&nbsp; - Basically, all the codes has the `<iostream>` header and namespace `std` even if there's no mention.  
&nbsp; - When any additional header is used, the header block is also noted seperately.  


### 1978. 소수 찾기

#### C++ 
```cpp
#include <iostream>
#include <vector>
```
```cpp
// Input data
int n;          // n <= 100
cin >> n;
vector<int> v;  // v_i <= 1000
int temp;
for (int i = 0; i < n; i++)
{
    cin >> temp;
    v.push_back(temp);
}

// Determine if each number of v is a prime number
int count = 0, prime;
for (int j = 0; j < n; j++)
{
    if (v[j] == 1) continue;

    prime = 1;
    for (int k = 2; k < v[j]/2 + 1; k++)
    {
        if (v[j] % k  == 0)
        {
            prime = 0;
            break;
        }
    }
    if (prime == 1) count++;

    // test
    cout << j << " " << v[j] << " " << count << endl;
}

// Output
cout << count << endl;

return 0;
```

> 4  
> 1 3 5 7

> 1 3 1  
> 2 5 2  
> 3 7 3  
> 3


### 2581. 소수

#### C++ 
```cpp
// Input data
int m, n;                           // 1 <= m <= n <= 10,000
cin >> m >> n;

// Determine if each number between m and n is a prime number
int sum = 0, min = 10000, prime;
if (m == 1) m++;                    // don't need to consider 1
for (int i = m; i <= n; i++)
{
    prime = 1;

    for (int j = 2; j <= i/2; j++)
    {
        if (i % j  == 0)
        {
            prime = 0;
            break;
        }
    }

    if (prime == 1)
    {
        sum += i;
        if (i < min) min = i;       // enough to operate just once first but ……

        // test
        cout << i << " " << sum << " " << min << endl;
    }
}

// Output
if (sum > 0) cout << sum << '\n' << min << endl;
else cout << -1 << endl;

return 0;
```

> 60  
> 100

> 61 61 61  
> 67 128 61  
> ……  
> 97 620 61  
> 620  
> 61


### 11653. 소인수분해

#### C++ 
```cpp
// Input data
int n;                           // 1 <= n <= 10,000,000
cin >> n;

// Prime factorization
int divisor = 2;
while (n > 1)
{
    if (n % divisor == 0)
    {
        cout << divisor << endl;
        n /= divisor;
    }
    else divisor++;
}

return 0;
```

> 72

> 2  
> 2  
> 2  
> 3  
> 3


### 1929. 소수 구하기

#### C++ 
```cpp
// seems to be needed ……
ios_base::sync_with_stdio(false);
cout.tie(NULL);

// Input data
int m, n;       // 1 <= m <= n <= 1,000,000, guarantee at least one prime number
cin >> m >> n;

// Determine if each number between m and n is a prime number
int prime;
if (m == 1) m++;                    // don't need to consider 1
for (int i = m; i <= n; i++)
{
    prime = 1;

    for (int j = 2; j <= i/j; j++)  // magic to avoid TLE! 
    {
        if (i % j  == 0)
        {
            prime = 0;
            break;
        }
    }

    if (prime == 1) cout << i << endl;
}

return 0;
```

> 3 16

> 3  
> 5  
> 7  
> 11  
> 13


### 4948. Chebyshev's Theorem (베트르랑 공준)

#### C++ 
```cpp
// maybe better than nothing?
ios_base::sync_with_stdio(false);
cout.tie(NULL);

int n;
while (true)
{
    // Input data
    cin >> n;
    if (n == 0) break;

    // Determine if each number between n and 2n is a prime one
    int m = 2 * n, prime, count = 0;
    for (int i = n + 1; i <= m; i++)    // "greater than n and less than or equal to 2n"
    {
        prime = 1;
        for (int j = 2; j <= i/j; j++)  // magic to avoid TLE! 
        {
            if (i % j  == 0)
            {
                prime = 0;
                break;
            }
        }
        if (prime == 1) count++;
    }

    // Output
    cout << count << endl;
}

return 0;
```

> 1  
> 10  
> 13  
> 100  
> 1000  
> 10000  
> 100000  
> 0

> 1  
> 4  
> 3  
> 21  
> 135  
> 1033  
> 8392


### 9020. Goldbach’s Conjecture (골드바흐의 추측)

#### C++ 
```cpp
// maybe better than nothing?
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);

int T;
cin >> T;

// T test cases
for (int t = 0; t < T; t++)
{
    int n, m, prime;
    cin >> n;

    for (int i = n/2; i > 1; i--)
    {
        prime = 1;

        // Find the first prime number
        for (int j = 2; j <= i/j; j++)      // magic to avoid TLE! 
        {
            if (i % j  == 0)
            {
                prime = 0;
                break;
            }
        }

        // Find if (n - i) is also a prime number
        if (prime == 1)
        {
            m = n - i;
            for (int k = 2; k <= m/k; k++)
            {
                if (m % k  == 0)
                {
                    prime = 0;
                    break;
                }
            }
        }

        // When both of the numbers are prime ones
        if (prime == 1)
        {
            cout << i << ' ' << m << endl;
            break;                          // need only once
        }
    } // The end of i loop
} // The end of t loop

return 0;
```

> 3  
> 8  
> 10  
> 16

> 3 5  
> 5 5  
> 5 11


### 1085. 직사각형에서 탈출

#### C++ 
```cpp
int x, y, w, h;
cin >> x >> y >> w >> h;

int minValue;
minValue = min(min(x, w-x), min(y, h-y));

cout << minValue << endl;

return 0;
```

> 6 2 10 3

> 1


### 3009. CETVRTA (네 번째 점)

#### C++ - Trial 1
```cpp
#include <iostream>
#include <map>
```
```cpp
// Input data
map<int, int> x, y;
int temp1, temp2;
for (int i = 0; i < 3; i++)
{
    cin >> temp1 >> temp2;
    x.insert(pair<int, int> (temp1, 1));
    y.insert(pair<int, int> (temp2, 1));
}

// test
map<int, int>::iterator it;
for (it = x.begin(); it != x.end(); it++)
{
    cout << it->first << ' ' << it->second << endl;
}

return 0;
```
> 5 5  
> 5 7  
> 7 5

> 5 1  
> 7 1

#### C++ - Trial 2
```cpp
#include <iostream>
#include <array>
```
```cpp
// Input data
array<int, 1001> x = {0, }, y = {0, };
int temp1, temp2;
for (int i = 0; i < 3; i++)
{
    cin >> temp1 >> temp2;
    x[temp1]++;
    y[temp2]++;
}

// test
for (int j = 1; j <= 1000; j++)
{
    if (x[j] != 0) cout << "x : " << j << ' ' << x[j] << endl;
    if (y[j] != 0) cout << "y : " << j << ' ' << y[j] << endl;
}     

// Find the 4th point
int x4 = 0, y4 = 0;
for (int k = 1; k <= 1000; k++)
{
    if (x[k] == 1) x4 = k;
    if (y[k] == 1) y4 = k;
    if (x4 != 0 && y4 != 0) break;  // a little sincere attitude, not much
}   

// // Output
cout << x4 << ' ' << y4 << endl;

return 0;
```

> x : 5 2  
> y : 5 2  
> x : 7 1  
> y : 7 1  
> 7 7


### 4153. Egypt (직각삼각형)

#### C++ 
```cpp
#include <iostream>
// #include <array>     // not used, but use legacy array
#include <algorithm>    // sort()
#include <cmath>        // pow()
```
```cpp
int arr[3];
// array<int, 3> arr                            // causes crazy compile time error when apply to sort()
while (true)
{
    // Input data
    for (int i = 0; i < 3; i++) cin >> arr[i];
    if (arr[0] == 0) break;                     // enough to check just one line segment

    // Sort : not sure if data will be sorted
    sort(arr, arr + 3);                         // not sort(arr[0], arr[3])

    // Output
    if ((int) pow(arr[0], 2) + (int) pow(arr[1], 2) == (int) pow(arr[2], 2))
    {
        cout << "right" << endl;
    } else
    {
        cout << "wrong" << endl;
    }
}

return 0;
```

> 6 8 10  
> 25 52 60  
> 5 12 13  
> 0 0 0

> right  
> wrong  
> right


### 3053. HERMAN(택시 기하학)

#### C++ 
```cpp
#define _USE_MATH_DEFINES   // for using the exact pi value(M_PI)

#include <iostream>
#include <cmath>            // pow(), M_PI
```
```cpp
int r;
cin >> r;

double euclidian = M_PI * pow(r, 2);            // find the exact value of M_PI : F12 (VS Code)
double taxicab = 2 * pow(r, 2);

cout << fixed;
cout.precision(6);
cout << euclidian << '\n' << taxicab << endl;

return 0;
```

> 21

> 1385.442360  
> 882.000000


### 1002. 터렛

#### C++ 
```cpp
#include <iostream>
#include <cmath>        // pow()
```
```cpp
int T;
cin >> T;

// T Test cases
for (int t = 0; t < T; t++)
{
    // Input data
    int x1, y1, r1, x2, y2, r2;
    cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

    // Find square of distance : sqrt() can cause error
    int distanceSquare = (int) (pow(x2 - x1, 2) + pow(y2 - y1, 2));
    int rangeSquare1 = (int) pow(r1 + r2, 2), rangeSquare2 = (int) pow(r2 - r1, 2);

    // test
    cout << distanceSquare << ' ' << rangeSquare1 << ' ' << rangeSquare2 << endl;

    // Output
    if (distanceSquare == 0 && rangeSquare2 == 0) cout << -1 << endl;   // infinitely cross
    else if (distanceSquare > rangeSquare1 || distanceSquare < rangeSquare2) cout << 0 << endl;
    else if (distanceSquare == rangeSquare1 || distanceSquare == rangeSquare2 ) cout << 1 << endl;
    else cout << 2 << endl;
}

return 0;
```

> 3  
> 0 0 13 40 0 37  
> 0 0 3 0 7 4  
> 1 1 1 1 1 5

> 1600 2500 576  
> 2  
> 49 49 1  
> 1  
> 0 36 16  
> 0