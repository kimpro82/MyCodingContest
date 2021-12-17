## BAEKJOON Online Judge

# # 문제 > 단계별로 풀어보기 > 12. 정렬
(2021.12.16)  
https://www.acmicpc.net/step/9


## 2750. 수 정렬하기

#### C++
(2021.12.11)
```cpp
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define endl '\n'
```
```cpp
int main()
{
    // Input N
    int N;
    cin >> N;

    // Input a vector
    vector<int> v;
    for (int i = 0; i < N; i++)
    {
        int temp;
        cin >> temp;
        v.push_back(temp);
    }

    // Sort (default : ascending order)
    sort(v.begin(), v.end());

    // Output (not in a row)
    for (int i = 0; i < N; i++) cout << v[i] << endl;

    return 0;
}
```

> 5  
> 5  
> 2  
> 3  
> 4  
> 1

> 1  
> 2  
> 3  
> 4  
> 5


## 2751. 수 정렬하기 2

#### C++
(2021.12.11)
```cpp
    //totally the same code with Q.2750
```

## 10989. 수 정렬하기 3

#### C++
(2021.12.11)
```cpp
#include <iostream>
#include <array>

using namespace std;

#define endl '\n'
```
```cpp
int main()
{
    // make it faster
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);

    // Input N
    int N;
    cin >> N;

    // Input an array
    array<int, 10001> arr = {0, };      // memory limit : 8 MB > int(4 byte) * 10,001
    for (int i = 0; i < N; i++)
    {
        int temp;
        cin >> temp;
        arr[temp]++;                    // 3 -> arr[3]++
    }

    // test
    // for (int i = 1; i <= 10000; i++) if (arr[i] > 0) cout << i << ' ' << arr[i] << endl;

    // Output
    for (int i = 1; i <= 10000; i++) for (int j = 0; j < arr[i]; j++) cout << i << endl;

    return 0;
}
```

> 10  
> 5  
> 2  
> 3  
> 1  
> 4  
> 2  
> 3  
> 5  
> 1  
> 7

> 1  
> 1  
> 2  
> 2  
> 3  
> 3  
> 4  
> 5  
> 5  
> 7


## 2108. 통계학

#### C++
(2021.12.16)
```cpp
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>

using namespace std;

#define endl '\n'
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

> 5  
> 1  
> 3  
> 8  
> -2  
> 2

> 2  
> 2  
> 1  
> 10


## 1427. 소트인사이드

#### C++
(2021.12.15)
```cpp
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define endl '\n'
```
```cpp
int main()
{
    // Input N
    string N;
    cin >> N;
    int len = N.size();

    // Input a vector
    vector<int> v;
    for (int i = 0; i < len; i++) v.push_back(N[i] - '0');

    // Sort (default : descending order)
    sort(v.rbegin(), v.rend());                             // need to practice more various ways to use sort()

    // Output (in a row)
    for (int i = 0; i < len; i++) cout << v[i];
    cout << endl;

    return 0;
}
```

> 2143

> 4321


## 11650. 좌표 정렬하기

#### C++
(2021.12.15)
```cpp
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define endl '\n'
```
```cpp
bool comp(pair<int, int> p1, pair<int, int> p2)             // I've just learned a new skill!
{
    if (p1.first == p2.first) return p1.second < p2.second;
    else return p1.first < p2.first;
}
```
```cpp
int main()
{
    // Input N
    int N;
    cin >> N;

    // Input vector<pair<int, int>>
    vector<pair<int, int>> v;
    for (int i = 0; i < N; i++)
    {
        int temp1, temp2;
        pair<int, int> p;
        cin >> temp1 >> temp2;
        p.first = temp1;
        p.second = temp2;
        v.push_back(p);
    }

    // Sort
    sort(v.begin(), v.end(), comp);

    // Output
    for (int i = 0; i < N; i++) cout << v[i].first << ' ' << v[i].second << endl;

    return 0;
}
```

> 5  
> 3 4  
> 1 1  
> 1 -1  
> 2 2  
> 3 3

> 1 -1  
> 1 1  
> 2 2  
> 3 3  
> 3 4


## 11651. 좌표 정렬하기 2

#### C++
(2021.12.15)
```cpp
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define endl '\n'
```
```cpp
bool comp(pair<int, int> p1, pair<int, int> p2)             // only different part from Q.11650
{
    if (p1.second == p2.second) return p1.first < p2.first;
    else return p1.second < p2.second;
}
```
```cpp
int main()
{
    // totally the same with Q.11650
}
```

> 5  
> 0 4  
> 1 2  
> 1 -1  
> 2 2  
> 3 3

> 1 -1  
> 1 2  
> 2 2  
> 3 3  
> 0 4


## 1181. 단어 정렬

#### C++
(2021.12.16)
```cpp
#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

