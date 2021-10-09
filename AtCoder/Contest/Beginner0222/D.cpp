// AtCoder Beginner Contest 222
// 2021-10-09(Sat) 21:00 - 22:40, 100 minutes

// D - Between Two Arrays

/* Sample Input & Output
2
1 1
2 3
5

3
2 2 2
2 2 2
1

10
1 2 3 4 5 6 7 8 9 10
1 4 9 16 25 36 49 64 81 100
978222082
*/


#include <iostream>
#include <vector>

#define endl '\n'

using namespace std;

int main()
{
    int N, mod = 998244353;
    cin >> N;

    vector<int> A;
    vector<int> B;
    int temp;
    for (int n = 0; n < N; n++)
    {
        cin >> temp;
        A.push_back(temp);
    }
    for (int n = 0; n < N; n++)
    {
        cin >> temp;
        B.push_back(temp);
    }

    // Dynamic Programming ?
    vector<vector<int>> dp(3000, vector<int> (3000, 0));
    int cnt = 0;
    for (int i = 0; i < N; i++)
    {
        // test
        cout << i << ' ';

        for (int j = 0; j < 3000; j++)
        {
            if (i == 0)
            {
                if (j == 0) if (j >= A[i] && j <= B[i]) dp[i][j] = 1;
            }

        }

        // test
        cout << endl;
    }

    return 0;
}