## AtCoder Beginner Contest 210

2021-07-17(Sat) 21:00 - 22:40, 100 minutes  
https://atcoder.jp/contests/abc210

※ All the codes are written in C++  
    - **skipped** `main()` function's brace(`{}`) and its outside  
    - Basically, all the codes has the `<iostream>` header and namespace `std` even if there's no mention.  
    - When any additional header is used, the header block is also noted seperately.



### A - Cabbages

#### C++
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

#### C++
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

#### C++ - Trial 1
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

// Find the max number of colors in vector c's subsets of length k
set<int> s;
int max = 0, sSize;
int index;                      // test
for (int j = 0; j < n - k + 1; j++)
{
    s = {};
    for (int l = j; l < j + k; l++) s.insert(c[l]);
    sSize = s.size();
    if (sSize == k)
    {
        max = sSize;
        index = j;              // test
        break;
    } else if (sSize > max)
    {
        max = sSize;
        index = j;              // test
    }
}

// Output
cout << max << endl;

// test
for (int l = index; l < index + max; l++) cout << c[l] << " ";
cout << endl;

return 0;
```
> 7 3  
> 1 2 1 2 3 3 1

> 3

> Time Limit Exceeded

#### C++ - Trial 2
```cpp
#include <map>                      // instead of <set>
```
```cpp
// Find the max number of colors in vector c's subsets of length k
map<int, int> m;
int max = 0, mSize = 0;
int index = n;                  // test
for (int j = 0; j < n; j++)
{
    // remove the oldest element
    if (j >= k - 1)
    {
        if (m.find(c[j-k])->second > 1) m.find(c[j-k])->second--;
        else m.erase(c[j-k]);
    }

    // insert a new element
    if (m.find(c[j]) == m.end()) m.insert(pair<int, int> (c[j], 1));
    else m.find(c[j])->second++;

    // test
    for (auto it = m.begin(); it != m.end(); it++) cout << it->first << ' ';
    cout << endl;

    // judge if max
    mSize = m.size();
    if (mSize == k)
    {
        max = mSize;
        index = j;              // test
        break;
    } else if (mSize >= max)
    {
        max = mSize;
        index = j;              // test
    }
}
```
```cpp
// test
for (int l = index - k + 1; l < index + 1; l++) cout << c[l] << " ";
cout << endl;
```
> 1  
> 1 2  
> 1 2  
> 1 2  
> 1 2 3  
> 3  
> 1 2 3

> Accepted


### D - National Railway

Editorial ☞ https://atcoder.jp/contests/abc210/editorial/2305

????