#define endl '\n'
```
```cpp
struct comp                                                                         // should be a struct, refer to less<_Kty>
{
    bool operator() (const pair<int, string> p1, const pair<int, string> p2) const  // need to understand why use 'const'
    {
        if (p1.first != p2.first) return p1.first < p2.first;
        else return p1.second < p2.second;
    }
};                                                                                  // don't miss ';'
```
```cpp
// struct for set<string>
// struct comp                                                                      // should be a struct, refer to less<_Kty>
// {
//     bool operator() (const string s1, const string s2) const
//     {
//         if (s1.size() != s2.size()) return s1.size() < s2.size();
//         else return s1 < s2;
//     }
// };                                                                               // don't miss ';'
```
```cpp
// function for set<string> : an error occurs - 함수 "comp"은(는) 형식 이름이 아닙니다.C/C++(757)
// bool comp(string s1, string s2)
// {
//     if (s1.size() != s2.size()) return s1.size() < s2.size();
//     else return s1 < s2;
// }
```
```cpp
int main()
{
    // Input N
    int N;
    cin >> N;

    // Input set<pair<int, string>> with ordering
    set<pair<int, string>, comp> s;                                                 // declare with indicating how to order
    // template<typename _Key, typename _Compare = std::less<_Key>, typename _Alloc = std::allocator<_Key> >
    // less<_Key> is a struct
    for (int i = 0; i < N; i++)
    {
        string temp;
        cin >> temp;

        pair<int, string> p;
        p.first = temp.size();
        p.second = temp;

        s.insert(p);
    }

    // Output
    int len = s.size();
    for (auto it = s.begin(); it != s.end(); it++) cout << (*it).second << endl;

    return 0;
}
```

> 13  
> but  
> i  
> wont  
> hesitate  
> no  
> more  
> no  
> more  
> it  
> cannot  
> wait  
> im  
> yours

> i  
> im  
> it  
> no  
> but  
> more  
> wait  
> wont  
> yours  
> cannot  
> hesitate


## 10814. 나이순 정렬

#### C++
(2021.12.16)
```cpp
#include <iostream>
#include <set>
#include <tuple>                                                        // similar with <pair>, but elements are more than 3
#include <algorithm>

using namespace std;

#define endl '\n'
```
```cpp
struct comp
{
    bool operator() (const tuple<int, int, string> t1, const tuple<int, int, string> t2) const
    {
        if (get<1>(t1) != get<1>(t2)) return get<1>(t1) < get<1>(t2);
        else return get<0>(t1) < get<0>(t2);                            // maintain the existing order
    }
};
```
```cpp
int main()
{
    // Input N
    int N;
    cin >> N;

    // Input set<tuple<int, int, string>> with ordering
    set<tuple<int, int, string>, comp> s;
    for (int i = 0; i < N; i++)
    {
        int age;
        string name;
        cin >> age >> name;

        s.insert(tuple<int, int, string> (i, age, name));
    }

    // Output
    int len = s.size();
    for (auto it = s.begin(); it != s.end(); it++) cout << get<1>(*it) << ' ' << get<2>(*it) << endl;

    return 0;
}
```

> 3  
> 21 Junkyu  
> 21 Dohyun  
> 20 Sunyoung

> 20 Sunyoung  
> 21 Junkyu  
> 21 Dohyun


## 18870. 좌표 압축

#### C++
(2021.12.16)
```cpp
// rather worse performance
// #pragma GCC optimize ("O2")
// #pragma GCC target ("avx")
```
```cpp
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

#define endl '\n'
```
```cpp
int main()
{
    // Make it faster
    cin.tie(NULL);
    cout.tie(NULL);
	ios_base::sync_with_stdio(false);

    // Input N
    int N;
    cin >> N;

    // Input vector<int> and map<int, int>
    vector<int> v;
    map<int, int> m;
    for (int i = 0; i < N; i++)
    {
        int x;
        cin >> x;

        v.push_back(x);

        auto it = m.find(x);
        if (it == m.end()) m.insert(pair<int, int>(x, 0));
        else it->second++;
    }

    // Count rank
    int rank = 0;
    for (auto it = m.begin(); it != m.end(); it++)
    {
        it->second = rank;
        rank++;
    }

    // Output
    for (int i = 0; i < N - 1; i++) cout << m.find(v[i])->second << ' ';
    cout << m.find(v[N - 1])->second << endl;

    return 0;
}
```

> 5  
> 2 4 -10 4 -9

> 2 3 0 3 1