// [BOJ] 단계별로 풀어보기 > 16. 동적 계획법 1

// 11053. 가장 긴 증가하는 부분 수열
// 2022.05.02

/* Sample input & output data
6
10 20 10 30 20 50

4
*/


#include <iostream>
#include <vector>
#include <algorithm>                                            // sort()
#define endl '\n'

using namespace std;

int main()
{
    // Input data
    int n, temp;
    cin >> n;

    vector<int> a;
    a.push_back(0);                                             // i == 0
    for (int i = 1; i <= n; i++)
    {
        cin >> temp;
        a.push_back(temp);
    }

    // Dynamic Programming
    vector<vector<int>> dp;
    dp.push_back(vector<int> (n+1, 0));                         // i == 0
    for (int i = 1; i <= n; i++)
    {
        vector<int> currentMax (n+1, 0);                        // memo the current max value, don't need a vector but it's for test
        vector<int> row (n+1, 0);                               // j == 0 : row[0] = 0
        for (int j = 1; j <= i; j++)                            // j >= 1
        {
            if (j < i)
            {
                if (a[j] > currentMax[j-1] && a[j] < a[i])
                {
                    row[j] = row[j-1] + 1;
                    currentMax[j] = a[j];
                }
                else
                {
                    row[j] = row[j-1];
                    currentMax[j] = currentMax[j-1];
                }
            }
            else                                                // j == i : It's the max(final) value
            {
                row[j] = row[j-1] + 1;
                currentMax[j] = a[j];
            }

        }
        dp.push_back(row);

        // test
        cout << i << ' ' << a[i] << " :";
        for (int j = 1; j <= i; j++) cout << ' ' << row[j] << ' ' << currentMax[j] <<  " /";
        cout << endl;
    }

    // Find the max value among dp[n][n] : check only diagonal elements
    int maxValue = 0;
    for (int i = 1; i <= n; i++) if (dp[i][i] > maxValue) maxValue = dp[i][i];

    // Output
    cout << maxValue << endl;

    return 0;
}