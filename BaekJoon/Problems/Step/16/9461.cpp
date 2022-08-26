// [BOJ] 단계별로 풀어보기 > 16. 동적 계획법 1

// 9461. 파도반 수열 (Padovan Sequence)
// 2022.04.24

/* Sample input & output data
2
6
12

3
16
*/


#include <iostream>
#include <vector>
#define endl '\n'

using namespace std;
using ll = long long;

int main()
{
    int t;
    ll n;                                                               // int causes a run-time error
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        cin >> n;

        // Dynamic Programming
        vector<ll> dp {0, 1, 1, 1, 2, 2};
        for (int j = 6; j <= n; j++)
        {
            dp.push_back(dp[j-1] + dp[j-5]);                            // pass if n < 5

            // test
            // printf("%d %d %d %d\n", j, dp[j-1], dp[j-5], dp[j]);     // %lld runs strange
        }

        // Output
        cout << dp[n] << endl;
    }

    return 0;
}