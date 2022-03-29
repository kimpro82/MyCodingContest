// [BOJ] 단계별로 풀어보기 > 9. 기본 수학 2

// 3053. HERMAN(택시 기하학)

/* Sample input & output data
1
3.141593
2.000000

21
1385.442360
882.000000

42
5541.769441
3528.000000
*/

#define _USE_MATH_DEFINES   // for using the exact pi value(M_PI)

#include <iostream>
#include <cmath>            // pow(), M_PI

using namespace std;
#define endl '\n'

int main()
{
    int r;
    cin >> r;

    double euclidian = M_PI * pow(r, 2);            // find the exact value of M_PI : F12 (VS Code)
    double taxicab = 2 * pow(r, 2);

    cout << fixed;
    cout.precision(6);
    cout << euclidian << '\n' << taxicab << endl;

    return 0;
}