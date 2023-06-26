// [BOJ] 단계별로 풀어보기 > 16. 동적 계획법 1

// 2156. 포도주 시식
// 2022.04.29

/* Sample input & output data
6
6
10
13
9
8
1

33
*/


#include <iostream>
#include <vector>
#include <algorithm>                                    // max()
#define endl '\n'

using namespace std;

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