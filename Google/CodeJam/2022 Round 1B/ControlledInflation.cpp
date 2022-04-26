/* Sample Input & Output
2
3 3
30 10 40
20 50 60
60 60 50
5 2
1 1000000000
500000000 1000000000
1 1000000000
500000000 1
1 1000000000

Case #1: 110
Case #2: 4999999996
*/


#include <iostream>
#include <vector>
#include <cmath>
#define endl '\n'

using namespace std;
using ll = long long;

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
        // Input
        int N, P;
        cin >> N >> P;

        // Dynamic Programming
        vector<vector<ll>> dp;
        ll temp, min, max, dist, sum1, sum2;
        dp.push_back(vector<ll> {0, 0, 0, 0, 0});                                                             // i = 0
        for (int n = 1; n <= N; n++)
        {
            min = 1000000000, max = 0;
            for (int p = 1; p <= P; p++)
            {
                cin >> temp;

                if (temp < min) min = temp;
                if (temp > max) max = temp;
            }
            dist = max - min;
            sum1 = (dp[n-1][3] + abs(max - dp[n-1][0]) <= dp[n-1][4] + abs(max - dp[n-1][1])) ? dp[n-1][3] + abs(max - dp[n-1][0]) : dp[n-1][4] + abs(max - dp[n-1][1]);
            sum1 += dist;
            sum2 = (dp[n-1][3] + abs(min - dp[n-1][0]) <= dp[n-1][4] + abs(min - dp[n-1][1])) ? dp[n-1][3] + abs(min - dp[n-1][0]) : dp[n-1][4] + abs(min - dp[n-1][1]);
            sum2 += dist;
            // crazy~~~

            // test
            // printf("min : %lld, max : %lld, dist : %lld, sum1 : %lld, sum2 : %lld\n", min, max, dist, sum1, sum2);

            dp.push_back(vector<ll> {min, max, dist, sum1, sum2});
        }

        // Output
        ll ans = (sum1 <= sum2) ? sum1 : sum2;
        cout << "Case #" << t << ": " << ans << endl;
    }

    return 0;
}