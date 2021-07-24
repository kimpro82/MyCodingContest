## AtCoder Beginner Contest 210

2021-07-17(Sat) 21:00 - 22:40, 100 minutes  
https://atcoder.jp/contests/abc210

※ All the codes are written in C++  
    - **skipped** `main()` function's brace(`{}`) and its outside  
    - Basically, all the codes has the `<iostream>` header and namespace `std` even if there's no mention.  
    - When any additional header is used, the header block is also noted seperately.



### A - Cabbages

```cpp
int n, a, x, y, sum;
cin >> n >> a >> x >> y;

if (n > a) sum = a * x + (n - a) * y;
else sum = n * x;

cout << sum << endl;

return 0;
```

> 5 3 20 15

> 90

> Accepted


### B - Bouzu Mekuri

```cpp
int n;
string s;

cin >> n;
cin >> s;

// Find the first 1's index
int index = s.find('1');

// test
cout << index << endl;

// Output
if (index % 2 == 0) cout << "Takahashi" << endl;
else cout << "Aoki" << endl;

return 0;
```
> 5  
> 00101

> Takahashi

> Accepted


### C - Colorful Candies

```cpp
#pragma GCC optimize ("O2")
#pragma GCC target ("avx")

#include <iostream>
#include <vector>
#include <set>
#include <bits/stdc++.h>
```
```cpp
cin.tie(0);
ios::sync_with_stdio(false);

// Input data
int n, k;
cin >> n >> k;
vector<int> c;
int temp;
for (int i = 0; i < n; i++)
{
    cin >> temp;
    c.push_back(temp);
}

// Find the most various subset's starting index of length k
set<int> s;
int max = 0, sSize;
int index = 1;                                      // test
for (int j = 0; j < n - k + 1; j++)
{
    s = {};
    for (int l = 0; l < k; l++) s.insert(c[j+l]);
    sSize = s.size();
    if (sSize == k)
    {
        max = sSize;
        break;
    } else if (sSize > max)
    {
        max = sSize;
        index = j;                                  // test
    }
}

// Output
cout << max << endl;

// test
for (int m = index; m < index + k; m++)
{
    cout << c[m] << " ";
}
cout << endl;

return 0;
```
> 7 3  
> 1 2 1 2 3 3 1

> 3

> Time Limit Exceeded