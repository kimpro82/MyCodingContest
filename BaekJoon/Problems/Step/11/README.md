### [BAEKJOON Online Judge](/README.md#baekjoon-online-judge)

# 문제 > 단계별로 풀어보기 > 11. 시간 복잡도

https://www.acmicpc.net/step/53

(2023.07.04) - `C++`  


### **List**

- [24262. 알고리즘 수업 - 알고리즘의 수행 시간 1](#24262-알고리즘-수업---알고리즘의-수행-시간-1)
- [24263. 알고리즘 수업 - 알고리즘의 수행 시간 2](#24263-알고리즘-수업---알고리즘의-수행-시간-2)
- [24264. 알고리즘 수업 - 알고리즘의 수행 시간 3](#24264-알고리즘-수업---알고리즘의-수행-시간-3)
- [24265. 알고리즘 수업 - 알고리즘의 수행 시간 4](#24265-알고리즘-수업---알고리즘의-수행-시간-4)
- [24266. 알고리즘 수업 - 알고리즘의 수행 시간 5](#24266-알고리즘-수업---알고리즘의-수행-시간-5)
- [24267. 알고리즘 수업 - 알고리즘의 수행 시간 6](#24267-알고리즘-수업---알고리즘의-수행-시간-6)
- [24313. 알고리즘 수업 - 점근적 표기 1](#24313-알고리즘-수업---점근적-표기-1)


**※ Note**

&nbsp;&nbsp; - All the codes of any language for the same problem have basically the same result.  
&nbsp;&nbsp; - Typical headers like the below are basically skipped, but they are noted seperately when there are any additional line.  
&nbsp;&nbsp;&nbsp;&nbsp; · `C++` : `#include <iostream>` `#define endl '\n';` `using namespace std;`  



## [24262. 알고리즘 수업 - 알고리즘의 수행 시간 1](#list)

```txt
1
```
```txt
1
0
```

#### C++ - Trial 1(2023.07.04)
```cpp
int MenOfPassion(int *n)
{
    if (*n == 0) return 0;

    int temp = *n / 2;
    if (temp > 3) temp = 4;

    // Output
    cout << temp << endl;

    return MenOfPassion(&temp);
}
```
```cpp
int main()
{
    // Input
    int n;
    cin >> n;

    // Operate
    MenOfPassion(&n);

    return 0;
}
```
> 틀렸습니다

#### C++ - Trial 2 (2023.07.04)
```cpp
int main()
{
    // Input
    int n;
    cin >> n;

    // Output
    cout << 1 << endl;
    cout << 0 << endl;

    return 0;
}
```


## [24263. 알고리즘 수업 - 알고리즘의 수행 시간 2](#list)

```txt
7
```
```txt
7
1
```

#### C++ (2023.07.04)
```cpp
int main()
{
    // Input
    int n;
    cin >> n;

    // Output
    cout << n << endl;
    cout << 1 << endl;

    return 0;
}
```


## [24264. 알고리즘 수업 - 알고리즘의 수행 시간 3](#list)

```txt
7
```
```txt
49
2
```

#### C++ (2023.07.04)
```cpp
int main()
{
    // Input
    long long n;
    cin >> n;

    // Output
    cout << (long long) n * n << endl;
    cout << 2 << endl;

    return 0;
}
```


## [24265. 알고리즘 수업 - 알고리즘의 수행 시간 4](#list)

```txt
7
```
```txt
21
2
```

#### C++ (2023.07.04)
```cpp
int main()
{
    // Input
    long long n;
    cin >> n;

    // Operate
    long long cnt = 0;
    for (int i = 1; i < n; i++) for (int j = i + 1; j <= n; j++) cnt++;

    // Output
    cout << cnt << endl;
    cout << 2 << endl;

    return 0;
}
```


## [24266. 알고리즘 수업 - 알고리즘의 수행 시간 5](#list)

```txt
7
```
```txt
343
3
```

#### C++ (2023.07.04)
```cpp
int main()
{
    // Input
    long long n;
    cin >> n;

    // Output
    cout << (long long) n * n * n << endl;
    cout << 3 << endl;

    return 0;
}
```


## [24267. 알고리즘 수업 - 알고리즘의 수행 시간 6](#list)

```txt
7
```
```txt
35
3
```

#### C++ (2023.07.04)
```cpp
// #define test
```
```cpp
int main()
{
    // Input
    long long n;
    cin >> n;

    // Operate : Trial 1 - Time Limit Exceeded
    // long long cnt = 0;
    // for (int i = 1; i <= n - 2; i++)
    // {
    //     for (int j = i + 1; j <= n - 1; j++)
    //     {
    //         for (int k = j + 1; k <= n; k++)
    //         {
    //             cnt++;

    //             #ifdef test
    //                 printf("%d %d %d\n", i, j, k);
    //             #endif
    //         }
    //     }
    // }

    // Operate : Trial 2
    long long cnt = 0;
    for (int i = 1; i <= n - 2; i++)
    {
        cnt += (n - i - 1) * (n - i) / 2;

        #ifdef test
            printf("%d %d\n", i, cnt);
        #endif
    }

    // Output
    cout << cnt << endl;
    cout << 3 << endl;

    return 0;
}
```


## [24313. 알고리즘 수업 - 점근적 표기 1](#list)

```txt
7 7
8
10
```
```txt
35
1
```

#### C++ (2023.07.04)
```cpp
int main()
{
    // Input
    int a1, a0, c, n0;
    cin >> a1 >> a0 >> c >> n0;

    // Output
    int ans = 0;
    if (a1 <= c && a1 * n0 + a0 <= c * n0 ) ans = 1;
    cout << ans << endl;

    return 0;
}
```
