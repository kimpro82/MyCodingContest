## BAEKJOON Online Judge

# 문제 > 단계별로 풀어보기 > 12. 브루트 포스

(2021.12.10)  

https://www.acmicpc.net/step/22


※ All the `C++` codes **skipped** the below lines. :
```cpp
#include <iostream>

using namespace std;

#define endl '\n'
```
&nbsp;&nbsp;&nbsp;When any additional header is used, the header block is also noted seperately.


## 2798. JACK

#### C++
(2021.11.01)
```cpp
#include <iostream>
#include <vector>

using namespace std;

#define endl '\n'
```
```cpp
int main()
{
    // Input 1 : N, M
    int N, M;
    cin >> N >> M;

    // Input 2 : N cards
    vector<int> cards;
    int temp;
    for (int n = 0; n < N; n++)
    {
        cin >> temp;
        cards.push_back(temp);
    }

    // Find the max value that does not exceed 21
    int sum, max = 0;
    for (int i = 0; i < N - 2; i++)
    {
        if (cards[i] > M) continue;

        for (int j = i + 1; j < N - 1; j++)
        {
            if (cards[i] + cards[j] > M) continue;

            for (int k = j + 1; k < N; k++)
            {
                sum = cards[i] + cards[j] + cards[k];

                // test
                cout << cards[i] << ' ' << cards[j] << ' ' << cards[k] << ' ' << sum << ' ' << max << endl;

                if (sum > M) continue;
                else if (sum > max) max = sum;
            }
        }
    }

    // Output
    cout << max << endl;

    return 0;
}
```

> 5 21
> 5 6 7 8 9

> 21


## 2231. Digit Generator

#### C++
(2021.11.01)
```cpp
int main()
{
    // Input
    int N;
    cin >> N;

    // Count N's digits
    int n = N, digits = 1;
    while (n > 10)
    {
        n /= 10;
        digits++;
    }

    // Assume a minimum generator candidate
    int min = max(0, N - 9 * digits);

    // Find the minimum generator
    int digitSum;
    string candidate;
    bool ok = false;
    for (int i = min; i < N; i++)
    {
        digitSum = i;
        candidate = to_string(i);

        for (int j = 0; j < candidate.size(); j++) digitSum += candidate[j] - '0';

        // test
        // cout << N << ' ' << digits << ' ' << candidate << ' ' << digitSum << endl;

        if (digitSum == N)
        {
            ok = true;
            break;
        }
    }

    // Output
    if (!ok) cout << 0 << endl;
    else cout << candidate << endl;

    return 0;
}
```

> 216

> 198


## 7568. 덩치

#### C++
(2021.12.10)
```cpp
#include <iostream>
#include <vector>

using namespace std;

#define endl '\n'
```
```cpp
int main()
{
    // Input
    int N;
    cin >> N;

    // Input x, y
    int x, y;
    vector<vector<int>> xy;
    for (int i = 0; i < N; i++)
    {
        cin >> x >> y;
        vector<int> temp;
        temp.push_back(x);
        temp.push_back(y);
        xy.push_back(temp);
    }

    // Determine everyone's ranking
    vector<int> ranking;
    for (int i = 0; i < N; i++)
    {
        int onesRank = 1;
        for (int j = 0; j < N; j++) if (xy[i][0] < xy[j][0] && xy[i][1] < xy[j][1]) onesRank++;
        ranking.push_back(onesRank);
    }

    // Output
    for (int i = 0; i < N - 1; i++) cout << ranking[i] << ' ';
    cout << ranking[N - 1] << endl;

    return 0;
}
```

> 5  
> 55 185  
> 58 183  
> 88 186  
> 60 175  
> 46 155

> 2 2 1 2 5


## 1018. 체스판 다시 칠하기

#### C++
(2021.12.10)
```cpp
#include <iostream>
#include <vector>

using namespace std;

#define endl '\n'
```
```cpp
int main()
{
    // Input N, M
    int N, M;                                                                               // 8 <= N, M <= 50
    cin >> N >> M;

    // Input wb
    vector<string> wb;
    for (int i = 0; i < N; i++)
    {
        string temp;
        cin >> temp;
        wb.push_back(temp);
    }

    // Find the minimum number to paint the cell for (N - 8 + 1, M - 8 + 1)
    int min = 8 * 8;
    // Loop for (r, c) : the reference point at the top left corner
    for (int r = 0; r < N - 8 + 1; r++)
    {
        for (int c = 0; c < M - 8 + 1; c++)
        {
            // Loop for 8 * 8 from each (r, c)
            int change, changeW = 0, changeB = 0;                                           // changeW/B : the reference point can be W and B both
            for (int i = 0; i < 8; i++)
            {
                for (int j = 0; j < 8; j++)
                {
                    if ((i + j) % 2 == 0)                                                   // no change if the same with (r, c)
                    {
                        if (wb[r + i][c + j] == 'W') changeB++;
                        else changeW++;
                    }
                    else                                                                    // change if the same with (r, c)
                    {
                        if (wb[r + i][c + j] == 'B') changeB++;
                        else changeW++;
                    }
                }
            }

            // determine if the number of changes is smaller than the previous min
            if (changeW < changeB) change = changeW;
            else change = changeB;
            if (min > change) min = change;
        }
    }

    // Output
    cout << min << endl;

    return 0;
}
```

> 11 12  
> BWWBWWBWWBWW  
> BWWBWBBWWBWW  
> WBWWBWBBWWBW  
> BWWBWBBWWBWW  
> WBWWBWBBWWBW  
> BWWBWBBWWBWW  
> WBWWBWBBWWBW  
> BWWBWBWWWBWW  
> WBWWBWBBWWBW  
> BWWBWBBWWBWW  
> WBWWBWBBWWBW

> 15


## 1436. 영화감독 숌

#### C++
(2021.12.10)
```cpp
int main()
{
    // Input N
    int N ;         // 1 <= N <= 10000
    cin >> N;

    // Find the 666-number
    int n = 666, count = 0;
    while (true)
    {
        string stringN = to_string(n);
        int len = stringN.length();

        for (int i = 0; i < len - 3 + 1; i++)
        {
            if (stringN.substr(i, 3) == "666")
            {
                count++;

                // test
                // cout << n << ' ' << count << endl;

                break;
            }
        }

        if (count == N) break;

        n++;
    }

    // Output
    cout << n << endl;

    return 0;
}
```

> 187

> 66666