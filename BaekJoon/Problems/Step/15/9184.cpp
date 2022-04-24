// 9184. Function Run Fun

/* Sample input & output data
1 1 1
2 2 2
10 4 6
50 50 50
-1 7 18
-1 -1 -1

w(1, 1, 1) = 2
w(2, 2, 2) = 4
w(10, 4, 6) = 523
w(50, 50, 50) = 1048576
w(-1, 7, 18) = 1
*/


#include <iostream>
#include <vector>
#define endl '\n'

using namespace std;

int main()
{
    int a, b, c, temp;
    while (cin >> a >> b >> c)
    {
        if (a == -1 && b == -1 && c == -1) return 0;

        cout << "w(" << a << ", " << b << ", " << c << ") = ";  // to avoid affection from the below if statement
        // cout << '\n';                                        // for test

        if (a <= 0 || b <= 0 || c <= 0)                         // start from [0][0][0]
        {
            a = 0;
            b = 0;
            c = 0;
        }
        else if (a > 20 || b > 20 || c > 20)                    // end at [20][20][20]
        {
            a = 20;
            b = 20;
            c = 20;
        }

        vector<vector<vector<int>>> dp;
        for (int i = 0; i <= a; i++)
        {
            vector<vector<int>> d2;

            for (int j = 0; j <= b; j++)
            {
                vector<int> d3;

                for (int k = 0; k <= c; k++)
                {
                    if (i == 0 || j == 0 || k == 0) temp = 1;
                    else if (i < j && j < k) temp = d3[k-1] + d2[j-1][k-1] - d2[j-1][k];                // dp[i][j][k-1] + dp[i][j-1][k-1] - dp[i][j-1][k] causes a run-time error
                    else temp = dp[i-1][j][k] + dp[i-1][j-1][k] + dp[i-1][j][k-1] - dp[i-1][j-1][k-1];

                    // test
                    // cout << "i: " << i << " j: " << j << " k: " << k << " w: " << temp << endl;

                    d3.push_back(temp);
                }

                d2.push_back(d3);
            }

            dp.push_back(d2);
        }

        cout << dp[a][b][c] << endl;
    }

    return 0;
}