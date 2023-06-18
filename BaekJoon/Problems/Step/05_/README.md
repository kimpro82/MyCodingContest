## [BAEKJOON Online Judge](../../../../README.md#baekjoon-online-judge)

# 문제 > 단계별로 풀어보기 > 5. 함수 (Depreciated)

https://www.acmicpc.net/step/5

(2021.06.18) - `C++`  
(2022.03.11) - `Text`  
(2022.04.17) - `Golang`


## **List**

- [15596. 정수 N개의 합](#15596-정수-n개의-합)
- [4673. Self Numbers](#4673-self-numbers)
- [1065. 한수](#1065-한수)


**※ Note**

&nbsp;&nbsp; - All the codes of any language for the same problem have basically the same result.  
&nbsp;&nbsp; - `C++`* : skipped the below two header lines; `#include <iostream>` `using namespace std;`  
&nbsp;&nbsp; - `Golang`* : skipped the below two header lines; `package main` `import "fmt"`  
&nbsp;&nbsp; - `Text` : Only possible problems that do not require input values are solved.  
&nbsp;&nbsp; * When any additional header is used, the header block is also noted seperately.


## [15596. 정수 N개의 합](#list)

> n   : 5  
> ans : 15

#### C++

I guessed it as a question related with using pointer(because of "&a") at first, but it was not.  
Hell easy one to ask about `vector` very simply.  
It's been a few days with pointer, I hate myself

```cpp
#include <iostream>
#include <vector>
```
```cpp
long long sum(vector<int> &a)
{
    int n = a.size();                   // not sizeof(a) : get length of the memory space
    cout << "n   : " << n << endl;      // test

    long long ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans += a[i];
    }

    cout << "ans : " << ans << endl;    // test
    return ans;
}
```
```cpp
// test
// int main()
// {
//     vector<int> a = {1, 2, 3, 4, 5};
//     sum(a);

//     return 0;
// }
```

#### Golang
```golang
// import "fmt"
```
```golang
func sum(a []int) int {            // int == int64 in 64 bit env.
    var ans int = 0

    for _, el := range a {
        ans += el                  // not a[i] !!!
    }

    return ans
}
```
```golang
// Test
// func main() {
//     a := []int{1, 2, 3, 4, 5}
//     fmt.Println(sum(a))
// }
```


## [4673. Self Numbers](#list)

Deja vu? ☞ [Oncoder Challenge Lv.6](..//Oncoder/Challenge/Q06/README.md)

> 1  
> 3  
> 5  
> ……  
> 9993

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

#### Golang
Hmm it would be better to use *nested If statement* with the order of `num > 9` `num > 99` `num > 999`.
```golang
func digitadition(num int) int {

    var d int = num

    if num > 999 {
        d += num / 1000
    }
    if num > 99 {
        d += (num % 1000) / 100
    }
    if num > 9 {
        d += (num % 100) / 10
    }
    d += num % 10

    return d
}
```
```golang
func main() {

    var n int = 10001                            // n = 101 for test
    
    // Generate an array {1, 2, ……, 9999}
    var arr []int = make([]int, n)
    for i := 1; i < n; i++ {
        arr[i] = 1
    }

    // Remove non-self numbers from the array
    var temp int
    for i := 1; i < n; i++ {
        temp = digitadition(i)
        if temp < n {
            arr[temp] = 0
        }
    }

    // Output
    for i := 1; i < n; i++ {
        if arr[i] == 1 {
            fmt.Println(i)
        }
    }
}
```

#### Text
```txt
1
3
5
……
9993
```
ㅋㅋㅋ


## [1065. 한수](#list)

[한수](https://namu.wiki/w/%ED%95%9C%EC%88%98(%EC%82%BC%EA%B5%AD%EC%A7%80))라면 ……

> 777

> 1 0 0 99  
> 1 0 1 99  
> 1 0 2 99  
> ……  
> 7 7 7 133

> 133

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
            cout << a << " " << b << " " << c << " " << count << endl;  // test
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

#### Golang
```golang
func count(n int) int {
    var ans int = 0;
    var a, b, c int
    if n < 100 {
        ans = n
    } else if n < 1000 {
        ans = 99

        for i := 100; i <= n; i++ {
            a = i / 100
            b = (i % 100) / 10
            c = i % 10

            if b - a == c - b {
                ans++
            }
        }
    } else {                            // n == 1000
        ans = 144                       // crazy~ (given as a sample output)
    }

    return ans
}
```
```golang
func main() {
    var n int;
    fmt.Scanln(&n)

    fmt.Println(count(n))
}
```