## [BAEKJOON Online Judge](/README.md#baekjoon-online-judge)

# 문제 > 단계별로 풀어보기 > 21. 재귀 - (not completed)

(2021.09.15)  

https://www.acmicpc.net/step/19


※ All the `C++` codes **skipped** the below lines. :
```cpp
#include <iostream>

using namespace std;

#define endl '\n'
```
&nbsp;&nbsp;&nbsp;When any additional header is used, the header block is also noted seperately.


## 10872. 팩토리얼

#### C++
(2021.07.27)
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

> 10

> 3628800


## 10870. 피보나치 수 5

#### C++
(2021.07.27)
```cpp
int fibonacci(int n)
{
    if (n == 0) return 0;
    if (n == 1) return 1;

    return fibonacci(n - 1) + fibonacci(n - 2);
}
```
```cpp
int main()
{
    int n;
    cin >> n;

    cout << fibonacci(n) << endl;

    return 0;
}
```

> 10

> 55


## 2447. 별 찍기 - 10

#### C++
(2021.09.15)
```cpp
char star(int r, int c, int n)
{
    if (n <= 3)
    {
        if (r % 3 == 1 && c % 3 == 1) return ' ';
        else return '*';
    }

    if (r / (n / 3) == 1 && c / (n / 3) == 1) return ' ';

    return star(r % (n / 3), c % (n / 3), n / 3);
}
```
```cpp
int main()
{
    int n;
    cin >> n;

    for (int r = 0; r < n; r++)
    {
        for (int c = 0; c < n; c++) cout << star(r, c, n);
        cout << endl;
    }

    return 0;
}
```

> 27

>&nbsp;***************************  
>&nbsp;* ** &nbsp;** ** &nbsp;** &nbsp;** &nbsp;** ** &nbsp;** *  
>&nbsp;***************************  
>&nbsp;*** &nbsp;&nbsp;&nbsp; ****** &nbsp;&nbsp; ****** &nbsp;&nbsp;&nbsp; ***  
>&nbsp;* &nbsp;* &nbsp;&nbsp;&nbsp;* &nbsp;** &nbsp;* &nbsp;&nbsp; * ** * &nbsp;&nbsp;&nbsp; * &nbsp;*  
>&nbsp;*** &nbsp;&nbsp;&nbsp; ****** &nbsp;&nbsp; ****** &nbsp;&nbsp;&nbsp; ***  
>&nbsp;***************************  
>&nbsp;* ** &nbsp;** ** &nbsp;** &nbsp;** &nbsp;** ** &nbsp;** *  
>&nbsp;***************************  
>&nbsp;……


## 11729. 하노이 탑 이동 순서
not completed

#### C++
```cpp
int hanoi()
{
    // need more codes ……
}
```
```cpp
int main()
{
    int n;
    cin >> n;

    int k = pow(2, n) - 1;
    cout << k << endl;

    // need more codes ……

    return 0;
}
```

> 

> 