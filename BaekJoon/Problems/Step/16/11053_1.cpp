// [BOJ] 단계별로 풀어보기 > 16. 동적 계획법 1

// 11053. 가장 긴 증가하는 부분 수열
// 2022.04.30

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

    // Make an additional vector b that is sorted a
    vector<int> b = a;
    sort(b.begin(), b.end());

    // Dynamic Programming
    vector<vector<int>> dp;
    dp.push_back(vector<int> (n+1, 0));                         // i == 0
    for (int i = 1; i <= n; i++)
    {
        vector<int> row (n+1, 0);
        vector<int> currentMax (n+1, 0);                        // memo the current max value, don't need a vector but it's for test
        for (int j = 1; j < n; j++)                             // j == 0 : row[0] = 0
        {
            if (a[j] > currentMax[j-1] && a[j] <= b[i])
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
        if (a[n] > currentMax[n-1])                             // j == n
        {
            row[n] = row[n-1] + 1;
            currentMax[n] = a[n];
        }
        else
        {
            row[n] = row[n-1];
            currentMax[n] = currentMax[n-1];
        }
        dp.push_back(row);

        // test
        cout << i << ' ' << b[i] << " :";
        for (int j = 1; j <= n; j++) cout << ' ' << row[j] << ' ' << currentMax[j] <<  " /";
        cout << endl;
    }

    // Find the max value among dp[][n]
    int maxValue = 0;
    for (int i = 1; i <= n; i++) if (dp[i][n] > maxValue) maxValue = dp[i][n];

    // Output
    cout << maxValue << endl;

    return 0;
}

// Wrong : counterexample
// 4
// 40 20 40 10