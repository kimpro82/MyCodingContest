## AtCoder Beginner Contest 212

2021-07-31(Sat) 21:00 - 22:40, 100 minutes  
https://atcoder.jp/contests/abc212

※ All the codes are written in C++  
&nbsp;&nbsp;&nbsp;- **skipped** `main()` function or test case loop statement's brace(`{}`) and its outside  
&nbsp;&nbsp;&nbsp;- Basically, all the codes has the `<iostream>` header and namespace `std` even if there's no mention.  
&nbsp;&nbsp;&nbsp;- When any additional header is used, the header block is also noted seperately.


### A - Alloy

#### C++
```cpp
int A, B;
cin >> A >> B;

if (A != 0 && B == 0) cout << "Gold" << endl;
else if (A == 0) cout << "Silver" << endl;
else cout << "Alloy" << endl;

return 0;
```
Seriously?

> 50 50

> Alloy

> Accepted


### B - Weak Password

#### C++
```cpp
#include <iostream>
#include <string>
```
```cpp
// Input data
string X;
cin >> X;

// Determine
int weak1 = 0, weak2 = 0;
for (int i = 1; i < 4; i++)
{
    if (X[i] != X[0]) weak1++;
    if (X[i-1] < '9')
    {
        if (X[i] == X[i-1] + 1) weak2++;
    } else
    {
        if (X[i] == '0') weak2++;
    }
}

// Output
if (weak1 == 0 || weak2 == 3) cout << "Weak" << endl;
else cout << "Strong" << endl;

return 0;
```

> 9012

> Weak

> Accepted


### C - Min Difference

#### C++ - Trial 1
```cpp
#include <iostream>
#include <vector>

#define endl '\n'

using namespace std;
using ll = long long;
```
```cpp
// Input data
int N, M, temp;
cin >> N >> M;
vector<int> A, B;
for (int i = 0; i < N; i++)
{
    cin >> temp;
    A.push_back(temp);
}
for (int j = 0; j < M; j++)
{
    cin >> temp;
    B.push_back(temp);
}
```
```cpp
// Find the minimum difference
ll min = 1000000000;
for (int k = 0; k < N; k++)
{
    for (int l = 0; l < M; l++)
    {
        if (abs(A[k] - B[l]) < min) min = abs(A[k] - B[l]);
        if (min == 0) break;
    }
    if (min == 0) break;
}
```
```cpp
// Output
cout << min << endl;

return 0;
```

> 6 8  
> 82 76 82 82 71 70  
> 17 39 67 2 45 35 22 24

> 3

> Time Limit Exceeded

#### C++ - Trial 2
```cpp
#include <set>      // instead of <vector>
```
```cpp
// Input data
int N, M, temp;
cin >> N >> M;
set<int> A, B;
for (int i = 0; i < N; i++)
{
    cin >> temp;
    A.insert(temp);
}
int aSize = A.size();
for (int j = 0; j < M; j++)
{
    cin >> temp;
    B.insert(temp);
}
int bSize = B.size();
```
```cpp
// Find the minimum difference
int min = 1000000000, diff;
for (auto it1 = A.begin(); it1 != A.end(); it1++)
{
    for (auto it2 = B.begin(); it2 != B.end(); it2++)
    {
        diff = abs(*it1 - *it2);
        if (diff < min) min = diff;

        // test
        cout << *it1 << ' ' << *it2 << ' ' << diff << ' ' << min << ' ' << endl;

        if (diff < min) min = diff;
        if (min == 0 || diff > min) break;
    }
    if (min == 0) break;
}
```

> 70 2 68 68  
> 70 17 53 53  
> ……  
> 70 67 3 3  
> 71 2 69 3  
> 76 2 74 3  
> 82 2 80 3  
> 3

> Wrong Answer

#### C++ - Trial 3
```cpp
#include <set>
```
```cpp
// Find the minimum difference
int min = 1000000000, diff;
auto it1 = A.begin(), it2 = B.begin();
while (it1 != A.end() && it2 != B.end())
{
    diff = abs(*it1 - *it2);
    if (diff < min) min = diff;

    // test
    cout << *it1 << ' ' << *it2 << ' ' << diff << ' ' << min << ' ' << endl;

    if (min == 0) break;            // *it1 == *it2
    else if (*it1 > *it2)
    {
        if (it2 == B.end()) break;
        else it2++;
    } else
    {
        if (it1 == A.end()) break;
        else it1++;
    }
}
```

> 70 2 68 68  
> 70 17 53 53  
> ……  
> 70 67 3 3  
> 3

> Accepted


### D - Querying Multiset

#### C++
```cpp
#include <iostream>
#include <map>

#define endl '\n'

using namespace std;
using ll = long long;
```
```cpp
int Q, p, x;
ll temp, min;
cin >> Q;
map<ll, int> m;
for (int q = 0; q < Q; q++)
{
    cin >> p;

    // test
    cout << "[q : " << q + 1 << ", p : " << p << ']' << endl;

    // The below codes are located here
}

return 0;
```
```cpp
    if (p == 1)
    {
        cin >> x;

        if (m.find(x) == m.end()) m.insert(pair<ll, int> (x, 1));
        else m.find(x)->second++;
    }
    else if (p == 2)
    {
        cin >> x;

        map<ll, int> m2;
        for (auto it = m.begin(); it != m.end(); it++)
        {
            // if (m.find(*it + x)->second == 0) m.insert(pair<ll, int> (*it + x, 1));
            // else m.find(*it + x)->second++;
            // 이러한 피연산자와 일치하는 "+" 연산자가 없습니다. -- 피연산자 형식이 std::pair<const ll, int> + int입니다.

            temp = it->first + x;
            m2.insert(pair<ll, int> (temp, it->second));
        }
        m = m2;
    }
    else    // p == 3
    {
        min = INT64_MAX;
        for (auto it = m.begin(); it != m.end(); it++)
        {
            if (it->first < min) min = it->first;
        }
        cout << min << endl;

        if (m.find(min)->second > 1) m.find(min)->second--;
        else m.erase(min);
    }

    // test
    for (auto it = m.begin(); it != m.end(); it++) cout << it->first << ' ';
    cout << endl;
    for (auto it = m.begin(); it != m.end(); it++) cout << it->second << ' ';
    cout << endl;
```

> 5  
> 1 3  
> 1 5  
> 3  
> 2 2  
> 3

> [q : 1, p : 1]  
> 3  
> 1  
> [q : 2, p : 1]  
> 3 5  
> 1 1  
> [q : 3, p : 3]  
> 3  
> 5  
> 1  
> [q : 4, p : 2]  
> 7  
> 1  
> [q : 5, p : 3]  
> 7

> Time Limit Exceeded