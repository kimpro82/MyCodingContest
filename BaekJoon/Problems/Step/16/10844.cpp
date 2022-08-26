// [BOJ] 단계별로 풀어보기 > 16. 동적 계획법 1

// 10844. 쉬운 계단 수
// 2022.04.26

/* Sample input & output data
2

17
*/


#include <iostream>
#include <vector>
#define endl '\n'

using namespace std;
using ll = long long;

int main()
{
    // Input data
    int n;
    cin >> n;                                                                       // 1 <= n <= 100

    // Dynamic Programming
    vector<vector<ll>> dp;
    // i == 0
    dp.push_back(vector<ll> (10, 0));
    // i == 1
    dp.push_back(vector<ll> (10, 1));
    dp[1][0] = 0;

    for (int i = 2; i <= n; i++)
    {
        vector<ll> d2 (10, 0);

        for (int j = 0; j < 10; j++)
        {
            if (j == 0) d2[0] = dp[i-1][1];
            else if (j < 9) d2[j] = (dp[i-1][j-1] + dp[i-1][j+1]) % 1000000000;     // don't forget the modulo!
            else  d2[9] = dp[i-1][8];
        }

        dp.push_back(d2);

        // test
        // cout << n << " :";
        // for (int j = 0; j < 10; j++) cout << ' ' << d2[j];
        // cout << endl;
    }

    // Output
    ll sum = 0;
    for (int i = 0; i < dp[n].size(); i++) sum += dp[n][i];
    cout << sum % 1000000000 << endl;

    return 0;
}