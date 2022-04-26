# Google Code Jam 2022 - Round 1B

2022.04.02 08:00 ~ 04.03 11:00, 27 hrs

https://codingcompetitions.withgoogle.com/codejam/round/000000000087711b


## \<List>

- [Pancake Deque (7pts, 8pts, 10pts)]()
- [Controlled Inflation (14pts, 21pts)]()
- [ASeDatAb (25pts, 15pts)]()


## [Pancake Deque (7pts, 8pts, 10pts)](#list)

#### Test Input
```
4
2
1 5
4
1 4 2 3
5
10 10 10 10 10
4
7 1 3 1000000
```

#### Test Output
```
Case #1: 2
Case #2: 3
Case #3: 5
Case #4: 2
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
    // Run faster (N <= 10^5)
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    int T;
    cin >> T;

    for (int t = 1; t <= T; t++)
    {
        // Input
        int N;
        cin >> N;

        vector<int> S;
        int s, max = 0, maxIdx;
        for (int n = 0; n < N; n++)
        {
            cin >> s;
            S.push_back(s);

            // Find the maximum value's index
            if (s > max) 
            {   max = s;
                maxIdx = n;
            }
        }
        
        // printf("max : %d, maxIdx : %d\n", max, maxIdx);                                              // test
        
        // Count
        int count = 1;
        // 1) 0 ~ maxIdx
        max = S[0];
        for (int n = 1; n <= maxIdx; n++)
        {
            if (S[n] >= max)
            {
                max = S[n];
                count++;
            }
            // cout << n << ' ' << S[n-1] << ' ' << max << ' ' << count << endl;                        // test
        }
        // 2) N-1 ~ maxIdx
        max = S[N-1];
        for (int n = N-1; n >= maxIdx; n--)
        {
            if (S[n] >= max)
            {
                max = S[n];
                count++;
            }
            // cout << n << ' ' << S[n] << ' ' << max << ' ' << count << endl;                          // test
        }
        // 3) find if maxIdx causes double-count
        if (maxIdx == 0)
        {
            if (S[0] >= S[1]) count--;
            // cout << S[0] << ' ' << S[1] << ' ' << count << endl;                                     // test
        }
        else if (maxIdx == N-1)
        {
            if (S[N-2] <= S[N-1]) count--;
            // cout << S[N-2] << ' ' << S[N-1] << ' ' << count << endl;                                 // test
        }
        else
        {
            if (S[maxIdx] >= S[maxIdx-1] && S[maxIdx] >= S[maxIdx+1]) count--;
            // cout << S[maxIdx-1] << ' ' << S[maxIdx] << ' ' << S[maxIdx+1] << ' ' << count << endl;   // test
        }

        // Output
        cout << "Case #" << t << ": " << count << endl;
    }

    return 0;
}
```

#### Submissions
> Samples: Passed  
> Test Set 1: Passed (7 pts)  
> Test Set 2: Passed (8 pts)  
> Test Set 3: Passed (10 pts)


## [Controlled Inflation (14pts, 21pts)](#list)

#### Test Input
```
2
3 3
30 10 40
20 50 60
60 60 50
5 2
1 1000000000
500000000 1000000000
1 1000000000
500000000 1
1 1000000000
```

#### Test Output
```
Case #1: 110
Case #2: 4999999996
```

#### C++
```cpp
#include <iostream>
#include <vector>
#include <cmath>
#define endl '\n'

using namespace std;
using ll = long long;
```
```cpp
int main()
{
    // Run faster
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    int T;
    cin >> T;

    for (int t = 1; t <= T; t++)
    {
        // Input
        int N, P;
        cin >> N >> P;

        // Dynamic Programming
        vector<vector<ll>> dp;
        ll temp, min, max, dist, sum1, sum2;
        dp.push_back(vector<ll> {0, 0, 0, 0, 0});                                                             // i = 0
        for (int n = 1; n <= N; n++)
        {
            min = 1000000000, max = 0;
            for (int p = 1; p <= P; p++)
            {
                cin >> temp;

                if (temp < min) min = temp;
                if (temp > max) max = temp;
            }
            dist = max - min;
            sum1 = (dp[n-1][3] + abs(max - dp[n-1][0]) <= dp[n-1][4] + abs(max - dp[n-1][1])) ? dp[n-1][3] + abs(max - dp[n-1][0]) : dp[n-1][4] + abs(max - dp[n-1][1]);
            sum1 += dist;
            sum2 = (dp[n-1][3] + abs(min - dp[n-1][0]) <= dp[n-1][4] + abs(min - dp[n-1][1])) ? dp[n-1][3] + abs(min - dp[n-1][0]) : dp[n-1][4] + abs(min - dp[n-1][1]);
            sum2 += dist;
            // crazy~~~

            // test
            // printf("min : %lld, max : %lld, dist : %lld, sum1 : %lld, sum2 : %lld\n", min, max, dist, sum1, sum2);

            dp.push_back(vector<ll> {min, max, dist, sum1, sum2});
        }

        // Output
        ll ans = (sum1 <= sum2) ? sum1 : sum2;
        cout << "Case #" << t << ": " << ans << endl;
    }

    return 0;
}
```

#### Submissions
> Samples: Passed  
> Test Set 1: Passed (14 pts)  
> Test Set 2: Passed (21 pts)

I faced some struggle with dealing `printf()`'s integer format `%d` `%ld` `%lld` in this problem, so that I investigated it seperately at *[printf() format test (2022.04.25)]*(https://github.com/kimpro82/MyPractice/tree/master/C&Cpp#printf-format-test-20220425) in the other repository *[MyPractice]*(https://github.com/kimpro82/MyPractice/).


## [ASeDatAb (25pts, 15pts)](#list)

not attempted