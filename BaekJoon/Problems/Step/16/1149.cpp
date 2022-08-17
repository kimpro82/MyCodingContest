// 1149. RGB거리

/* Sample input & output data
3
26 40 83
49 60 57
13 89 99

96
*/


#include <iostream>
#include <vector>
#include <algorithm>                        // min()
#define endl '\n'

using namespace std;

int main()
{
    int n, r, g, b;
    cin >> n;

    // Dynamic Programming
    vector<vector<int>> dp;
    dp.push_back(vector<int> {0, 0, 0});    // when i == 0
    for (int i = 1; i <= n; i++)
    {
        cin >> r >> g >> b;

        vector<int> temp;
        temp.push_back(r + min(dp[i-1][1], dp[i-1][2]));
        temp.push_back(g + min(dp[i-1][0], dp[i-1][2]));
        temp.push_back(b + min(dp[i-1][0], dp[i-1][1]));
        dp.push_back(temp);
    }

    // Output
    cout << min(min(dp[n][0], dp[n][1]), dp[n][2]) << endl;

    return 0;
}