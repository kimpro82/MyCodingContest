## Google Code Jam 2022 - Qualification Round

2022.04.02 08:00 ~ 04.03 11:00, 27 hrs

https://codingcompetitions.withgoogle.com/codejam/round/0000000000876ff1


### \<List>

- [Punched Cards (11 pts)](#punched-cards-11-pts)
- [3D Printing (13 pts)](#3d-printing-13-pts)
- [d1000000 (9 / 11 pts)](#d1000000-9--11-pts)
- [Chain Reactions (10 / 12 / 5 pts)](#chain-reactions-10--12--5-pts)
- [Twisty Little Passages (29 pts)](#twisty-little-passages-29-pts)


### ※ Notes

- `C++`* : skipped `main()` function's brace(`{}`) and its outside including the following header lines
```cpp
#include <iostream>

#define endl '\n'

using namespace std;
```
- When any additional header is used, the header block is also noted seperately.


### [Punched Cards (11 pts)](#list)

#### C++
```cpp
int T;
cin >> T;

for (int t = 1; t <= T; t++)
{
    int R, C;
    cin >> R >> C;

    cout << "Case #" << t << ':' << endl;

    for (int r = 0; r <= 2 * R; r++)
    {
        for (int c = 0; c <= 2 * C; c++)
        {
            // test
            // cout << r << c;

            // The first row (additional) : ..+-+-+-+
            if (r == 0)
            {
                if (c == 0)                                         // c == 0 : for running only once in the first row
                {
                    for (int i = 0; i <= 2 * C; i++)
                    {
                        if (i < 2) cout << '.';
                        else if (i % 2 == 0) cout << '+';
                        else cout << '-';
                    }
                }
            }
            // The first column except the first row (additional)
            else if (c == 0)
            {
                if (r == 1) cout << ".";
                else if (r % 2 == 0) cout << '+';
                else cout << '|';
            }
            // Residual cells
            else if (r % 2 == 1)
            {
                if (c % 2 == 1) cout << '.';
                else cout << '|';
            }
            else
            {
                if (c % 2 == 1) cout << '-';
                else cout << '+';
            }
        }
        cout << endl;
    }
}

return 0;
```

#### Test Input
> 3  
> 3 4  
> 2 2  
> 2 3

#### Test Output
> Case #1:  
> ..+-+-+-+  
> ..|.|.|.|  
> +-+-+-+-+  
> |.|.|.|.|  
> +-+-+-+-+  
> |.|.|.|.|  
> +-+-+-+-+  
> Case #2:  
> ..+-+  
> ..|.|  
> +-+-+  
> |.|.|  
> +-+-+  
> Case #3:  
> ..+-+-+  
> ..|.|.|  
> +-+-+-+  
> |.|.|.|  
> +-+-+-+

#### Submissions
> Samples: Passed  
> Test Set 1: Passed (11 pts)


### [3D Printing (13 pts)](#list)

#### C++
```cpp
int T;
cin >> T;

for (int t = 1; t <= T; t++)
{
    // Input
    int cmyk[3][4];
    int min[4] = {1000000, 1000000, 1000000, 1000000};          // crazy but excused because this is competitive programming
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cin >> cmyk[i][j];

            if (cmyk[i][j] < min[j]) min[j] = cmyk[i][j];
        }
    }

    // Find if the sum of minimum inks meets 1,000,000
    int sum = 0;
    for (int j = 0; j < 4; j++)
    {
        if (sum >= 1000000) min[j] = 0;
        else if (sum + min[j] >= 1000000) min[j] = 1000000 - sum;

        sum += min[j];
    }

    // Output
    cout << "Case #" << t << ": ";
    if (sum == 1000000) for (int j = 0; j < 4; j++) cout << min[j] << ' ';
    else cout << "IMPOSSIBLE";
    cout << endl;
}

return 0;
```

#### Test Input
> 3  
> 300000 200000 300000 500000  
> 300000 200000 500000 300000  
> 300000 500000 300000 200000  
> 1000000 1000000 0 0  
> 0 1000000 1000000 1000000  
> 999999 999999 999999 999999  
> 768763 148041 178147 984173  
> 699508 515362 534729 714381  
> 949704 625054 946212 951187

#### Test Output
> Case #1: 300000 200000 300000 200000  
> Case #2: IMPOSSIBLE  
> Case #3: 400001 100002 100003 399994

#### Submissions
> Samples: Passed  
> Test Set 1: Passed (13 pts)


### [d1000000 (9 / 11 pts)](#list)

#### C++
```cpp
#include <iostream>
#include <vector>
#include <algorithm>
```
```cpp
// Run faster (N <= 10^5)
cin.tie(0);
cout.tie(0);
ios::sync_with_stdio(false);
```
```cpp
int T;
cin >> T;

for (int t = 1; t <= T; t++)
{
    // Input
    int N;
    cin >> N;

    vector<int> S = {0};
    int s;
    for (int n = 1; n <= N; n++)
    {
        cin >> s;
        S.push_back(s);
    }

    // Count
    int count = 0, criterion = 1;
    sort(S.begin(), S.end());
    for (int n = 1; n <= N; n++)
    {
        if (S[n] >= criterion)
        {
            count++;
            criterion++;
        }
    }

    // Output
    cout << "Case #" << t << ": " << count << endl;
}

return 0;
```

#### Test Input
> 4  
> 4  
> 6 10 12 8  
> 6  
> 5 4 5 4 4 4  
> 10  
> 10 10 7 6 7 4 4 5 7 4  
> 1  
> 10

#### Test Output
> Case #1: 4  
> Case #2: 5  
> Case #3: 9  
> Case #4: 1

#### Submissions
> Samples: Passed  
> Test Set 1: Passed (9 pts)  
> Test Set 2: Passed (11 pts)


### [Chain Reactions (10 / 12 / 5 pts)](#list)

It should be solved through `DFS` × `Greedy` but ……

#### C++
```cpp
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
```
```cpp
// Run faster (N <= 10^5)
cin.tie(0);
cout.tie(0);
ios::sync_with_stdio(false);
```
```cpp
int T;
cin >> T;

for (int t = 1; t <= T; t++)
{
    // Input
    int N;
    cin >> N;

    vector<int> F, P;
    int f, p;
    for (int n = 0; n < N; n++)
    {
        cin >> f;
        F.push_back(f);
    }
    for (int n = 0; n < N; n++)
    {
        cin >> p;
        P.push_back(p);
    }

    // Find initiators (that aren't pointed)
    vector<int> PCounting(N, 1);                                                    // mark 0 or 1 on a vector
    for (int n = 0; n < N; n++) PCounting[P[n] - 1] = 0;                            // why doesn't [-1] occur an error?
    vector<int> Initiators;
    for (int n = 0; n < N; n++) if (PCounting[n] > 0) Initiators.push_back(n + 1);  // + 1 : crazy
    int initLen = Initiators.size();

    // test : ok
    for (int n = 0; n < N; n++) cout << PCounting[n] << ' ';
    cout << endl;
    for (int i = 0; i < initLen; i++) cout << Initiators[i] << ' ';
    cout << endl;

    // Operate the permutations of Initiators
    int sum = 0, max = 0, passedSum, pointer;
    do
    {
        // test : ok
        // for (int i = 0; i < initLen; i++) cout << Initiators[i] << ' ';
        // cout << endl;

        vector<int> passed(initLen, 0);
        sum = 0, passedSum = 0, pointer;
        while (passedSum < initLen)
        {
            // recursion required
            passedSum++;
        }

        if (sum > max) max = sum;
    }
    while (next_permutation(Initiators.begin(), Initiators.end()));

    // Output
    cout << "Case #" << t << ": " << max << endl;
}

return 0;
```

#### Test Input
> 3  
> 4  
> 60 20 40 50  
> 0 1 1 2  
> 5  
> 3 2 1 4 5  
> 0 1 1 1 0  
> 8  
> 100 100 100 90 80 100 90 100  
> 0 1 2 1 2 3 1 3

#### Test Output
wrong
> Case #1: 0  
> Case #2: 0  
> Case #3: 0  

#### Submissions
not attempted


### [Twisty Little Passages (29 pts)](#list)
not attempted