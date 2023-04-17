# [Google Code Jam 2023 - Farewell Round A](../../../README.md#google-code-jam)

2023.04.15 23:00 ~ 04.16 03:00 (GMT+9), 4 hrs

https://codingcompetitions.withgoogle.com/codejam/round/0000000000c95b94


## \<List>

- [Colliding Encoding (4 / 10 pts)](#colliding-encoding-4--10-pts)
- [Illumination Optimization (4 / 10 pts)](#illumination-optimization-4--10-pts)
- [Rainbow Sort (4 / 10 pts)](#rainbow-sort-4--10-pts)
- [ASCII Art (9 / 20 pts)](#ascii-art-9--20-pts)
- [Untie (9 / 20 pts)](#untie-9--20-pts)


## [Colliding Encoding (4 / 10 pts)](#list)

<details>
    <summary>Test Input & Output</summary>

#### Input
```
2
0 1 2 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3
4
ABC
BC
BCD
CDE
0 1 2 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3
3
CDE
DEF
EFG
```

#### Output
```
Case #1: NO
Case #2: YES
```
</details>

<details>
    <summary>Codes</summary>

#### C++
```cpp
#include <iostream>
#include <vector>
#include <set>
#define endl '\n'

using namespace std;
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
        // Input 26 disits into vector<char> D
        vector<char> D;
        for (int d = 0; d < 26; d++)
        {
            char temp;
            cin >> temp;
            D.push_back(temp);
        }
        #ifdef test
            cout << "\n<test>" << endl;
            for (int d = 0; d < 26; d++) cout << D[d];
            cout << endl;
        #endif

        // Input N words into vector<string> S
        int N;
        cin >> N;
        vector<string> S;
        for (int n = 0; n < N; n++)
        {
            string temp;
            cin >> temp;
            S.push_back(temp);
        }
        #ifdef test
            for (int n = 0; n < N; n++) cout << S[n] << ' ';
            cout << endl;
        #endif

        // Encoding
        set<string> Encoded;                                                    // not <int> because of 0xx
        string ans = "NO";
        for (int n = 0; n < N; n++)
        {
            int len = S[n].size();
            string encoded;
            for (int i = 0; i < len; i++) encoded += D[S[n][i] - 'A'];

            #ifdef test
                cout << encoded << ' ';
            #endif

            // Binary search to find if there's the same encoded number to each other
            if (Encoded.find(encoded) == Encoded.end()) Encoded.insert(encoded);// no same element → no collision
            else                                                                // → a collision
            {
                ans = "YES";
                break;
            }
        }

        // Output
        #ifdef test
            cout << endl;
        #endif
        cout << "Case #" << t << ": " << ans << endl;
    }

    return 0;
}
```
</details>

#### Submissions
> Samples: Passed  
> Test Set 1: Passed (4 pts)  
> Test Set 2: Passed (10 pts)


## [Illumination Optimization (4 / 10 pts)](#list)

not attempted


## [Rainbow Sort (4 / 10 pts)](#list)

<details>
    <summary>Test Input & Output</summary>

#### Input
```
2
4
3 8 8 2
5
3 8 2 2 8
```

#### Output
```
Case #1: 3 8 2
Case #2: IMPOSSIBLE
```
</details>

<details>
    <summary>Codes</summary>

#### C++
```cpp
#include <iostream>
#include <vector>
#include <set>
#define endl '\n'

using namespace std;
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
        bool ansFlag = true;

        // Input data into vector S
        int N;
        cin >> N;
        vector<int> S;
        for (int n = 0; n < N; n++)
        {
            int temp;
            cin >> temp;
            S.push_back(temp);
        }

        #ifdef test
            cout << "\n<test>" << endl;
        #endif

        // Save a vector v and a set ans at the same time
        vector<int> V;
        set<int> ANS;
        for (int n = 0; n < N; n++)
        {
            #ifdef test
                cout << S[n] << ' ';
            #endif

            // Find if possible or not
            if (n == 0)
            {
                V.push_back(S[n]);
                ANS.insert(S[n]);
            }
            else if (S[n] != S[n-1])
            {
                if (ANS.find(S[n]) == ANS.end())
                {
                    V.push_back(S[n]);
                    ANS.insert(S[n]);
                }
                else
                {
                    ansFlag = false;
                    break;
                }
            }
        }
        #ifdef test
            cout << endl;
        #endif

        // Output
        cout << "Case #" << t << ": ";
        if (ansFlag)
        {
            for (int i = 0; i < V.size(); i++) cout << V[i] << ' ';
            cout << endl;;
        }
        else cout << "IMPOSSIBLE" << endl;
    }

    return 0;
}
```
</details>

#### Submissions
> Samples: Passed  
> Test Set 1: Passed (4 pts)  
> Test Set 2: Passed (10 pts)


## [ASCII Art (9 / 20 pts)](#list)

<details>
    <summary>Test Input & Output</summary>

#### Input
```
2
5
31
```

#### Output
```
Case #1: E
Case #2: C
```
</details>

<details>
    <summary>Codes</summary>

#### C++
```cpp
#include <iostream>
#include <vector>
#include <set>
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
        // Input N
        ll N;
        cin >> N;

        #ifdef test
            cout << "\n<test>" << endl;
        #endif

        // Find i
        ll i = 1, cum = 26;
        while (cum < N)
        {
            cum += (++i) * 26;
        }

        // Get answer
        ll mod = ((i - 1) * i / 2) * 26;
        char ans = ('A') + (N - 1 - mod) / i;
        #ifdef test
            cout << N << " / " << cum << ' ' << i << ' '  << mod << " / " << N - mod << ' ' << N - 1 - mod << ' ' << (N - 1 - mod) / i << endl;
        #endif

        // Output
        cout << "Case #" << t << ": " << ans << endl;
    }

    return 0;
}
```
</details>

#### Submissions
> Samples: Passed  
> Test Set 1: Passed (9 pts)  
> Test Set 2: Passed (20 pts)


## [Untie (9 / 20 pts)](#list)

<details>
    <summary>Test Input & Output</summary>

#### Input
```
3
PRSSP
RRRRRRR
RSPRPSPRS
```

#### Output
```
Case #1: 2
Case #2: 4
Case #3: 0
```
</details>

<details>
    <summary>Codes : Trial 1</summary>

#### C++
```cpp
#include <iostream>
#include <vector>
#include <cmath>
#define endl '\n'
#define test

using namespace std;
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
        // Input N
        string C;
        cin >> C;

        // Count how many times change
        // 1) C[0] can changed
        int cnt1 = 0;
        bool justChanged = false, firstChanged = false;
        int len = C.size();
        for (int i = 0; i < len; i++)
        {
            if (i == 0)
            {
                if (C[i] == C[len-1] || C[i] == C[i+1])
                {
                    cnt1++;
                    justChanged = true;
                    firstChanged = true;
                }
            }
            else if (i < len - 1)
            {
                if (C[i] == C[i-1] || C[i] == C[i+1])
                {
                    if (justChanged == false)
                    {
                        cnt1++;
                        justChanged = true;
                    }
                    else
                    {
                        justChanged = false;
                    }
                }
            }
            else
            {
                if (C[i] == C[i-1] || C[i] == C[0])
                {
                    if (justChanged == false)
                    {
                        cnt1++;
                        justChanged = true;
                    }
                    else
                    {
                        if (firstChanged == false) justChanged = false;
                    }
                }
            }
        }
        // 2) C[0] can't changed
        int cnt2 = 0;
        justChanged = false;
        for (int i = 0; i < len; i++)
        {
            if (i < len - 1)
            {
                if (C[i] == C[i-1] || C[i] == C[i+1])
                {
                    if (justChanged == false)
                    {
                        cnt2++;
                        justChanged = true;
                    }
                    else
                    {
                        justChanged = false;
                    }
                }
            }
            else
            {
                if (C[i] == C[i-1] || C[i] == C[0])
                {
                    if (justChanged == false)
                    {
                        cnt2++;
                        justChanged = true;
                    }
                    else
                    {
                        justChanged = false;
                    }
                }
            }
        }

        // Output
        #ifdef test
            cout << "\n<test> " << C << endl;
            cout << cnt1 << ' ' << cnt2 << endl;
        #endif
        cout << "Case #" << t << ": " << min(cnt1, cnt2) << endl;
    }

    return 0;
}
```
</details>

#### Submissions
> Samples: Passed  
> Test Set 1: Wrong Answer (0 pts)  
> Test Set 2: Skipped (0 pts)