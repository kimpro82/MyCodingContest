## [BAEKJOON Online Judge](/README.md#baekjoon-online-judge)

# 문제 > 단계별로 풀어보기 > 15. 약수, 배수와 소수 2

https://www.acmicpc.net/step/18

- (2023.07.11) - `C++`



## **List**

- [1934. 최소공배수](#1934-최소공배수)
- [13241. LCM(최소공배수)](#13241-lcm최소공배수)
- [1735. 분수 합](#1735-분수-합)
- [2485. 가로수](#2485-가로수)
- [4134. Next Prime(다음 소수)](#4134-next-prime다음-소수)
- [1929. 소수 구하기](#1929-소수-구하기)
- [4948. Chebyshev's Theorem(베트르랑 공준)](#4948-chebyshevs-theorem베트르랑-공준)
- [17103. 골드바흐 파티션](#17103-골드바흐-파티션)
- [13909. 창문 닫기](#13909-창문-닫기)


**※ Note**  

&nbsp;&nbsp; - All the codes of any language for the same problem have basically the same result.  
&nbsp;&nbsp; - Typical headers like the below are basically skipped, but they are noted seperately when theere are any additional line.  
&nbsp;&nbsp;&nbsp;&nbsp; · `C++` : `#include <iostream>` `#define endl '\n';` `using namespace std;`  



## [1934. 최소공배수](#list)

```txt
3
1 45000
6 10
13 17
```
```txt
45000
30
221
```

<details>
  <summary>Answer : C++ (2023.07.09)</summary>

```cpp
……
#include <cmath>
……
```
```cpp
int main()
{
    // Input
    int t;
    cin >> t;

    int a, b, Max, Min, prod, ans;
    for (int i = 0; i < t; i++)
    {
        cin >> a >> b;                                      // a, b <= 45,000 → a * b < 2.1b
        Max = max(a, b);
        Min = min(a, b);
        prod = a * b;
        ans = Max;

        // Operate
        while (ans < prod)
        {
            if (ans % Min == 0) break;
            ans += Max;
        }

        // Output
        cout << ans << endl;
    }

    return 0;
}
```
</details>
> 맞았습니다!!


## [13241. LCM(최소공배수)](#list)

```txt
121 199
```
```txt
24079
```

<details>
  <summary>Answer : C++ (2023.07.09)</summary>

```cpp
……
#include <cmath>

……
using ll = long long;
```
```cpp
int main()
{
    // Input
    ll a, b, Max, Min, prod, ans;
    cin >> a >> b;
    Max = max(a, b);
    Min = min(a, b);
    prod = a * b;
    ans = Max;

    // Operate
    while (ans < prod)
    {
        if (ans % Min == 0) break;
        ans += Max;
    }

    // Output
    cout << ans << endl;

    return 0;
}
```
</details>
> 맞았습니다!!


## [1735. 분수 합](#list)

```txt
2 7
3 5
```
```txt
31 35
```

<details>
  <summary>Answer : C++ - Trial 1 (2023.07.09)</summary>

```cpp
……
#include <cmath>
……
```
```cpp
int main()
{
    // Input
    int a, b, c, d, Max, Min, prod, den;
    cin >> a >> b >> c >> d;
    Max = max(b, d);
    Min = min(b, d);
    prod = b * d;
    den = Max;

    // Operate 1 : Get the common denominator
    while (den < prod)
    {
        if (den % Min == 0) break;
        den += Max;
    }

    // Operate 2 : Get the numerator
    int num = a * (den / b) + c * (den / d);

    // Operate 3 : Convert it as an irreducible fraction
    int gcd = den;                                       // Trial 1 : maybe not the best efficient way but enough to solve in 1 sec.
    while (gcd > 1)
    {
        if (num % gcd == 0 && den % gcd == 0) break;
        else gcd--;
    }

    // Output
    cout << num / gcd << ' ' << den / gcd << endl;

    return 0;
}
```
</details>
> 맞았습니다!! (908 ms)

<details>
  <summary>Answer : C++ - Trial 2 (2023.07.09)</summary>

```cpp
int main()
{
    ……

    // Operate 3 : Convert it as an irreducible fraction
    ……
    while (gcd > 1)
    {
        if ……
        else if (gcd == den) gcd = den / 2;              // Trial 2 : added because of my minimum conscience
        else ……
    }

    ……
}
```
</details>
> 맞았습니다!! (516 ms)


<details>
  <summary>Answer : C++ - Trial 3 (2023.07.09)</summary>

```cpp
int gcdf(int a, int b)                                      // Trial 3 : Euclidean algorithm
{
    int c;
    while (b)
    {
        c = a % b;
        a = b;
        b = c;
    }

    return a;
}
```
```cpp
int main()
{
    ……

    // Operate 3 : Convert it as an irreducible fraction
    ……
    int gcd = gcdf(num, den);                               // Trial 3

    ……
}
```
</details>
> 맞았습니다!! (0 ms)


## [2485. 가로수](#list)

```txt
4
2
6
12
18
```
```txt
5
```

<details>
  <summary>Answer : C++ - Trial 1 (2023.07.09)</summary>

```cpp
……
#include <vector>
#include <algorithm>
……
```
```cpp
int main()
{
    int n;
    cin >> n;

    // Input & Operate 1 : Find the shortest distance
    vector<int> v;
    int dist = 1000000000;
    int temp;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        v.push_back(temp);

        if (i > 0 && v[i] - v[i-1] < dist) dist = v[i] - v[i-1];
    }

    // Operate 2 : Count trees newly planted
    int ans = 0;
    int loc = v[0];
    while (loc < v[n-1])
    {
        loc += dist;
        if (binary_search(v.begin(), v.end(), loc)) continue;
        else ans++;
    }

    // Output
    cout << ans << endl;

    return 0;
}
```
</details>
> WA (not submitted)

<details>
  <summary>Answer : C++ - Trial 2 (2023.07.10)</summary>

```cpp
// #define test
```
```cpp
int gcdf(int a, int b)
{
    int c;
    while (b)
    {
        c = a % b;
        a = b;
        b = c;
    }

    return a;
}
```
```cpp
int main()
{
    ……

    // Input & Operate 1 : Find the shortest distance as GCD
    ……
    int gcd, temp;
    for (int i = 0; i < n; i++)
    {
        ……

        if (i == 1 ) gcd = v[1] - v[0];
        else if (i > 1) gcd = gcdf(gcd, v[i] - v[i-1]);

        #ifdef test
            if (i > 0) printf("i:%d gcd:%d\n", i, gcd);
        #endif
    }

    // Operate 2 : Count trees newly planted
    ……
    while (loc < v[n-1])
    {
        loc += gcd;
        ……
    }

    ……
}
```
</details>
> 시간 초과

<details>
  <summary>Answer : C++ - Trial 3 (2023.07.10)</summary>

```cpp
……
#include <set>
……
```
```cpp
int main()
{
    ……

    // Input & Operate 1 : Find the distances by a set
    ……
    set<int> dists;
    int temp;
    for (int i = 0; i < n; i++)
    {
        ……

        if (i > 0 ) dists.insert(v[i] - v[i-1]);
    }

    // Operate 2 : Find the GCD in a vector converted from the set
    vector<int> vDists;
    for (auto it = dists.begin(); it != dists.end(); it++) vDists.push_back(*it);
    int gcd = vDists[0];
    for (int i = 1; i < vDists.size(); i++)
    {
        int temp = gcdf(vDists[i], vDists[i-1]);
        if (temp < gcd) gcd = temp;

        #ifdef test
            printf("i:%d temp:%d gcd:%d\n", i, temp, gcd);
        #endif
    }

    // Output : Do not need to use loop
    #ifdef test
        printf("range:%d range/gcd:%d\n", v[v.size()-1] - v[0], (v[v.size()-1] - v[0]) / gcd);
    #endif
    int ans = (v[v.size()-1] - v[0]) / gcd - (v.size() - 1);
    cout << ans << endl;

    ……
}
```
</details>
> 맞았습니다!!


## [4134. Next Prime(다음 소수)](#list)

```txt
3
6
20
100
```
```txt
7
23
101
```

<details>
  <summary>Answer : C++ (2023.07.11)</summary>

```cpp
……
#include <cmath>

……
using ll = long long;
```
```cpp
int main()
{
    ll t;
    cin >> t;

    ll n, nSqrt;
    for (ll i = 0; i < t; i++)
    {
        cin >> n;
        n = max(n, ll(2));                                  // max(ll, int) causes an error

        while (true)
        {
            bool isPrime = true;
            nSqrt = ll(sqrt(n)) + 1;
            for (ll j = 2; j < nSqrt; j++)
            {
                if (n % j == 0)
                {
                    isPrime = false;
                    break;
                }
            }

            if (isPrime == true)
            {
                cout << n << endl;
                break;
            }
            else n++;
        }
    }

    return 0;
}
```
</details>
> 맞았습니다!!


## [1929. 소수 구하기](#list)

> 3 16

> 3  
> 5  
> 7  
> 11  
> 13

<details>
  <summary>Answer : C++ (2021.07.19)</summary>

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
</details>
> 맞았습니다!!


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

<details>
  <summary>Answer : C++ (2021.07.19)</summary>

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
</details>
> 맞았습니다!!


## [17103. 골드바흐 파티션](#list)

```txt
5
6
8
10
12
100
```
```txt
1
1
2
1
6
```

<details>
  <summary>Answer : C++ - Trial 1 (2023.07.10)</summary>

```cpp
……
#include <cmath>

#define test
……
```
```cpp
int main()
{
    int t;
    cin >> t;

    int n;
    for (int i = 0; i < t; i++)
    {
        cin >> n;

        int cnt = 0;
        for (int j = 2; j <= n / 2; j++)
        {
            // Get a as a prime number
            bool aIsPrime = true;
            for (int k = 2; k <= int(sqrt(j)); k++)
            {
                if (j % k == 0)
                {
                    aIsPrime = false;
                    break;
                }
            }

            // Run only when a is a prime number
            if (aIsPrime == true)
            {
                int a = j;
                int b = n - j;

                // Get b as a prime number
                bool bIsPrime = true;
                for (int k = 2; k <= int(sqrt(b)); k++)
                {
                    if (b % k == 0)
                    {
                        bIsPrime = false;
                        break;
                    }
                }

                // Do cnt++ when a and b both are prime numbers
                if (bIsPrime == true)
                {
                    cnt++;

                    #ifdef test
                        printf("a:%d b:%d cnt:%d\n", a, b, cnt);
                    #endif
                }
            }
        }

        cout << cnt << endl;
    }

    return 0;
}
```
</details>
> 시간 초과

<details>
  <summary>Answer : C++ - Trial 2 (2023.07.10)</summary>

```cpp
……
#include <set>
……
```
```cpp
void getPn(set<int>* pn)
{
    for (int i = 2; i < 1000000; i++)
    {
        bool isPrime = true;
        for (int j = 2; j <= int(sqrt(i)); j++)
        {
            if (i % j == 0)
            {
                isPrime = false;
                break;
            }
        }

        if (isPrime == true) (*pn).insert(i);
    }
}
```
```cpp
int main()
{
    // First, get a set of prime numbers between 2 and 1m
    set<int> pn;
    getPn(&pn);

    ……

    ……
    for (int i = 0; i < t; i++)
    {
        ……

        // Count when `j` and `j - n` both exist
        ……
        for (int j = 2; j <= n / 2; j++)
        {
            if (pn.find(j) != pn.end() && pn.find(n - j) != pn.end()) cnt++;
        }

        ……
    }

    return 0;
}
```
</details>
> 시간 초과

<details>
  <summary>Answer : C++ - Trial 3 (2023.07.10)</summary>

```cpp
……
#include <vector>
#include <algorithm>
```
```cpp
// Use the sieve of Eratosthenes
void eratos(vector<int>* v, vector<int>* pn, const int* NUM)
{
    for (int i = 2; i <= *NUM; i++)
    {
        if ((*v)[i] == 1)
        {
            (*pn).push_back(i);

            #ifdef test
                cout << i << ' ';
            #endif

            for (int j = i; j <= *NUM; j += i) (*v)[j] = 0;                     // run only when i is a prime number
        }
    }

    #ifdef test
        cout << endl;
    #endif
}
```
```cpp
int main()
{
    // First, get a sorted vector of prime numbers between 2 and 1m
    #ifdef test
        const int NUM = 100;
    #else
        const int NUM = 1000000;
    #endif
    vector<int> v(NUM + 1, 1);
    vector<int> pn;
    eratos(&v, &pn, &NUM);

    ……

    ……
    for (int i = 0; i < t; i++)
    {
        ……

        ……
        for (int j = 2; j <= n / 2; j++)
        {
            if (binary_search(pn.begin(), pn.end(), j) && binary_search(pn.begin(), pn.end(), n - j))
            {
                cnt++;

                #ifdef test
                    printf("a:%d b:%d cnt:%d\n", j, n - j, cnt);
                #endif
            }
        }

        ……
    }

    ……
}
```
</details>
> 시간 초과

<details>
  <summary>Answer : C++ - Trial 4 (2023.07.11)</summary>

```cpp
// Use the sieve of Eratosthenes
void eratos(int* vPtr, vector<int>* pn, const int* NUM)
{
    for (int i = 2; i <= *NUM; i++)
    {
        if (vPtr[i] == 1)
        {
            ……

            for (int j = i; j <= *NUM; j += i) vPtr[j] = 0;                     // run only when i is a prime number
        }
    }

    ……
}
```
```cpp
int main()
{
    // First, get a sorted vector of prime numbers between 2 and 1m
    #ifdef ……
    #else
        const int NUM = 1'000'000;                                              // add digit separators
    #endif
    ……
    int* vPtr = v.data();                                                       // declare pointer for v
    ……
    eratos(vPtr, &pn, &NUM);

    ……
}
```
</details>
> 시간 초과

<details>
  <summary>Answer : C++ - Trial 5 (2023.07.11)</summary>

```cpp
// Use the sieve of Eratosthenes
void eratos(int* vPtr, const int* NUM)
{
    for (int i = 2; i <= *NUM; i++)
    {
        if (vPtr[i] == 1)
        {
            ……

            for (int j = i + i; j <= *NUM; j += i) vPtr[j] = 0;                 // run only when i is a prime number
        }
    }

    ……
}
```
```cpp
int main()
{
    // First, get a sorted vector of prime numbers between 2 and 1m
    ……
    eratos(vPtr, &NUM);

    ……

    ……
    for (int i = 0; i < t; i++)
    {
        cin >> n;

        // Count when `j` and `j - n` both exist
        ……
        for (int j = 2; j <= n / 2; j++)
        {
            if (v[j] == 1 && v[n-j] == 1)                                       // O(n * log_n) → O(n) : It was binary search that was the criminal!
            ……
        }

        ……
    }

    ……
}
```
</details>
> 맞았습니다!!


## [13909. 창문 닫기](#list)

```txt
24
```
```txt
4
```

<details>
  <summary>Answer : C++ - Trial 1 (2023.07.11)</summary>

```cpp
……
#include <vector>
#include <algorithm>

// #define test
……
```
```cpp
// Use some similiar algorithm with the sieve of Eratosthenes
void kindOfEratos(int* n, vector<bool>* v)
{
    for (int i = 1; i <= *n; i++)
    {
        for (int j = i; j <= *n; j += i) (*v)[j] = !(*v)[j];
    }
}
```
```cpp
int main()
{
    int n;
    cin >> n;

    // Operate 1 : Open and close the windows
    vector<bool> win(n + 1, false);
    kindOfEratos(&n, &win);

    // Operate 2 : Count the opened windows
    int cnt = 0;
    for (auto it = win.begin(); it != win.end(); it++)
    {
        if (*it == true) cnt++;

        #ifdef test
            cout << int(*it) << ' ';
        #endif
    }
    #ifdef test
        cout << endl;
    #endif

    // Output
    cout << cnt << endl;

    return 0;
}
```
</details>
> 메모리 초과

<details>
  <summary>Answer : C++ - Trial 2 (2023.07.11)</summary>

```cpp
……
// #include <vector>
……
```
```cpp
// // Use some similiar algorithm with the sieve of Eratosthenes → It causes MLE (2.1B Bit ≒ 262.5 MB)
// void kindOfEratos(int* n, vector<bool>* v)
// {
//     for (int i = 1; i <= *n; i++)
//     {
//         for (int j = i; j <= *n; j += i) (*v)[j] = !(*v)[j];
//     }
// }
```
```cpp
int main()
{
    int n;
    cin >> n;

    // // Operate 1 : Open and close the windows            // not needed
    // vector<bool> win(n + 1, false);
    // kindOfEratos(&n, &win);

    // Operate 2 : Count the opened windows
    // int cnt = 0;
    // for (int i = 1; i < win.size(); i++)
    // {
    //     if (win[i] == 1)
    //     {
    //         cnt++;

    //         #ifdef test
    //             cout << i << ' ';                        // 1 4 9 16 ……
    //         #endif
    //     }
    // }
    // #ifdef test
    //     cout << endl;
    // #endif

    int cnt = 0, i = 1;
    while (i * i <= n)
    {
        cnt++;
        i++;
    }

    ……
}
```
</details>
> 맞았습니다!!
