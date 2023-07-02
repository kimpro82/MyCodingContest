## [BAEKJOON Online Judge](/README.md#baekjoon-online-judge)

# 문제 > 단계별로 풀어보기 > 9. 일반 수학 2 : 약수, 배수와 소수

https://www.acmicpc.net/step/10

(2021.07.19, 2023.07.02) - `C++`  


## **List**

- [5086. Factors And Multiples(배수와 약수)](#5086-factors-and-multiples배수와-약수) *(new)*
- [2501. 약수 구하기](#2501-약수-구하기) *(new)*
- [9506. Federation Favorites(약수들의 합)](#9506-federation-favorites약수들의-합) *(new)*
- [1978. 소수 찾기](#1978-소수-찾기)
- [2581. 소수](#2581-소수)
- [11653. 소인수분해](#11653-소인수분해)

#### (Depreciated)
- [1929. 소수 구하기](#1929-소수-구하기)
- [4948. Chebyshev's Theorem(베트르랑 공준)](#4948-chebyshevs-theorem베트르랑-공준)
- [9020. Goldbach’s Conjecture(골드바흐의 추측)](#9020-goldbachs-conjecture골드바흐의-추측)
- [1085. 직사각형에서 탈출](#1085-직사각형에서-탈출)
- [3009. CETVRTA(네 번째 점)](#3009-cetvrta네-번째-점)
- [4153. Egypt(직각삼각형)](#4153-egypt직각삼각형)
- [3053. HERMAN(택시 기하학)](#3053-herman택시-기하학)
- [1002. 터렛](#1002-터렛)


**※ Note**

&nbsp;&nbsp; - All the codes of any language for the same problem have basically the same result.  
&nbsp;&nbsp; - Typical headers like the below are basically skipped, but they are noted seperately when there are any additional line.  
&nbsp;&nbsp;&nbsp;&nbsp; · `C++` : `#include <iostream>` `#define endl '\n';` `using namespace std;`  



## [5086. Factors And Multiples(배수와 약수)](#list)

```txt
8 16
32 4
17 5
0 0
```
```txt
factor
multiple
neither
```

#### C++ (2023.07.02)
```cpp
int main()
{
    int a, b;
    while (true)
    {
        // Input
        cin >> a >> b;

        if (a == 0 && b == 0) break;
        else if (a < b && b % a == 0) cout << "factor" << endl;
        else if (a > b && a % b == 0) cout << "multiple" << endl;
        else cout << "neither" << endl;
    }

    return 0;
}
```


## [2501. 약수 구하기](#list)

```txt
6 3
```
```txt
3
```

#### C++ (2023.07.02)
```cpp
int main()
{
    int a, b;

    // Input
    cin >> a >> b;

    int cnt = 0;
    for (int i = 1; i <= a; i++)
    {
        if (a % i == 0)
        {
            cnt++;

            // Test
            #ifdef test
                printf("i:%d remainder:%d cnt:%d\n", i, a%i, cnt);
            #endif

            // Operate and Output
            if (cnt == b)
            {
                cout << i << endl;
                return 0;
            }
        }
    }

    cout << 0 << endl;
    return 0;
}
```


## [9506. Federation Favorites(약수들의 합)](#list)

```txt
6
12
28
-1
```
```txt
6 = 1 + 2 + 3
12 is NOT perfect.
28 = 1 + 2 + 4 + 7 + 14
```

#### C++ (2023.07.02)
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
    while (true)
    {
        // Input
        int n;
        cin >> n;
        if (n == -1) break;

        // Operate
        vector<int> v;
        int sum = 0;
        for (int i = 1; i <= n/2; i++)
        {
            if (n % i == 0)
            {
                v.push_back(i);
                sum += i;
            }

            if (n < sum) break;
        }

        // Output
        if (sum == n)
        {
            cout << n << " = 1";
            for (int i = 1; i < v.size(); i++) cout << " + " << v[i];
        }
        else cout << n << " is NOT perfect.";
        cout << endl;
    }

    return 0;
}
```


## [1978. 소수 찾기](#list)

> 4  
> 1 3 5 7

> 1 3 1  
> 2 5 2  
> 3 7 3  
> 3

#### C++ (2021.07.19)
```cpp
#include <iostream>
#include <vector>

using namespace std;
#define endl '\n'
```
```cpp
int main()
{
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
}
```


## [2581. 소수](#list)

> 60  
> 100

> 61 61 61  
> 67 128 61  
> ……  
> 97 620 61  
> 620  
> 61

#### C++ (2021.07.19)
```cpp
int main()
{
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
}
```


## [11653. 소인수분해](#list)

> 72

> 2  
> 2  
> 2  
> 3  
> 3

#### C++ (2021.07.19)
```cpp
int main()
{
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
}
```


## [1929. 소수 구하기](#list)

> 3 16

> 3  
> 5  
> 7  
> 11  
> 13

#### C++ (2021.07.19)
```cpp
int main()
{
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
}
```


## [4948. Chebyshev's Theorem(베트르랑 공준)](#list)

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

#### C++ (2021.07.19)
```cpp
int main()
{
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
}
```


## [9020. Goldbach’s Conjecture(골드바흐의 추측)](#list)

> 3  
> 8  
> 10  
> 16

> 3 5  
> 5 5  
> 5 11

#### C++ (2021.07.19)
```cpp
int main()
{
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
}
```


## [1085. 직사각형에서 탈출](#list)

> 6 2 10 3

> 1

#### C++ (2021.07.19)
```cpp
int main()
{
    int x, y, w, h;
    cin >> x >> y >> w >> h;

    int minValue;
    minValue = min(min(x, w-x), min(y, h-y));

    cout << minValue << endl;

    return 0;
}
```


## [3009. CETVRTA(네 번째 점)](#list)

> 5 5  
> 5 7  
> 7 5

> 7 7

#### C++ - Trial 1 (2021.07.20)
```cpp
#include <iostream>
#include <map>

using namespace std;
#define endl '\n'
```
```cpp
int main()
{
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
}
```
> 5 5  
> 5 7  
> 7 5

> 5 1  
> 7 1

#### C++ - Trial 2 (2021.07.20)
```cpp
#include <iostream>
#include <array>

using namespace std;
#define endl '\n'
```
```cpp
int main()
{
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
}
```
> x : 5 2  
> y : 5 2  
> x : 7 1  
> y : 7 1  
> 7 7


## [4153. Egypt(직각삼각형)](#list)

> 6 8 10  
> 25 52 60  
> 5 12 13  
> 0 0 0

> right  
> wrong  
> right

#### C++ (2021.07.20)
```cpp
#include <iostream>
// #include <array>     // not used, but use legacy array
#include <algorithm>    // sort()
#include <cmath>        // pow()

using namespace std;
#define endl '\n'
```
```cpp
int main()
{
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
}
```


## [3053. HERMAN(택시 기하학)](#list)

> 21

> 1385.442360  
> 882.000000

#### C++ (2021.07.20)
```cpp
#define _USE_MATH_DEFINES   // for using the exact pi value(M_PI)

#include <iostream>
#include <cmath>            // pow(), M_PI

using namespace std;
#define endl '\n'
```
```cpp
int main()
{
    int r;
    cin >> r;

    double euclidian = M_PI * pow(r, 2);            // find the exact value of M_PI : F12 (VS Code)
    double taxicab = 2 * pow(r, 2);

    cout << fixed;
    cout.precision(6);
    cout << euclidian << '\n' << taxicab << endl;

    return 0;
}
```


## [1002. 터렛](#list)

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

#### C++ (2021.07.20)
```cpp
#include <iostream>
#include <cmath>        // pow()

using namespace std;
#define endl '\n'
```
```cpp
int main()
{
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
}
```
