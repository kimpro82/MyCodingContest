// AtCoder Beginner Contest 220
// 2021-09-26(Sun) 21:00 - 22:40, 100 minutes

// D - FG operation

/* Sample Input & Output
3
2 7 6

1
0
0
0
2
1
0
0
0
0

5
0 1 2 3 4

6
0
1
1
4
0
1
1
0
2
*/


#include <iostream>
#include <vector>
#include <algorithm>

#define endl '\n'

using namespace std;

int main()
{
    // Input data
    int N, a;
    cin >> N;
    vector<int> A;
    for (int n = 0; n < N; n++)
    {
        cin >> a;
        A.push_back(a);
    }
    int mod = 998244353;

    // Count : Dynamic Programming
    vector<vector<int>> dp(N, vector<int> (10, 0));
    for (int n = 0; n < N; n++)
    {
        // test
        cout << A[n] << ' ';

        // n == 0
        if (n == 0)
        {
            for (int i = 0; i < 2; i++) dp[0][A[i]]++;
        }
        // n >= 1
        else
        {
            for (int r = 0; r < 10; r++)
            {
                if (dp[n-1][r] != 0)
                {
                    dp[n][(dp[n-1][r] + A[n]) % 10]++;
                    dp[n][(dp[n-1][r] * A[n]) % 10]++;
                    dp[n][r] %= mod;
                }
            }
        }

        // test
        for (int r = 0; r < 10; r++)
        {
            cout << dp[n][r] << ' ';
        }
        cout << endl;
    }

    // Output
    for (int r = 0; r < 10; r++) cout << dp[N-1][r] << ' ';
    cout << endl;

    return 0;
}