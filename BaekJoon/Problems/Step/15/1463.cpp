// 1463. 1로 만들기

/* Sample input & output data
10

3
*/


#include <iostream>
#include <vector>
#define endl '\n'

using namespace std;

int main()
{
    // Input data
    int x = 0;
    cin >> x;

    // Dynamic Programming
    vector<vector<int>> dp;
    dp.push_back(vector<int> {x});
    int min = x, count = 0;

    while (min > 1)
    {
        vector<int> d2;                                                         // vector vs set?

        for (int i = 0; i < dp[count].size(); i++)
        {
            if (dp[count][i] % 3 == 0) d2.push_back(dp[count][i] / 3);
            if (dp[count][i] % 2 == 0) d2.push_back(dp[count][i] / 2);
            d2.push_back(dp[count][i] - 1);
        }

        count++;

        for (int i = 0; i < d2.size(); i++) if (d2[i] < min) min = d2[i];

        // test
        // cout << count << " (min : " << min << ") : ";
        // for (int i = 0; i < d2.size(); i++) cout << d2[i] << ' ';
        // cout << endl;

        dp.push_back(d2);
    }

    cout << count << endl;

    return 0;
}