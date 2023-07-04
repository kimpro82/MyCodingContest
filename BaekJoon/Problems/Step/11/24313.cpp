// 24313. 알고리즘 수업 - 점근적 표기 1
// 2023.07.04

/* Sample input & output data
7 7
8
10

35
1
*/


#include <iostream>

#define test
#define endl '\n'

using namespace std;

int main()
{
    // Input
    int a1, a0, c, n0;
    cin >> a1 >> a0 >> c >> n0;

    // Output
    int ans = 0;
    if (a1 <= c && a1 * n0 + a0 <= c * n0 ) ans = 1;
    cout << ans << endl;

    return 0;
}
