// [BOJ] 단계별로 풀어보기 > 16. 동적 계획법 1 (Excluded)

// 1003. 피보나치 함수

/* Sample input & output data
2
6
22

5 8
10946 17711
*/


#include <iostream>
#include <vector>
#define endl '\n'

using namespace std;

int main()
{
    int t, n;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        cin >> n;

        // Count : Dynamic Programming
        vector<pair<int, int>> dp;
        for (int j = 0; j <= n; j++)
        {
            if (j == 0) dp.push_back(make_pair(1, 0));
            else if (j == 1) dp.push_back(make_pair(0, 1));
            else dp.push_back(make_pair(dp[j - 1].second, dp[j - 2].second + dp[j - 1].second));    // not ->second, but .second

            // test
            // cout << n << ' ' << j << ' ' << dp[j].first << ' ' << dp[j].second << endl;
        }

        // Output
        cout << dp[n].first << ' ' << dp[n].second << endl;
    }

    return 0;
}