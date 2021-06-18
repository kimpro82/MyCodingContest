## BAEKJOON Online Judge

## 문제 > 단계별로 풀어보기 > 6. 함수 (2021.06.18)
(2021.06.18)  
https://www.acmicpc.net/step/5  

※ C++ codes : **skipped** `main()` function's brace(`{}`) and its outside  
    - Basically, all the codes has the `<iostream>` header and namespace `std` even if there's no mention.  
    - When any additional header is used, the header block is also noted seperately.


### 15596. 정수 N개의 합
I guessed it as a question related with using pointer(because of "&a") at first, but it was not.  
Hell easy one to ask about `vector` very simply.  
It's been a few days with pointer, I hate myself

#### C++ 
```cpp
#include <iostream>
#include <vector>
```
```cpp
long long sum(vector<int> &a)
{
    int n = a.size();               // not sizeof(a) : get length of the memory space
    cout << "n   : " << n << endl;    // test

    long long ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans += a[i];
    }

    cout << "ans : " << ans << endl;        // test
    return ans;
}
```
```cpp
// test
int main()
{
    vector<int> a = {1, 2, 3, 4, 5};
    sum(a);

    return 0;
}
```

> n   : 5  
> ans : 15


### 4673. Self Numbers
Deja vu? ☞ [Oncoder Challenge Lv.6](..//Oncoder/Challenge/Q06/README.md)

#### C++ 
```cpp
#include <iostream>
#include <set>
#include <algorithm>
```
```cpp
int main()
{
    // make a set {1, 2, ……, 9999}
    set<int> mySet;
    for (int i = 1; i < 10000; i++)
    {
        mySet.insert(i);
    }

    // erase digitaditions from mySet{}
    for (int j = 1; j < 10000; j++)
    {
        int digitadition = j;
        if (j > 999)
        {
            digitadition += j / 1000;
        }
        if (j > 99)
        {
            digitadition += (j % 1000) / 100;
        }
        if (j > 9)
        {
            digitadition += (j % 100) / 10;
        }
        digitadition += j % 10;

        mySet.erase(digitadition);
    }

    // output self-numbers
    // make cin/cout faster
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    for_each (mySet.begin(), mySet.end(), [](int n)
    {
        cout << n << '\n';
    });

    return 0;
}
```
```cpp
        // better code?
        int digitadition = j;
        if (j > 999)
        {
            digitadition += j / 1000;
            digitadition += (j % 1000) / 100;
            digitadition += (j % 100) / 10;
        } else if (j > 99)
        {
            digitadition += (j % 1000) / 100;
            digitadition += (j % 100) / 10;
        } else if (j > 9)
        {
            digitadition += (j % 100) / 10;
        }
        digitadition += j % 10;
```

> 1  
> 3  
> 5  
> ……  
> 9993


### 1065. 한수
[한수](https://namu.wiki/w/%ED%95%9C%EC%88%98(%EC%82%BC%EA%B5%AD%EC%A7%80))라면 ……

#### C++ 
```cpp
int main()
{
    int n;      // n <= 1000
    cin >> n;

    int count = 0;
    if (n < 100)
    {
        count = n;
    } else
    {
        int a, b, c;
        count = 99;
        if (n == 1000)      // can determine 1000 is not
        {
            n = 999;
        }
        for (int i = 100; i <= n; i++)
        {
            a = i / 100;
            b = (i % 100) / 10;
            c = i % 10;
            if ((b - a) == (c - b))
            {
                count++;
            }
            // cout << a << " " << b << " " << c << " " << count << endl;  // test
        }
    }

    cout << count << endl;

    return 0;
}
```
```cpp
    // else             // n == 1000
    // {
    //     count = 144; // given as a sample output …… crazy
    // }
```

> 110  
> 99

> 1  
> 1

> 210  
> 105

> 1000  
> 144