// AtCoder Beginner Contest 211
// 2021-07-24(Satn) 21:00 - 22:40, 100 minutes

// C - chokudai

/* Sample Input & Output
chchokudai
3

atcoderrr
0

chokudaichokudaichokudai
45
*/


#include <iostream>
#include <string>
#include <vector>

using namespace std;
#define endl '\n'

int main()
{
    // Indput data
    string c = "chokudai", s;
    // cout << c[1] << endl;            // test : ok
    cin >> s;
    int cSize = c.size(), sSize = s.size();
    int mod = 1e9 + 7;

    // test
    cout << "  ";
    for (int k = 0; k < sSize; k++) cout << s[k] << ' ';
    cout << endl;

    // Count : Dynamic Programming
    vector<vector<int>> dp(cSize, vector<int> (sSize, 0));
    for (int i = 0; i < cSize; i++)
    {
        // test
        cout << c[i] << ' ';

        for (int j = 0; j < sSize; j++)
        {
            if (i == 0)
            {
                if (j == 0)
                {
                    if (c[i] == s[j]) dp[i][j] = 1;
                    else dp[i][j] = 0;
                }
                else
                {
                    if (c[i] == s[j]) dp[i][j] = (dp[i][j-1] + 1) % mod;
                    else dp[i][j] = dp[i][j-1] % mod;
                }
            }
            else if (j == 0) dp[i][j] = 0;
            else if (c[i] == s[j]) dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % mod;
            else dp[i][j] = dp[i][j-1] % mod;

            // test
            cout << dp[i][j] << ' ';
        }

        // test
        cout << endl;
    }

    // Output
    cout << dp[cSize - 1][sSize - 1] << endl;

    return 0;
}