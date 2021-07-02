## AtCoder Beginner Contest 206

2021-06-19(Sat) 21:00 - 22:40, 100 minutes  
https://atcoder.jp/contests/abc206

※ All the codes are written in C++  
    - **skipped** `main()` function's brace(`{}`) and its outside  
    - Basically, all the codes has the `<iostream>` header and namespace `std` even if there's no mention.  
    - When any additional header is used, the header block is also noted seperately.



### A - Maxi-Buying

```cpp
int n;
cin >> n;

int price = int (n * 1.08);     // price : n + 8% tax
cout << price << endl;          // test

if (price < 206)
{
    cout << "Yay!" << endl;
} else if (price == 206)
{
    cout << "so-so" << endl;
} else
{
    cout << ":(" << endl;
}

return 0;
```

> 191

> 206  
> so-so

> Accepted



### B - Savings

```cpp
int n;              // 1 <= n <= 10^9
cin >> n;

int x = 0, sum = 0;
do {
    x++;
    sum += x;
}
while (sum < n);

cout << x << endl;

return 0;
```

> 100128

> 447

> Accepted



### C - Swappable


#### Trial 1

```cpp
int n;
cin >> n;

int a[n];
for (int k = 0; k < n; k++)
{
    cin >> a[k];
}

long long count = 0;
for (int i = 1; i <= n-1; i++)
{
    for (int j = i+1; j <= n; j++)
    {
        if (a[i-1] != a[j-1])
        {
            count++;
        }
    }
}

cout << count << endl;

return 0;
```

> 20  
> 7 8 1 1 4 9 9 6 8 2 4 1 1 9 5 5 5 3 6 4

> 173

> Time Limit Exceeded


#### Trial 2

```cpp
#include <iostream>
#include <vector>
#include <algorithm>    // for using sort()
```

```cpp
int n;
cin >> n;

// input data to a vector
vector<int> a(n);
for (int i = 0; i < n; i++)
{
    cin >> a[i];
}

// sort the vector
sort(a.begin(), a.end());

// count
long long count = 0, sameNum = 1, remainedNum = (long long) n;
for (int j = 1; j <= n-1; j++)
{
    remainedNum--;
    if (a[j-1] == a[j])
    {
        sameNum++;
    } else
    {
        count += sameNum * remainedNum;
        sameNum = 1;
    }

    // test
    cout << j << " " << sameNum << " " << remainedNum << " " << count << endl;
}

// output
cout << count << endl;

return 0;
```

> Accepted (Exec Time : 109 ms, Memory : 4204 KB)


#### Trial 2-1

Refer to :  
https://atcoder.jp/contests/abc206/submissions/23630035  
https://justicehui.github.io/etc/2019/08/29/Optimization/  
https://namu.wiki/w/고급%20벡터%20확장

Added codes :

```cpp
#pragma GCC optimize ("O2")
#pragma GCC target ("avx")
```

```cpp
cin.tie(0);
ios::sync_with_stdio(false);
```

> Accepted (Exec Time : 53 ms, Memory : 4440 KB)

Amazing!



### D - KAIBUNsyo

```cpp
#include <iostream>
#include <set>
```

```cpp
int n;
cin >> n;

int a[n];
for (int k = 0; k < n; k++)
{
    cin >> a[k];
}

set<int> numToChange;
for (int i = 1; i <= (n+1)/2; i++)
{
    if (a[i-1] != a[n-i])
    {
        numToChange.insert(a[i-1]);
        numToChange.insert(a[n-i]); 
        cout << i-1 << " " << a[i-1] << " " << n-i << " " << a[n-i]
            << " " << numToChange.size() << endl;                   // test 
    }
}
if (numToChange.empty())
{
    cout << 0 << endl;
}
else
{
    cout << numToChange.size()-1 << endl;
}

return 0;
```

> 7  
> 1 2 3 4 1 2 3

> 1

> Wrong Answer