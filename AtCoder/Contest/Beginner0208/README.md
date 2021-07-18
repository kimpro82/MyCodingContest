## AtCoder Beginner Contest 208

2021-07-04(Sun) 21:00 - 22:40, 100 minutes  
https://atcoder.jp/contests/abc208

※ All the codes are written in C++  
    - **skipped** `main()` function's brace(`{}`) and its outside  
    - Basically, all the codes has the `<iostream>` header and namespace `std` even if there's no mention.  
    - When any additional header is used, the header block is also noted seperately.


### A - Rolling Dice

```cpp
int a, b;
cin >> a >> b;

if (a * 6 >= b && a <= b)
{
    cout << "Yes" << '\n';
} else
{
    cout << "No" << '\n';
}

return 0;
```

> 2 11

> Yes

> Accepted


### B - Factorial Yen Coin

```cpp
int factorial(int n)
{
    if (n <= 1) return 1;
 
    return n * factorial(n - 1);
}
```
```cpp
int p;
cin >> p;

// Find the largest coin
int pTemp = p, largest = 1;
for (int i = 1; i <= 10; i++)
{
    if (pTemp > 1)
    {
        pTemp /= i;
        largest = i;

        // test
        cout << i << " " << pTemp << '\n';
    } 
    else break;
}

// Count the number of coins needed
int count = 0, coin;
for (int j = largest; j > 0; j--)
{
    if (p >= factorial(j))
    {
        count += p / factorial(j);
    
        // test
        cout << j << " " << p << " " << count << '\n';

        p %= factorial(j);
    }
}

// Output
cout << count << '\n';

return 0;
```

> 10000000

> 1 10000000  
> 2 5000000  
> ……  
> 10 2  
> 10 10000000 2  
> 9 2742400 9  
> ……  
> 2 4 24  
> 24

> Accepted


### Fair Candy Distribution

```cpp
#include <iostream>
#include <vector>
#include <algorithm>    // for sort()

#define endl '\n'

using namespace std;
using ll = long long;
```
```cpp
// Input data
int n;
ll k;
cin >> n >> k;

vector<int> a;                  // a : ID number
int temp;
for (int i = 0; i < n; i++)
{
    cin >> temp;
    a.push_back(temp);
}
```
```cpp
// Allocation 1 : When sweets are more than n
ll base = k / n;
vector<ll> allocation (n, base);
```
```cpp
// Allocation 2 : When allocate sweets to citizens from the smaller ID number
// 2-1 : Rank ID numbers from smaller
vector<int> rank (n, 1);
for (int j = 0; j < n; j++)
{
    for (int l = 0; l < n; l++)
    {
        if (a[j] > a[l]) rank[j]++;
    }
}
// 2-2 : Give one candy more to the higher ranker (<= k & n)
int residual = k % n; 
for (int m = 0; m < n; m++)
{
    if (rank[m] <= residual) allocation[m]++;
}
```
```cpp
// Output
for (int o = 0; o < n; o++) cout << allocation[o] << endl;

return 0;
```

> 7 1000000000000  
> 99 8 2 4 43 5 3

> 142857142857  
> 142857142857  
> 142857142858  
> 142857142857  
> 142857142857  
> 142857142857  
> 142857142857

> Time Limit Exceeded