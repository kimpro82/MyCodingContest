// [BOJ] 단계별로 풀어보기 > 16. 동적 계획법 1

// 2579. 계단 오르기
// 2022.04.24

/* Sample input & output data
6
10
20
15
25
10
20

75
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