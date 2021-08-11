## AtCoder Beginner Contest 211

2021-07-24(Satn) 21:00 - 22:40, 100 minutes  
https://atcoder.jp/contests/abc211

※ All the codes are written in C++  
&nbsp;&nbsp;&nbsp;- **skipped** `main()` function or test case loop statement's brace(`{}`) and its outside  
&nbsp;&nbsp;&nbsp;- Basically, all the codes has the `<iostream>` header and namespace `std` even if there's no mention.  
&nbsp;&nbsp;&nbsp;- When any additional header is used, the header block is also noted seperately.


### A - Blood Pressure

#### C++
```cpp
int a, b;
cin >> a >> b;

cout.precision(10);
cout << (double) (a - b)/3 + b << endl;

return 0;
```

> 300 50

> 133.3333333

> Accepted


### B - Cycle Hit

#### C++
```cpp
#include <iostream>
#include <map>
```
```cpp
map<string, int> m;
string temp;
bool isYes = true;
for (int i = 0; i < 4; i++)
{
    cin >> temp;
    if (m.find(temp) == m.end())
    {
        m.insert(pair<string, int> (temp, 1));
    }
    else
    {
        isYes = false;
        break; 
    };        
}

if (isYes == true) cout << "Yes" << endl;
else cout << "No" << endl;

return 0;
```

> 3B  
> HR  
> 2B  
> H

> Yes

> Accepted


### C - chokudai

#### C++
```cpp
#include <iostream>
#include <string>
#include <vector>
```
```cpp
// Indput data
string c = "chokudai", s;
// cout << c[1] << endl;            // test : ok
cin >> s;
int cSize = c.size(), sSize = s.size();
int mod = 1e9 + 7;

// test
cout << "  ";
for (int k = 0; k < sSize; k++) cout << s[k] << ' ';
cout << endl;
```
```cpp
// Count : Dynamic Programming
vector<vector<int>> dp(cSize, vector<int> (sSize, 0));
for (int i = 0; i < cSize; i++)
{
    // test
    cout << c[i] << ' ';

    for (int j = 0; j < sSize; j++)
    {
        if (i == 0)
        {
            if (j == 0)
            {
                if (c[i] == s[j]) dp[i][j] = 1;
                else dp[i][j] = 0;
            }
            else
            {
                if (c[i] == s[j]) dp[i][j] = (dp[i][j-1] + 1) % mod;
                else dp[i][j] = dp[i][j-1] % mod;
            }
        }
        else if (j == 0) dp[i][j] = 0;
        else if (c[i] == s[j]) dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % mod;
        else dp[i][j] = dp[i][j-1] % mod;

        // test
        cout << dp[i][j] << ' ';
    }

    // test
    cout << endl;
}

// Output
cout << dp[cSize - 1][sSize - 1] << endl;

return 0;
```

> chokudaichokudaichokudai

> &nbsp;&nbsp;&nbsp;c h o k u d a i c h o k u d a i c h o k u d a i  
> c 1 1 1 1 1 1 1 1 2 2 2 2 2 2 2 2 3 3 3 3 3 3 3 3  
> h 0 1 1 1 1 1 1 1 1 3 3 3 3 3 3 3 3 6 6 6 6 6 6 6  
> o 0 0 1 1 1 1 1 1 1 1 4 4 4 4 4 4 4 4 10 10 10 10 10 10  
> k 0 0 0 1 1 1 1 1 1 1 1 5 5 5 5 5 5 5 5 15 15 15 15 15  
> u 0 0 0 0 1 1 1 1 1 1 1 1 6 6 6 6 6 6 6 6 21 21 21 21  
> d 0 0 0 0 0 1 1 1 1 1 1 1 1 7 7 7 7 7 7 7 7 28 28 28  
> a 0 0 0 0 0 0 1 1 1 1 1 1 1 1 8 8 8 8 8 8 8 8 36 36  
> i 0 0 0 0 0 0 0 1 1 1 1 1 1 1 1 9 9 9 9 9 9 9 9 45  
> 45

> Accepted

#### Editorial
☞ https://atcoder.jp/contests/abc211/editorial/2327


### D - Number of Shortest paths

#### C++
```cpp
#include <iostream>
#include <vector>
```
```cpp
// Input data
int N, M;
cin >> N >> M;

vector<pair<int, int>> v;
int temp1, temp2;
for (int i = 0; i < M; i++)
{
    cin >> temp1 >> temp2;
    v.push_back(pair<int, int> (temp1, temp2));
}

// Find the minimum hours to move
int count = 0, start = 1;
while (true)
{
    // need more codes ……
}

// I can't postpone anymore to say good game ……

return 0;
```

#### Editorial
☞ https://atcoder.jp/contests/abc211/editorial/2330