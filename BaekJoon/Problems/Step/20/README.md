## [BAEKJOON Online Judge](/README.md#baekjoon-online-judge)

# 문제 > 단계별로 풀어보기 > 20. 심화2

https://www.acmicpc.net/step/54

- (2023.07.14) - `C++`



## **List**

- [1037. 약수](#1037-약수)
- [25192. 인사성 밝은 곰곰이](#25192-인사성-밝은-곰곰이)
- [26069. 붙임성 좋은 총총이](#26069-붙임성-좋은-총총이)
- [2108. 통계학](#2108-통계학)
- [20920. 영단어 암기는 괴로워](#20920-영단어-암기는-괴로워)


**※ Note**  

&nbsp;&nbsp; - All the codes of any language for the same problem have basically the same result.  
&nbsp;&nbsp; - Typical headers like the below are basically skipped, but they are noted seperately when theere are any additional line.  
&nbsp;&nbsp;&nbsp;&nbsp; · `C++` : `#include <iostream>` `#define endl '\n';` `using namespace std;`  
&nbsp;&nbsp;&nbsp;&nbsp; · `Golang` : `package main` `import "fmt"`  



## [1037. 약수](#list)

```txt
6
3 4 2 12 6 8
```
```txt
24
```

<details>
  <summary>Answer : C++ (2023.07.13)</summary>

```cpp
int main()
{
    int n;
    cin >> n;

    int a, max = 0, min = 1'000'000;
    while (n--)
    {
        cin >> a;
        if (a > max) max = a;
        if (a < min) min = a;
    }

    // Output
    int ans = max * min;
    cout << ans << endl;

    return 0;
}
```
</details>

> 맞았습니다!!


## [25192. 인사성 밝은 곰곰이](#list)

```txt
7
ENTER
pjshwa
chansol
chogahui05
ENTER
pjshwa
chansol
```
```txt
5
```

<details>
  <summary>Answer : C++ (2023.07.13)</summary>

```cpp
……
#include <set>
#include <algorithm>
……
```
```cpp
int main()
{
    int n;
    cin >> n;

    int cnt = 0;
    string name;
    set<string> names;
    for (int i = 0; i < n; i++)
    {
        cin >> name;
        if (name == "ENTER") names.clear();
        else if (names.find(name) == names.end())
        {
            cnt++;
            names.insert(name);
        }
    }

    // Output
    cout << cnt << endl;

    return 0;
}
```
</details>

> 맞았습니다!!


## [26069. 붙임성 좋은 총총이](#list)

```txt
12
bnb2011 chansol
chansol chogahui05
chogahui05 jthis
jthis ChongChong
jthis jyheo98
jyheo98 lms0806
lms0806 pichulia
pichulia pjshwa
pjshwa r4pidstart
r4pidstart swoon
swoon tony9402
tony9402 bnb2011
```
```txt
10
```

<details>
  <summary>Answer : C++ (2023.07.14)</summary>

```cpp
……
#include <set>
#include <algorithm>
……
```
```cpp
int main()
{
    int n;
    cin >> n;

    string s1, s2, cc = "ChongChong";
    set<string> m = {cc};
    for (int i = 0; i < n; i++)
    {
        cin >> s1 >> s2;
        if (m.find(s1) != m.end()) m.insert(s2);
        if (m.find(s2) != m.end()) m.insert(s1);
    }

    // Output
    int cnt = m.size();
    cout << cnt << endl;

    return 0;
}
```
</details>

> 맞았습니다!!




## [2108. 통계학](#list)

```txt
5
1
3
8
-2
2
```
```txt
2
2
1
10
```

<details>
  <summary>Answer : C++ (2021.12.16)</summary>

```cpp
……
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>
……
```
```cpp
int main()
{
    // Input N
    int N;
    cin >> N;

    // Input numbers
    vector<int> v, modeCandidate;
    map<int, int> m;
    int sum = 0, modeFreq = 0, max = -4000, min = 4000;
    for (int i = 0; i < N; i++)
    {
        int n;
        cin >> n;

        // 1. Mean
        sum += n;                                                           // 4,000 * 500,000 = 2,000,000,000 < __int_max__

        // 2. Median
        v.push_back(n);

        // 3. Mode
        auto mFind = m.find(n);
        if (mFind == m.end()) m.insert(pair<int, int>(n, 1));
        else mFind->second++;
        mFind = m.find(n);                                                  // avoid mFind == m.end()
        if (mFind->second > modeFreq) modeFreq = mFind->second;

        // test
        // cout << mFind->first << ' ' << mFind->second << ' ' << modeFreq << endl;

        // 4. Max - Min
        if (n < min) min = n;
        if (n > max) max = n;
    }

    // 2. Median : sort by ascending order
    sort(v.begin(), v.end());

    // 3. Mode : the given condition is like trash ……
    int mode;
    for (auto it = m.begin(); it != m.end(); it++)
    {
        if (it->second == modeFreq) modeCandidate.push_back(it->first);
        if (modeCandidate.size() > 2) break;
    }
    if (modeCandidate.size() == 1) mode = modeCandidate[0];
    else mode = modeCandidate[1];

    // Output
    cout << round((double) sum / N) << endl;                                // 1. Mean
    cout << v[(N - 1) / 2] << endl;                                         // 2. Median
    cout << mode << endl;                                                   // 3. Mode
    cout << max - min << endl;                                              // 4. Max - Min

    return 0;
}
```
</details>

> 틀렸습니다 (2022.02.21 재채점)

<details>
  <summary>Answer : Golang (2022.07.11)</summary>

```go
……
import (
    ……
    "bufio"
    "os"
    "sort"
    "math"
)
```
```go
func main() {

    // Make it faster
    var reader = bufio.NewReader(os.Stdin)

    var n int                                   // n <= 500,000
    fmt.Scanln(&n)

    // Input
    var num []int
    for i := 0; i < n; i++ {
        var temp int
        fmt.Fscanln(reader, &temp)
        num = append(num, temp)
    }

    // 1. Mean
    var sum int = 0                             // sum <= 4,000 * 500,000 < int max
    for i := 0; i < n; i++ {
        sum += num[i]
    }
    var mean int = int(math.Round(float64(sum)/float64(n)))

    // 2. Median
    sort.Ints(num)
    var median int = num[(n-1)/2]               // n is aways odd

    // 3. Mode : crazy~~~
    // 3.1 Get a map consists of num and freq.
    var m map[int]int
    m = make(map[int]int)
    for i := 0; i < n; i++ {
        _, exists := m[num[i]]
        if !exists {
            m[num[i]] = 1
        } else {
            m[num[i]]++
        }
    }
    // 3.2 Find the maximum freq.
    var maxFreq int = 0
    for _, v := range m {
        if v > maxFreq {
            maxFreq = v
        }
    }
    // 3.3 Find all the keys with maximum freq.
    var modes []int
    for k, v := range m {
        if v == maxFreq {
            modes = append(modes, k)
        }
    }
    // 3.4 Find the answer
    var mode int
    var length int = len(modes)
    if length > 1 {
        sort.Ints(modes)
        mode = modes[1]
    } else {
        mode = modes[0]
    }

    // 4. Range
    var Range int = num[n-1] - num[0]

    // Output
    fmt.Println(mean)                           // math.Round() requires float64
    fmt.Println(median)
    fmt.Println(mode)
    fmt.Println(Range)
}
```
</details>

> 맞았습니다!!


## [20920. 영단어 암기는 괴로워](#list)

```txt
12 5
appearance
append
attendance
swim
swift
swift
swift
mouse
wallet
mouse
ice
age
```
```txt
swift
mouse
appearance
attendance
append
wallet
```

<details>
  <summary>Answer : C++ (2023.07.14)</summary>

```cpp
……
#include <map>
#include <vector>
#include <algorithm>

// #define test
……
```
```cpp
bool comp(const pair<string, int>& a, const pair<string, int>& b)                                   // return true : a is the first & b is the second
{
    if (a.second != b.second) return a.second > b.second;                                           // 1) frequency
    else if (a.first.size() != b.first.size()) return a.first.size() > b.first.size();              // 2) length of the word
    else return a.first < b.first;                                                                  // 3) lexicographical order
}
```
```cpp
int main()
{
    // Faster I/O
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    // Input
    int n, m;
    cin >> n >> m;
    map<string, int> mp;
    for (int i = 0; i < n; i++)
    {
        string temp;
        cin >> temp;

        if (temp.size() >= m)
        {
            if (mp.find(temp) == mp.end()) mp[temp] = 1;
            else mp[temp]++;
        }
    }

    // Sort with a new vector
    vector<pair<string, int>> v;
    for (auto it = mp.begin(); it != mp.end(); it++) v.push_back(pair<string, int> ((*it).first, (*it).second));
    sort(v.begin(), v.end(), comp);

    // Output
    for (auto it = v.begin(); it != v.end(); it++)
    {
        #ifdef test
            cout << (*it).first << ' ' << (*it).second << endl;
        #else
            cout << (*it).first << endl;
        #endif
    }

    return 0;
}
```
</details>

> 맞았습니다!!
