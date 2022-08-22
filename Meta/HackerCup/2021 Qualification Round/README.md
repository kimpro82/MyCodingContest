# Meta(Facebook) Hacker Cup - 2022 Qualification Round

2022.08.27 02:00 ~ 08.30 02:00, 72 hrs

https://www.facebook.com/codingcompetitions/hacker-cup/2021/qualification-round


## \<List>

- [Problem A1: Consistency - Chapter 1 (11pt)](#)
- [Problem A2: Consistency - Chapter 2 (17pt)](#)
- [Problem B: Xs and Os (15pt)](#)
- [Problem C1: Gold Mine - Chapter 1 (21pt)](#)
- [Problem C2: Gold Mine - Chapter 2 (36pt)](#)


## [Problem A1: Consistency - Chapter 1 (11pt)](#list)

#### Test Input
```
6
ABC
F
BANANA
FBHC
FOXEN
CONSISTENCY
```

#### Test Output
```
Case #1: 2
Case #2: 0
Case #3: 3
Case #4: 4
Case #5: 5
Case #6: 12
```

#### C++ - Trial 1 (2021.08.30)
```cpp
#include <iostream>
#include <vector>

using namespace std;
#define endl '\n'
```
```cpp
int main()
{
    // Find vowels' indices : 0, 4, 8, 14 , 20
    string AEIOU = "AEIOU";
    vector<int> vowel;
    int temp;
    for (int i = 0; i < 5; i++)
    {
        temp = AEIOU[i]-'A';
        vowel.push_back(temp);
    }
    // // test
    // for (int i = 0; i < 5; i++) cout << vowel[i] << endl;

    int T;
    cin >> T;

    // Input vector<string> S
    vector<string> S;
    for (int t = 0; t < T; t++)
    {

        string s;
        cin >> s;
        S.push_back(s);
    }

    // Test T times
    for (int t = 0; t < T; t++)
    {
        // Make vector v to count each alphabet from string S[t]
        int len = S[t].size();
        vector<int> v (26, 0);
        for (int i = 0; i < len; i++) v[S[t][i] - 'A']++;

        // Count each of sum from vowels and consonants
        int vw = 0, cs = 0, vwMax = 0, csMax = 0;
        bool ifVw = false;
        for (int i = 0; i < 26; i++)
        {
            if (v[i] > 0)
            {
                for (int j = 0; j < 5; j++)
                {
                    if (i == vowel[j])
                    {
                        vw += v[i];
                        if (v[i] > vwMax) vwMax = v[i];
                        ifVw = true;
                        break;
                    }
                }
                if (ifVw == false)
                {
                    cs += v[i];
                    if (v[i] > csMax) csMax = v[i];
                }
            }
            ifVw = false;
        }

        // Determine where operate A and B - Trial 1
        int answer;
        if (vw - vwMax >= cs - csMax) answer = vw + (cs - csMax) * 2;
        else answer = cs + (vw - vwMax) * 2;

        // test
        // cout << "len : : " << len << ", vw : " << vw << ", vwMax : " << vwMax << ", cs : " << cs << ", csMax : " << csMax << endl;

        // Output
        cout << "Case #" << t + 1 << ": " << answer << endl;
    }

    return 0;
}
```
> Wrong Answer
```cpp
/* Wrong Case - Trial 1
UFOVKZEOUTPUJSWEITEUAIYDRIBGUIUIOEII

My Output :
47

Correct Output :
43
*/
```

#### C++ - Trial 2 (2021.08.30)
```cpp
int main()
{
    ……
        // Determine where operate A and B - Trial 2 (Upsolving)
        int answer;
        if (vw == 0)
        {
            if (cs - csMax == 0) answer = 0;
            else answer = min(cs, (cs - csMax) * 2);
        }
        else if (cs == 0)
        {
            if (vw - vwMax == 0) answer = 0;
            else answer = min(vw, (vw - vwMax) * 2);
        }
        else if (vw - vwMax >= cs - csMax) answer = vw + (cs - csMax) * 2;
        else answer = cs + (vw - vwMax) * 2;
    ……
}
```
> Wrong Answer
```cpp
/* Wrong Case - Trial 2
OXEOURJOEUEJUUTUEIEQORXSBGLUIIARAVUBPUICEIJAIILEQDBIIQONE
UFOVKZEOUTPUJSWEITEUAIYDRIBGUIUIOEII

My Output :
75
47

Correct Output :
72
43
*/
```

#### C++ - Trial 3
```cpp
int main()
{
    ……
        // Determine where operate A and B - Trial 3 (Upsolving)
        int answer;
        if (vw == 0)
        {
            if (cs - csMax == 0) answer = 0;
            else answer = min(cs, (cs - csMax) * 2);
        }
        else if (cs == 0)
        {
            if (vw - vwMax == 0) answer = 0;
            else answer = min(vw, (vw - vwMax) * 2);
        }
        else if ((vw - vwMax) * 2 + cs <= (cs - csMax) * 2 + vw) answer = (vw - vwMax) * 2 + cs;
        else answer = (cs - csMax) * 2 + vw;
    ……
}
```
> Accepted


## [Problem A2: Consistency - Chapter 2 (17pt)](#list)

not attempted


## [Problem B: Xs and Os (15pt)](#list)

#### Test Input
```
8
2
XO
..
2
X.
.O
……
5
OX.OO
X.XXX
OXOOO
OXOOO
XXXX.
```

#### Test Output
```
Case #1: 1 1
Case #2: 1 2
Case #3: 3 6
Case #4: 2 2
Case #5: 1 1
Case #6: Impossible
Case #7: 2 2
Case #8: 1 2
```

#### C++ - Trial 1
```cpp
#include <iostream>
#include <vector>

using namespace std;
#define endl '\n'
```
```cpp
int main()
{
    int T;
    cin >> T;

    // Input data T times
    vector<int> N;
    vector<vector<string>> C;
    for (int t = 0; t < T; t++)
    {
        int ni;
        cin >> ni;
        N.push_back(ni);

        // Make vector C that has n[t] rows
        vector<string> C2;
        for (int n = 0; n < N[t]; n++)
        {
            string temp;
            cin >> temp;
            C2.push_back(temp);
        }
        C.push_back(C2);
    }

    // Operate T times
    for (int t = 0; t < T; t++)
    {
        // Count '.' to be replaced to X : by row and column (-1 if O exists at leat one)
        vector<int> row (N[t], 0), col (N[t], 0);
        int rowMax = 0, colMax = 0;
        for (int i = 0; i < N[t]; i++)
        {
            // By row : i = row, j = col
            for (int j = 0; j < N[t]; j++)
            {
                if (C[t][i][j] == '.')
                {
                    row[i]++;
                    if (row[i] > rowMax) rowMax = row[i];
                }
                else if (C[t][i][j] == 'O')
                {
                    row[i] = -1;
                    break;
                }
            }

            // By Column : i = col, j = row
            for (int j = 0; j < N[t]; j++)
            {
                if (C[t][j][i] == '.')
                {
                    col[i]++;
                    if (col[i] > colMax) colMax = col[i];
                }
                else if (C[t][j][i] == 'O')
                {
                    col[i] = -1;
                    break;
                }
            }
        }

        // Find the minimum turn number for X to win
        int answer1 = min(rowMax, colMax);
    
        // Find cases that have the same number with answer1
        int answer2 = 0;
        for (int i = 0; i < N[t]; i++)
        {
            if (row[i] == answer1) answer2++;
            if (col[i] == answer1) answer2++;
        }

        // Output
        if (answer2 > 0) cout << "Case #" << t + 1 << ": " << answer1 << ' ' << answer2 << endl;
        else cout << "Case #" << t + 1 << ": Impossible" << endl;
    }

    return 0;
}
```
> Wrong Answer

#### C++ - Trial 2
```cpp
    ……
    // Operate T times
    for (int t = 0; t < T; t++)
    {
        // Count '.' to be replaced to X : by row and column (-1 if O exists at leat one)
        ……
        int rowMin = N[t], colMin = N[t];
        for (int i = 0; i < N[t]; i++)
        {
            // By row : i = row, j = col
            ……
            if (row[i] > 0 && row[i] < rowMin) rowMin = row[i];

            // By Column : i = col, j = row
            ……
            if (col[i] > 0 && col[i] < colMin) colMin = col[i];

            // Special case : place one X that satisfies winning condition at the same time by row and column
            for (int j = 0; j < N[t]; j++) if (C[t][i][j] == '.' && row[i] == 1 && col[j] == 1) col[i]--;
        }
        ……
    }
    ……
```
> Wrong Answer
```cpp
/* Wrong Case
13
OX..O.XXOX..X
O.OO..XX....X
...OO.XX.O..X
...O..XX..OOX
..O...XXOOOOX
XXXXXXX.XXXXX
.X..O.XXOOOOX
.OO..OXX..OX.
...OO.XX.OO.X
.O.O..XX..O.X
OO..XOOX...OX
..X..OOX..O.X
OOOOOO.XO.OOX

My Output :
1 3

Correct Output :
1 2
*/
```

#### C++ - Trial 3
```cpp
    ……
    // Operate T times
    for (int t = 0; t < T; t++)
    {
        ……
        // Find cases that have the same number with answer1
        int answer2 = 0;
        for (int i = 0; i < N[t]; i++)
        {
            if (row[i] == answer1) answer2++;
            if (col[i] == answer1) answer2++;

            // Special case : place one X that satisfies winning condition at the same time by row and column
            for (int j = 0; j < N[t]; j++) if (C[t][i][j] == '.' && row[i] == 1 && col[j] == 1) answer2--;
        }
        ……
    }
    ……
```
> Accepted

## [Problem C1: Gold Mine - Chapter 1 (21pt)](#list)

not attempted


## [Problem C2: Gold Mine - Chapter 2 (36pt)](#list)

not attempted