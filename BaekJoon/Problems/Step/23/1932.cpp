// [BOJ] 단계별로 풀어보기 > 16. 동적 계획법 1

// 1932. 정수 삼각형 (The Triangle)
// 2022.04.24

/* Sample input & output data
5
7
3 8
8 1 0
2 7 4 4
4 5 2 6 5

30
*/


#include <iostream>
#include <vector>
#define endl '\n'

using namespace std;

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