// [BOJ] 단계별로 풀어보기 > 16. 동적 계획법 1

// 1912. 연속합
// 2022.08.26

/* Sample input & output data
10
10 -4 3 1 5 6 -35 12 21 -1
33

10
2 1 -4 3 4 -4 6 5 -5 1
14

5
-1 -2 -3 -4 -5
-1
*/


#include <iostream>
#include <vector>

using namespace std;

#define endl '\n'

int main()
{
    int n;
    cin >> n;

    // Input data
    vector<int> v;
    int el;
    for (int i = 0; i < n; i++)
    {
        cin >> el;
        v.push_back(el);
    }

    // DP
    vector<int> dp = {v[0]};
    int sumMax = v[0], temp;
    for (int i = 1; i < n; i++)
    {
        if (dp[i-1] > 0) dp.push_back(dp[i-1] + v[i]);
        else dp.push_back(v[i]);

        if (dp[i] > sumMax) sumMax = dp[i];

        // test
        // cout << "i : " << i << "\tdp[i-1] : " << dp[i-1] << "\tv[i] : " << v[i] << "\tdp[i] : " << dp[i] << "\tsumMax : " << sumMax << endl;
    }

    // Output
    cout << sumMax << endl;

    return 0;
}