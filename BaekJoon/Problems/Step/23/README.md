## [BAEKJOON Online Judge](/README.md#baekjoon-online-judge)

# 문제 > 단계별로 풀어보기 > 23. 동적 계획법 1

https://www.acmicpc.net/step/16

(2022.04.24) - `C++`  


## **List**

- [1003. 피보나치 함수 (Excluded)](#1003-피보나치-함수-excluded)
- [24416. 알고리즘 수업 - 피보나치 수 1](#24416-알고리즘-수업---피보나치-수-1)
- [9184. Function Run Fun](#9184-function-run-fun)
- [1904. 01타일](#1904-01타일)
- [9461. Padovan Sequence](#9461-padovan-sequence)
- [1912. 연속합](#1912-연속합)
- [1149. RGB거리](#1149-rgb거리)
- [1932. The Triangle](#1932-the-triangle)
- [2579. 계단 오르기](#2579-계단-오르기)
- [1463. 1로 만들기](#1463-1로-만들기)
- [10844. 쉬운 계단 수](#10844-쉬운-계단-수)
- [2156. 포도주 시식](#2156-포도주-시식)
- [11053. 가장 긴 증가하는 부분 수열](#11053-가장-긴-증가하는-부분-수열)
- 11054. 가장 긴 바이토닉 부분 수열
- 2565. 전깃줄
- 9251. LCS
- 12865. 평범한 배낭


## [1003. 피보나치 함수 (Excluded)](#list)

#### Input Data
```
2
6
22
```

#### Output Data
```
5 8
10946 17711
```

#### C++ (2022.04.24)
```cpp
#include <iostream>
#include <vector>
#define endl '\n'

using namespace std;
```
```cpp
int main()
{
    int t, n;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        cin >> n;

        // Count : Dynamic Programming
        vector<pair<int, int>> dp;
        for (int j = 0; j <= n; j++)
        {
            if (j == 0) dp.push_back(make_pair(1, 0));
            else if (j == 1) dp.push_back(make_pair(0, 1));
            else dp.push_back(make_pair(dp[j - 1].second, dp[j - 2].second + dp[j - 1].second));    // not ->second, but .second

            // test
            // cout << n << ' ' << j << ' ' << dp[j].first << ' ' << dp[j].second << endl;
        }

        // Output
        cout << dp[n].first << ' ' << dp[n].second << endl;
    }

    return 0;
}
```


## [24416. 알고리즘 수업 - 피보나치 수 1](#list)

#### Input Data
```
30
```

#### Output Data
```
832040 28
```

#### C++ (2022.08.26)
```cpp
#include <iostream>
#include <vector>

using namespace std;

#define endl '\n'
```
```cpp
// Recursion
int fib(int n, int* p1)
{
    if (n == 1 || n == 2)
    {
        (*p1)++;
        return 1;
    }
    else return fib(n - 1, p1) + fib(n - 2, p1);
}
```
```cpp
// Dynamic Programming …… originally, but?
int fibonacci(int n, int* p2)
{
    // do not need to get the fibonacci number
    *p2 = n - 2;

    return 1;
}
```
```cpp
int main()
{
    int n;
    cin >> n;

    int cnt1 = 0, cnt2 = 0;
    int* p1 = &cnt1;
    int* p2 = &cnt2;
    fib(n, p1);
    fibonacci(n, p2);

    cout << cnt1 << " " << cnt2 << endl;

    return 0;
}
```


## [9184. Function Run Fun](#list)

#### Input Data
```
1 1 1
2 2 2
10 4 6
50 50 50
-1 7 18
-1 -1 -1
```

#### Output Data
```
w(1, 1, 1) = 2
w(2, 2, 2) = 4
w(10, 4, 6) = 523
w(50, 50, 50) = 1048576
w(-1, 7, 18) = 1
```

#### C++ (2022.04.24)
```cpp
#include <iostream>
#include <vector>
#define endl '\n'

using namespace std;
```
```cpp
int main()
{
    int a, b, c, temp;
    while (cin >> a >> b >> c)
    {
        if (a == -1 && b == -1 && c == -1) return 0;

        cout << "w(" << a << ", " << b << ", " << c << ") = ";  // to avoid affection from the below if statement
        // cout << '\n';                                        // for test

        if (a <= 0 || b <= 0 || c <= 0)                         // start from [0][0][0]
        {
            a = 0;
            b = 0;
            c = 0;
        }
        else if (a > 20 || b > 20 || c > 20)                    // end at [20][20][20]
        {
            a = 20;
            b = 20;
            c = 20;
        }

        vector<vector<vector<int>>> dp;
        for (int i = 0; i <= a; i++)
        {
            vector<vector<int>> d2;

            for (int j = 0; j <= b; j++)
            {
                vector<int> d3;

                for (int k = 0; k <= c; k++)
                {
                    if (i == 0 || j == 0 || k == 0) temp = 1;
                    else if (i < j && j < k) temp = d3[k-1] + d2[j-1][k-1] - d2[j-1][k];                // dp[i][j][k-1] + dp[i][j-1][k-1] - dp[i][j-1][k] causes a run-time error
                    else temp = dp[i-1][j][k] + dp[i-1][j-1][k] + dp[i-1][j][k-1] - dp[i-1][j-1][k-1];

                    // test
                    // cout << "i: " << i << " j: " << j << " k: " << k << " w: " << temp << endl;

                    d3.push_back(temp);
                }

                d2.push_back(d3);
            }

            dp.push_back(d2);
        }

        cout << dp[a][b][c] << endl;
    }

    return 0;
}
```


## [1904. 01타일](#list)

#### Input Data
```
4
```

#### Output Data
```
5
```

#### C++ (2022.04.24)
```cpp
#include <iostream>
#include <vector>
#define endl '\n'

using namespace std;
```
```cpp
int main()
{
    int n;
    cin >> n;

    vector<int> dp {0, 1, 2};

    // Find the recurrence relation!
    for (int i = 3; i <= n; i++) dp.push_back((dp[i - 2] + dp[i - 1]) % 15746);     // pass if n < 3
                                                                                    // don't forget the modulo!
    cout << dp[n] << endl;

    return 0;
}
```


## [9461. Padovan Sequence](#list)

#### Input Data
```
2
6
12
```

#### Output Data
```
3
16
```

#### C++ (2022.04.24)
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
    int t;
    ll n;                                                               // int causes a run-time error
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        cin >> n;

        // Dynamic Programming
        vector<ll> dp {0, 1, 1, 1, 2, 2};
        for (int j = 6; j <= n; j++)
        {
            dp.push_back(dp[j-1] + dp[j-5]);                            // pass if n < 5

            // test
            // printf("%d %d %d %d\n", j, dp[j-1], dp[j-5], dp[j]);     // %lld runs strange
        }

        // Output
        cout << dp[n] << endl;
    }

    return 0;
}
```


## [1912. 연속합](#list)

#### Input Data
```
10
10 -4 3 1 5 6 -35 12 21 -1
```

#### Output Data
```
33
```

#### C++ (2022.08.26)
```cpp
#include <iostream>
#include <vector>

using namespace std;

#define endl '\n'
```
```cpp
int main()
{
    int n;
    cin >> n;

    // Input data
    vector<int> v;
    int el;
    for (int i = 0; i < n; i++)
    {
        cin >> el;
        v.push_back(el);
    }

    // DP
    vector<int> dp = {v[0]};
    int sumMax = v[0], temp;
    for (int i = 1; i < n; i++)
    {
        if (dp[i-1] > 0) dp.push_back(dp[i-1] + v[i]);
        else dp.push_back(v[i]);

        if (dp[i] > sumMax) sumMax = dp[i];

        // test
        // cout << "i : " << i << "\tdp[i-1] : " << dp[i-1] << "\tv[i] : " << v[i] << "\tdp[i] : " << dp[i] << "\tsumMax : " << sumMax << endl;
    }

    // Output
    cout << sumMax << endl;

    return 0;
}
```


## [1149. RGB거리](#list)

#### Input Data
```
3
26 40 83
49 60 57
13 89 99
```

#### Output Data
```
96
```

#### C++ (2022.04.24)
```cpp
#include <iostream>
#include <vector>
#include <algorithm>                        // min()
#define endl '\n'

using namespace std;
```
```cpp
int main()
{
    int n, r, g, b;
    cin >> n;

    // Dynamic Programming
    vector<vector<int>> dp;
    dp.push_back(vector<int> {0, 0, 0});    // when i == 0
    for (int i = 1; i <= n; i++)
    {
        cin >> r >> g >> b;

        vector<int> temp;
        temp.push_back(r + min(dp[i-1][1], dp[i-1][2]));
        temp.push_back(g + min(dp[i-1][0], dp[i-1][2]));
        temp.push_back(b + min(dp[i-1][0], dp[i-1][1]));
        dp.push_back(temp);
    }

    // Output
    cout << min(min(dp[n][0], dp[n][1]), dp[n][2]) << endl;

    return 0;
}
```


## [1932. The Triangle](#list)

#### Input Data
```
5
7
3 8
8 1 0
2 7 4 4
4 5 2 6 5
```

#### Output Data
```
30
```

#### C++ (2022.04.24)
```cpp
#include <iostream>
#include <vector>
#define endl '\n'

using namespace std;
```
```cpp
int main()
{
    int n, temp;
    cin >> n;

    // Dynamic Programming
    vector<vector<int>> dp;
    dp.push_back(vector<int> {0, 0});                               // when i == 0
    for (int i = 1; i <= n; i++)
    {
        vector<int> row;
        row.push_back(0);                                           // when j == 0
        for (int j = 1; j <= i; j++)
        {
            cin >> temp;
            row.push_back(temp + max(dp[i-1][j-1], dp[i-1][j]));
        }
        row.push_back(0);                                           // when j == i
        dp.push_back(row);

        // test
        // cout << i << ": ";
        // for (int j = 0; j <= i + 1; j++) cout << row[j] << ' ';
        // cout << endl;
    }

    // Output : find the maximum value in the last row
    int max = 0;
    for (auto it = dp[n].begin(); it != dp[n].end(); it++) if (*it > max) max = *it;
    cout << max << endl;

    return 0;
}
```


## [2579. 계단 오르기](#list)

#### Input Data
```
6
10
20
15
25
10
20
```

#### Output Data
```
75
```

#### C++ (2022.04.24)
```cpp
#include <iostream>
#include <vector>
#include <algorithm>                                    // max()
#define endl '\n'

using namespace std;
```
```cpp
int main()
{
    int n, score;
    cin >> n;

    // Dynamic Programming
    vector<vector<int>> dp;
    dp.push_back(vector<int> {0, 0, 0});                // when i == 0
    for (int i = 1; i <= n; i++)
    {
        cin >> score;

        // i = 1 ~ 3 : {OOX / XOO / OXO}
        if (i == 1) dp.push_back(vector<int> {score, 0, score});
        else if (i == 2) dp.push_back(vector<int> {score + dp[1][0], score, dp[1][2]});
        else if (i == 3) dp.push_back(vector<int> {dp[2][0], score + dp[2][1], score + dp[2][2]});
        else dp.push_back(vector<int> {max(dp[i-1][1], dp[i-1][2]), score + dp[i-1][2], score + dp[i-1][0]});

        // test
        // printf("%d : %d %d %d\n", i, dp[i][0], dp[i][1], dp[i][2]);
    }

    // Output : it must be O when i == n
    if (n == 1) cout << max(dp[n][0], dp[n][2]) << endl;
    else if (n == 2) cout << max(dp[n][0], dp[n][1]) << endl;
    else cout << max(dp[n][1], dp[n][2]) << endl;

    return 0;
}
```


## [1463. 1로 만들기](#list)

#### Input Data
```
10
```

#### Output Data
```
3
```

#### C++ (2022.04.26)
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
    int x;
    cin >> x;

    // Dynamic Programming
    vector<vector<int>> dp;
    dp.push_back(vector<int> {x});
    int min = x, count = 0;

    while (min > 1)
    {
        vector<int> d2;                                                         // vector vs set?

        for (int i = 0; i < dp[count].size(); i++)
        {
            if (dp[count][i] % 3 == 0) d2.push_back(dp[count][i] / 3);
            if (dp[count][i] % 2 == 0) d2.push_back(dp[count][i] / 2);
            d2.push_back(dp[count][i] - 1);
        }

        count++;

        for (int i = 0; i < d2.size(); i++) if (d2[i] < min) min = d2[i];

        // test
        // cout << count << " (min : " << min << ") : ";
        // for (int i = 0; i < d2.size(); i++) cout << d2[i] << ' ';
        // cout << endl;

        dp.push_back(d2);
    }

    cout << count << endl;

    return 0;
}
```


## [10844. 쉬운 계단 수](#list)

#### Input Data
```
2
```

#### Output Data
```
17
```

#### C++ (2022.04.26)
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
    cin >> n;                                                                       // 1 <= n <= 100

    // Dynamic Programming
    vector<vector<ll>> dp;
    // i == 0
    dp.push_back(vector<ll> (10, 0));
    // i == 1
    dp.push_back(vector<ll> (10, 1));
    dp[1][0] = 0;

    for (int i = 2; i <= n; i++)
    {
        vector<ll> d2 (10, 0);

        for (int j = 0; j < 10; j++)
        {
            if (j == 0) d2[0] = dp[i-1][1];
            else if (j < 9) d2[j] = (dp[i-1][j-1] + dp[i-1][j+1]) % 1000000000;     // don't forget the modulo!
            else  d2[9] = dp[i-1][8];
        }

        dp.push_back(d2);

        // test
        // cout << n << " :";
        // for (int j = 0; j < 10; j++) cout << ' ' << d2[j];
        // cout << endl;
    }

    // Output
    ll sum = 0;
    for (int i = 0; i < dp[n].size(); i++) sum += dp[n][i];
    cout << sum % 1000000000 << endl;

    return 0;
}
```


## [2156. 포도주 시식](#list)

#### Input Data
```
6
6
10
13
9
8
1
```

#### Output Data
```
33
```

#### C++ (2022.04.29)
```cpp
#include <iostream>
#include <vector>
#include <algorithm>                                    // max()
#define endl '\n'

using namespace std;
```
```cpp
int main()
{
    int n, score;
    cin >> n;

    // Dynamic Programming
    vector<vector<int>> dp;
    dp.push_back(vector<int> (6, 0));           // when i == 0
    for (int i = 1; i <= n; i++)
    {
        cin >> score;

        // i = 1 ~ 3 : {XXO, XOX, XOO, OXX, OXO, OOX} ☜ three more cases from Q.2579!
        if (i == 1) dp.push_back(vector<int> {0, 0, 0, score, score, score});
        else if (i == 2) dp.push_back(vector<int> {0, score, score, dp[1][3], dp[1][3], score + dp[1][3]});
        else if (i == 3) dp.push_back(vector<int> {score, dp[2][1], score + dp[2][2], dp[2][3], score + dp[2][4], dp[2][5]});
        else
        {
            dp.push_back(vector<int> 
            {
                score + dp[i-1][3],
                max(dp[i-1][0], dp[i-1][4]),
                score + max(dp[i-1][0], dp[i-1][4]),
                max(dp[i-1][1], dp[i-1][5]),
                score + max(dp[i-1][1], dp[i-1][5]),
                dp[i-1][2]
            });
        }
        // It would be better to use a recurrence relation ……

        // test
        // printf("%d : %d %d %d %d %d %d\n", i, dp[i][0], dp[i][1], dp[i][2], dp[i][3], dp[i][4], dp[i][5]);
    }

    // Output
    int maxValue = 0;
    for (int i = 0; i < 6; i++) if (dp[n][i] > maxValue) maxValue = dp[n][i];
    cout << maxValue << endl;

    return 0;
}
```


## [11053. 가장 긴 증가하는 부분 수열](#list)

#### Input Data
```
6
10 20 10 30 20 50
```

#### Output Data
```
4
```

#### C++ - Trial 1 (2022.04.30)
```cpp
#include <iostream>
#include <vector>
#include <algorithm>                                            // sort()
#define endl '\n'

using namespace std;
```
```cpp
int main()
{
    // Input data
    int n, temp;
    cin >> n;

    vector<int> a;
    a.push_back(0);                                             // i == 0
    for (int i = 1; i <= n; i++)
    {
        cin >> temp;
        a.push_back(temp);
    }

    // Make an additional vector b that is sorted a
    vector<int> b = a;
    sort(b.begin(), b.end());

    // Dynamic Programming
    vector<vector<int>> dp;
    dp.push_back(vector<int> (n+1, 0));                         // i == 0
    for (int i = 1; i <= n; i++)
    {
        vector<int> row (n+1, 0);
        vector<int> currentMax (n+1, 0);                        // memo the current max value, don't need a vector but it's for test
        for (int j = 1; j < n; j++)                             // j == 0 : row[0] = 0
        {
            if (a[j] > currentMax[j-1] && a[j] <= b[i])
            {
                row[j] = row[j-1] + 1;
                currentMax[j] = a[j];
            }
            else
            {
                row[j] = row[j-1];
                currentMax[j] = currentMax[j-1];
            }
        }
        if (a[n] > currentMax[n-1])                             // j == n
        {
            row[n] = row[n-1] + 1;
            currentMax[n] = a[n];
        }
        else
        {
            row[n] = row[n-1];
            currentMax[n] = currentMax[n-1];
        }
        dp.push_back(row);

        // test
        cout << i << ' ' << b[i] << " :";
        for (int j = 1; j <= n; j++) cout << ' ' << row[j] << ' ' << currentMax[j] <<  " /";
        cout << endl;
    }

    // Find the max value among dp[][n]
    int maxValue = 0;
    for (int i = 1; i <= n; i++) if (dp[i][n] > maxValue) maxValue = dp[i][n];

    // Output
    cout << maxValue << endl;

    return 0;
}
```
> Wrong : counterexample  
> 4  
> 40 20 40 10

#### C++ - Trial 2 (2022.05.02)
```cpp
int main()
{
    ……

    // Dynamic Programming
    vector<vector<int>> dp;
    dp.push_back(vector<int> (n+1, 0));                         // i == 0
    for (int i = 1; i <= n; i++)
    {
        vector<int> currentMax (n+1, 0);                        // memo the current max value, don't need a vector but it's for test
        vector<int> row (n+1, 0);                               // j == 0 : row[0] = 0
        for (int j = 1; j <= i; j++)                            // j >= 1
        {
            if (j < i)
            ……
            else                                                // j == i : It's the max(final) value
            {
                row[j] = row[j-1] + 1;
                currentMax[j] = a[j];
            }

        }
        dp.push_back(row);

        // test
        cout << i << ' ' << a[i] << " :";
        for (int j = 1; j <= i; j++) cout << ' ' << row[j] << ' ' << currentMax[j] <<  " /";
        cout << endl;
    }

    // Find the max value among dp[n][n] : check only diagonal elements
    int maxValue = 0;
    for (int i = 1; i <= n; i++) if (dp[i][i] > maxValue) maxValue = dp[i][i];

    ……
}
```
> Wrong


## [11054. 가장 긴 바이토닉 부분 수열](#list)

not tried yet


## [2565. 전깃줄](#list)

not tried yet


## [9251. LCS](#list)

not tried yet


## [12865. 평범한 배낭](#list)

not tried yet