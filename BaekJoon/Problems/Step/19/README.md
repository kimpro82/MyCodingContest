## [BAEKJOON Online Judge](/README.md#baekjoon-online-judge)

# 문제 > 단계별로 풀어보기 > 19. 조합론

https://www.acmicpc.net/step/61

- (2023.07.12) - `C++`



## **List**

- [15439. Vera and Outfits(베라의 패션)](#15439-vera-and-outfits베라의-패션)
- [24723. 녹색거탑](#24723-녹색거탑)
- [10872. 팩토리얼](#10872-팩토리얼)
- [11050. 이항 계수 1](#11050-이항-계수-1)
- [1010. 다리 놓기](#1010-다리-놓기)


**※ Note**  

&nbsp;&nbsp; - All the codes of any language for the same problem have basically the same result.  
&nbsp;&nbsp; - Typical headers like the below are basically skipped, but they are noted seperately when theere are any additional line.  
&nbsp;&nbsp;&nbsp;&nbsp; · `C++` : `#include <iostream>` `#define endl '\n';` `using namespace std;`  



## [15439. Vera and Outfits(베라의 패션)](#list)

```txt
5
```
```txt
20
```

<details>
  <summary>Answer : C++ (2023.07.12)</summary>

```cpp
int main()
{
    // Input
    int n;
    cin >> n;

    // Output
    int ans = n * n - n;                                    // do not need to use combination
    cout << ans << endl;

    return 0;
}
```
</details>

> 맞았습니다!!


## [24723. 녹색거탑](#list)

```txt
2
```
```txt
4
```

<details>
  <summary>Answer : C++ (2023.07.12)</summary>

```cpp
int main()
{
    // Input
    int n;
    cin >> n;

    // Operate
    int ans = 1;
    while (n--) ans *= 2;

    // Output
    cout << ans << endl;

    return 0;
}
```
</details>

> 맞았습니다!!


## [10872. 팩토리얼](#list)

```txt
10
```
```txt
3628800
```

<details>
  <summary>Answer : C++ (2021.07.26)</summary>

```cpp
int factorial(int n)
{
    if (n <= 1) return 1;

    return n * factorial(n - 1);
}
```
```cpp
int main()
{
    int N;
    cin >> N;

    cout << factorial(N) << endl;

    return 0;
}
```
</details>

> 맞았습니다!!


## [11050. 이항 계수 1](#list)

```txt
5 2
```
```txt
10
```

<details>
  <summary>Answer : C++ (2023.07.12)</summary>

```cpp
int main()
{
    // Input
    int n, k;
    cin >> n >> k;

    // Operate
    int ans = 1;
    int k2 = k;
    for (int i = 0; i < k; i++) ans *= n--;
    for (int i = 0; i < k2; i++) ans /= k--;

    // Output
    cout << ans << endl;

    return 0;
}
```
</details>

> 맞았습니다!!


## [1010. 다리 놓기](#list)

```txt
3
2 2
1 5
13 29
```
```txt
1
5
67863915
```

<details>
  <summary>Answer : C++ (2023.07.12)</summary>

```cpp
int main()
{
    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        // Input
        int n, m;
        cin >> n >> m;

        // Operate : mCn
        long long ans = 1;
        for (int j = 1; j <= n; j++)                        // j must start from 1, not 0
        {
            ans *= m--;
            ans /= j;
        }

        // Output
        cout << ans << endl;
    }

    return 0;
}
```
</details>

> 맞았습니다!!
