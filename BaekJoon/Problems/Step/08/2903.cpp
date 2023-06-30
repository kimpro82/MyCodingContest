// 2903. PLANINA (중앙 이동 알고리즘)
// 2023.06.28

/* Sample input & output data
1
9

2
25

5
1089
*/


#include <iostream>

#define endl '\n'

using namespace std;

int main()
{
    // Input : 1 <= N <= 15
    int N;
    cin >> N;

    // Operate : avoid pow() because it returns wrong values in MinGWs
    int quad = 1;
    for (int i = 0; i < N; i++) quad *= 2;
    int ans = (quad + 1) *  (quad + 1);                     // max < 2.1b when N = 15

    // Output
    cout << ans << endl;

    return 0;
}
