## BAEKJOON Online Judge

# 문제 > 단계별로 풀어보기 > 17. 그리디 알고리즘

https://www.acmicpc.net/step/33

(2022.04.21) - `C++`  


## **List**

- [11047. 동전 0](#11047-동전-0)
- [1931. 회의실 배정](#1931-회의실-배정)
- [11399. ATM](#11399-atm)
- [1541. 잃어버린 괄호](#1541-잃어버린-괄호)
- [13305. 주유소](#13305-주유소)


**※ Note**

&nbsp;&nbsp; - All the codes of any language for the same problem have basically the same result.  


## [11047. 동전 0](#list)

#### Input Data
```
10 4200
1
5
10
50
100
500
1000
5000
10000
50000
```

#### Output Data
```
6
```

#### C++
```cpp
#include <iostream>
#include <vector>
#define endl '\n'

using namespace std;
```
```cpp
int main()
{
    // Input data
    int n, k;
    cin >> n >> k;

    vector<int> coins;
    int coin;
    for (int i = 0; i < n; i++)
    {
        cin >> coin;
        coins.push_back(coin);
    }

    // Count with the Greedy algorithm
    int count = 0, freq;
    for (int i = 0; i < n; i++)
    {
        freq = k / coins[n - i - 1];
        k -= freq * coins[n - i - 1];
        count += freq;
    }
    
    // Output
    cout << count << endl;

    return 0;
}
```


## [1931. 회의실 배정](#list)

#### Input Data
```
11
1 4
3 5
0 6
5 7
3 8
5 9
6 10
8 11
8 12
2 13
12 14
```

#### Output Data
```
4
```

#### C++
```cpp
#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'

using namespace std;
```
```cpp
bool comp(pair<int, int> p1, pair<int, int> p2)
{
    if (p1.second == p2.second) return p1.first <= p2.first;
    else return p1.second < p2.second;
}
```
```cpp
int main()
{
    // Input data
    int n;
    cin >> n;

    vector<pair<int, int>> meeting;
    int start, end;
    for (int i = 0; i < n; i++)
    {
        cin >> start >> end;
        meeting.push_back(make_pair(start, end));
    }

    // Sort by start first, by end second
    sort(meeting.begin(), meeting.end(), comp);

    // Count by Greedy algorithm
    int count = 0, endPoint = 0;
    for (int i = 0; i < n; i++)
    {
        if (meeting[i].first >= endPoint)
        {
            count++;

            // test
            // cout << i << ' ' << meeting[i].first << ' ' << meeting[i].second << ' ' << endPoint << ' ' << count << endl;

            endPoint = meeting[i].second;
        }
    }

    // Output
    cout << count << endl;

    return 0;
}
```


## [11399. ATM](#list)

#### Input Data
```
5
3 1 4 3 2
```

#### Output Data
```
32
```

#### C++
```cpp
#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'

using namespace std;
```
```cpp
int main()
{
    // Input data
    int n;
    cin >> n;

    vector<int> p;
    int temp;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        p.push_back(temp);
    }

    // Sort in ascending order
    sort(p.begin(), p.end());

    // Count by Greedy algorithm
    int leadTime = 0;
    for (int i = 0; i < n; i++) leadTime += p[i] * (n - i);

    // Output
    cout << leadTime << endl;

    return 0;
}
```


## [1541. 잃어버린 괄호](#list)

#### Input Data
```
55-50+40
```

#### Output Data
```
-35
```

#### C++
```c++
#include <iostream>
#define endl '\n'

using namespace std;
```
```cpp
int main()
{
    // Input data
    string s;
    cin >> s;
    int len = s.size();

    // Read formula
    int endPoint = 0, sum = 0, sign = 1;
    for (int i = 0; i < len; i++)
    {
        if (s[i] == '+' || s[i] == '-' || i == len - 1)
        {
            sum += stoi(s.substr(endPoint)) * sign;         // stoi() cuts substring before sign (ex. 55-50+40 → 55)

            // test
            // cout << i << ' ' << s[i] << ' ' << sign << ' ' << endPoint << ' ' << s.substr(endPoint) << ' ' << sum << endl;

            endPoint = i + 1;
            if (s[i] == '-') sign = -1;
        }
    }

    // Output
    cout << sum << endl;

    return 0;
}
```


## [13305. 주유소](#list)

#### Input Data
```
4
2 3 1
5 2 4 1
```

#### Output Data
```
18
```

#### C++
```cpp
#include <iostream>
#include <vector>
#define endl '\n'

using namespace std;
using ll = long long;
```
```cpp
int main()
{
    // Input data
    int n;
    cin >> n;

    vector<ll> distance;
    ll temp;
    for(int i = 0; i < n - 1; i++)
    {
        cin >> temp;
        distance.push_back(temp);
    }

    vector<ll> price;
    for(int i = 0; i < n; i++)
    {
        cin >> temp;
        price.push_back(temp);
    }
    

    // Calculate the minimum cost
    ll cost = 0, minPrice = price[0];
    for(int i = 0; i < n - 1; i++)
    {
        if (price[i] < minPrice) minPrice = price[i];
        cost += distance[i] * minPrice;

        // test
        // cout << i << ' ' << distance[i] << ' ' << price[i] << ' ' << minPrice << ' ' << cost << endl;
    }

    // Output
    cout << cost << endl;

    return 0;
}
```