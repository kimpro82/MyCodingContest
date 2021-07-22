// [BOJ] 단계별로 풀어보기 > 9. 기본 수학 2

// 1002. 터렛

/* Sample input & output data
3
0 0 13 40 0 37
0 0 3 0 7 4
1 1 1 1 1 5

2
1
0
*/


#include <iostream>
#include <cmath>        // pow()

using namespace std;
#define endl '\n'

int main()
{
    int T;
    cin >> T;

    // T Test cases
    for (int t = 0; t < T; t++)
    {
        // Input data
        int x1, y1, r1, x2, y2, r2;
        cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

        // Find square of distance : sqrt() can cause error
        int distanceSquare = (int) (pow(x2 - x1, 2) + pow(y2 - y1, 2));
        int rangeSquare1 = (int) pow(r1 + r2, 2), rangeSquare2 = (int) pow(r2 - r1, 2);

        // test
        cout << distanceSquare << ' ' << rangeSquare1 << ' ' << rangeSquare2 << endl;

        // Output
        if (distanceSquare == 0 && rangeSquare2 == 0) cout << -1 << endl;   // infinitely cross
        else if (distanceSquare > rangeSquare1 || distanceSquare < rangeSquare2) cout << 0 << endl;
        else if (distanceSquare == rangeSquare1 || distanceSquare == rangeSquare2 ) cout << 1 << endl;
        else cout << 2 << endl;
    }

    return 0;
}