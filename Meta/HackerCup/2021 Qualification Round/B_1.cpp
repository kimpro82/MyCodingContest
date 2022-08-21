// Facebook Hacker Cup 2021 > Qualification Round
// 2021.08.28 02:00, 72 hrs

// Problem B: Xs and Os

/* Sample Input & Output
8
2
XO
..
2
X.
.O
3
...
...
...
3
.OX
X..
..O
3
OXO
X.X
OXO
3
.XO
O.X
XO.
4
X...
.O.O
.XX.
O.XO
5
OX.OO
X.XXX
OXOOO
OXOOO
XXXX.

Case #1: 1 1
Case #2: 1 2
Case #3: 3 6
Case #4: 2 2
Case #5: 1 1
Case #6: Impossible
Case #7: 2 2
Case #8: 1 2
*/


#include <iostream>
#include <vector>

using namespace std;
#define endl '\n'

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