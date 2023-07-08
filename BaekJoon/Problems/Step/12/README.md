### [BAEKJOON Online Judge](/README.md#baekjoon-online-judge)

# 문제 > 단계별로 풀어보기 > 12. 브루트 포스

(2021.12.10) - `C++`

https://www.acmicpc.net/step/22


### **List**

- [2798. JACK](#2798-jack블랙잭)
- [2231. Digit Generator](#2231-digit-generator분해합)
- [19532. 수학은 비대면강의입니다](#19532-수학은-비대면강의입니다) *(new)*
- [1018. 체스판 다시 칠하기](#1018-체스판-다시-칠하기)
- [1436. 영화감독 숌](#1436-영화감독-숌)
- [2839. ŠEĆER(설탕 배달)](#2839-šećer설탕-배달)

#### (Depreciated)
- [7568. 덩치](#7568-덩치)

### **Note**

- All the codes of any language for the same problem have basically the same result.
- Typical headers like the below are basically skipped, but they are noted seperately when there are any additional line.
  - `C++` : `#include <iostream>` `#define endl '\n';` `using namespace std;`


## [2798. JACK(블랙잭)](#list)

> 5 21
> 5 6 7 8 9

> 21

#### C++ (2021.10.31)
```cpp
#include <vector>
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


## [2231. Digit Generator(분해합)](#list)

> 216

> 198

#### C++ (2021.10.31)
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


## [19532. 수학은 비대면강의입니다](#list)

> 1 3 -1 4 1 7

> 2 -1

#### C++ (2023.07.06)
```cpp
int main()
{
    // Input
    int a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;

    // Operate : Brute Force
    int x, y;
    for (int i = -999; i <= 999; i++)
    {
        for (int j = -999; j <= 999; j++)
        {
            if (a * i + b * j == c && d * i + e * j == f)
            {
                x = i;
                y = j;
                break;
            }
        }
    }

    // Output
    cout << x << ' ' << y << endl;

    return 0;
}
```


## [1018. 체스판 다시 칠하기](#list)

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

#### C++ (2021.12.10)
```cpp
#include <vector>
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


## [1436. 영화감독 숌](#list)

> 187

> 66666

#### C++ (2021.12.10)
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


## [2839. ŠEĆER(설탕 배달)](#list)

> 18

> 4

#### Bash (2022.03.11)
```bash
read n

let "bag3 = 0"
let "rest = 1"

for ((i = 0; i <= $((n / 3)); i++))
do
    # if [[ $(($((n - i * 3)) % 5)) == 0 ]]; then       # worse readability
    let "criteria = (n - i * 3) % 5"
    if [ $criteria -eq 0 ]; then
        let "bag3 = i"
        let "rest = 0"
        break
    fi

    # test
    # echo ${bag3} $((bag3 * 3)) $((n - bag3 * 3))
done



if [ $rest -eq 0 ]; then
    echo $((bag3 + (n - bag3 * 3) /  5))
else
    echo -1
fi
```

#### C++ (2021.07.12)
```cpp
int main()
{
    int N;
    cin >> N;       // 3 <= n <= 5000

    int bag3 = 0;
    bool rest = true;
    for (int i = 0; i <= N / 3; i++)
    {
        if ((N - i * 3) % 5 == 0)
        {
            bag3 = i;
            rest = false;
            break;
        }
    }

    // Test
    // cout << bag3 << " " << bag3 * 3 << " " << (N - bag3 * 3) << endl;

    // Output
    if (rest == false)
    {
        cout << bag3 + (N - bag3 * 3) / 5 << endl;
    } else
    {
        cout << -1 << endl;
    }

    return 0;
}
```


## [7568. 덩치](#list)

> 5  
> 55 185  
> 58 183  
> 88 186  
> 60 175  
> 46 155

> 2 2 1 2 5

#### C++ (2021.12.10)
```cpp
#include <vector>
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
