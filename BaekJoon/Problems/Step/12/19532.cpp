// 19532. 수학은 비대면강의입니다
// 2023.07.06

/* Sample input & output data
1 3 -1 4 1 7

2 -1
*/


#include <iostream>

#define endl '\n'

using namespace std;


int main()
{
    // Input
    int a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;

    // Operate : Brute Force
    int x, y;
    for (int i = -999; i <= 999; i++)
    {
        for (int j = -999; j <= 999; j++)
        {
            if (a * i + b * j == c && d * i + e * j == f)
            {
                x = i;
                y = j;
                break;
            }
        }
    }

    // Output
    cout << x << ' ' << y << endl;

    return 0;
}
