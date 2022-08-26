// [BOJ] 단계별로 풀어보기 > 16. 동적 계획법 1

// 1904. 01타일
// 2022.04.24

/* Sample input & output data
4

5
*/


#include <iostream>
#include <vector>
#define endl '\n'

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> dp {0, 1, 2};

    // Find the recurrence relation!
    for (int i = 3; i <= n; i++) dp.push_back((dp[i - 2] + dp[i - 1]) % 15746);     // pass if n < 3
                                                                                    // don't forget the modulo!
    cout << dp[n] << endl;

    return 0;
}