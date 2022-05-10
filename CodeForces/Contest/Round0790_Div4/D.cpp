// Codeforces Round #790 (Div. 4)
// 2022.05.10 23:45, 2 hrs

// D. X-Sum

/* Sample Input & Output
4
4 4
1 2 2 1
2 4 2 4
2 2 3 1
2 4 2 4
2 1
1
0
3 3
1 1 1
1 1 1
1 1 1
3 3
0 1 1
1 0 1
1 1 0

20
1
5
3
*/


#include <iostream>
#include <vector>
#include <cmath>

#define endl '\n'

using namespace std;

int main()
{
    int t;
    cin >> t;
 
    for (int i = 0; i < t; i++)
    {
        // Input data
        int n, m;                                           // 1 <= n, m <= 200
        cin >> n >> m;
 
        vector<vector<int>> a = {vector<int> (m, 0)};
        int temp;
        for (int j = 0; j < n; j++)
        {
            vector<int> a2 = {0};
            for (int k = 0; k < m; k++)
            {
                cin >> temp;
                a2.push_back(temp);
            }
            a.push_back(a2);
        }
        
        // Solve
        vector<int> sum1 (n+m, 0);
        vector<int> sum2 (n+m, 0);
        for (int j = 1; j <= n; j++)
        {
            for (int k = 1; k <= m; k++)
            {
                sum1[n-j-1+k] += a[j][k];
                sum2[j+k-1] += a[j][k];

                // test
                printf("%d %d / %d / %d %d / %d %d\n", j, k, a[j][k], n-j-1+k, j+k-1, sum1[n-j-1+k], sum2[j+k-1]);
            }
        }
        int max = 0;
        for (int j = 0; j < n+m-1; j++) for (int k = 0; k < n+m-1; k++) if (j % 2 == k % 2 && sum1[j] + sum2[k]> max) max = sum1[j] + sum2[k];

        // Output
        cout << max << endl;
    }

    return 0;
}