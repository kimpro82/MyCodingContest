### Codeforces Round #734 (Div. 3)

2021.07.23(Fri) 23:35, 2 hrs  
https://codeforces.com/contest/1551

※ All the codes are written in C++  
    - **skipped** `main()` function or test case loop statement's brace(`{}`) and its outside  
    - Basically, all the codes has the `<iostream>` header and namespace `std` even if there's no mention.  
    - When any additional header is used, the header block is also noted seperately.


#### A. Polycarp and Coins

```cpp
// Input data
int n;
cin >> n;

// Count
int a, b;
b = (n + 1)/3;
a = n - b*2;

// Output
cout << a << ' ' << b << endl;
```

> 1000  
> 30  
> 1  
> 32  
> 1000000000  
> 5

> 334 333  
> 10 10  
> 1 0  
> 10 11  
> 333333334 333333333  
> 1 2

> Accepted


#### B1. Wonderful Coloring - 1

```cpp
#include <iostream>
#include <string>
#include <vector>
```

```cpp
// Input data
string s;
cin >> s;

// Make vector v from the number of each alphabet of string s
vector<int> v (26, 0);
for (int j = 0; j < s.size(); j++) v[s[j]-'a']++;

// Count the pairs of the red and green colored
int count = 0;
while (true)
{
    // test
    for (int m = 0; m < 26; m++) cout << v[m] << ' ';
    cout << "/ " << count << endl;

    int candidate1 = -1, candidate2 = -1;

    // find candidate1
    for (int k = 0; k < 26; k++)
    {
        if (v[k] > 0)
        {
            candidate1 = k;
            break;
        }
    }
    if (candidate1 == -1) break;

    // find candidate2
    for (int l = candidate1 + 1; l < 26; l++)
    {
        if (v[l] > 0)
        {
            candidate2 = l;
            break;
        }
    }
    if (v[candidate1] < 2 && candidate2 == -1) break;

    // count
    if (v[candidate1] > 1)          // if a letter exists 2 or more
    {
        v[candidate1] = 0;
        count++;
    } else if (v[candidate2] > 1)
    {
        v[candidate2] = 0;
        count++;
    } else
    {
        v[candidate1]--;
        v[candidate2]--;
        count++;
    }
} // The end of while loop

// Output
cout << count << endl;
```

> kzaaa  
> codeforces  
> archive  
> y  
> xxxxxx

> 3 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 / 0  
> 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 / 1  
> 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 / 2  
> 2  
> 0 0 2 1 2 1 0 0 0 0 0 0 0 0 2 0 0 1 1 0 0 0 0 0 0 0 / 0  
> 0 0 0 1 2 1 0 0 0 0 0 0 0 0 2 0 0 1 1 0 0 0 0 0 0 0 / 1  
> 0 0 0 1 0 1 0 0 0 0 0 0 0 0 2 0 0 1 1 0 0 0 0 0 0 0 / 2  
> 0 0 0 0 0 0 0 0 0 0 0 0 0 0 2 0 0 1 1 0 0 0 0 0 0 0 / 3  
> 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 1 0 0 0 0 0 0 0 / 4  
> 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 / 5  
> 5  
> ……

> Accepted


#### B2. Wonderful Coloring - 2

```cpp
#include <iostream>
#include <map>
#include <vector>
```

```cpp
// Input data
int n, k;                       // n : the length of a given sequence
cin >> n >> k;                  // k : the number of colors
```

```cpp
// Make map m
map<int, int> m;
int temp;
for (int j = 0; j < n; j++)
{
    cin >> temp;;
    if (m.find(temp) == m.end()) m.insert(pair<int, int> (temp, 1));
    else m.find(temp)->second += 1;
}

// test : ok
map<int, int>::iterator it;
for (it = m.begin(); it != m.end(); it++) cout << it->first << ' ' << it->second << " / ";
cout << "\b\b\b" << endl;       // '\b' doesn't work
```

```cpp
// Convert map m to vector v;
vector<pair<int, int>> v(m.begin(), m.end());

// test : ok
for (int l = 0; l < v.size(); l++) cout << v[l].first << ' ';
cout << endl;        
for (int l = 0; l < v.size(); l++) cout << v[l].second << ' ';
cout << endl;
```

```cpp
// need more codes ……
```

> 10 3  
> 3 1 1 1 1 10 3 10 10 2  
> ……

> 1 4 / 2 1 / 3 2 / 10 3 /  
> 1 2 3 10  
> 4 1 2 3  
> ……

> Give up ㅋ