// AtCoder Beginner Contest 207
// 2021-06-26(Sat) 21:00 - 22:40, 100 minutes

// B - Hydrate

/* Sample Input & Output
5 2 3 2
2

6 9 2 3
-1
*/


#include <iostream>

using namespace std;

int main()
{
    long long a, b, c, d;                   // 1 <= a, b, c, d <= 10^5
    cin >> a >> b >> c >> d;

    long long cyan = a, red = 0, n = 0;     // n : number of the operation
    while (true)
    {
        if (cyan <= red * d)
        {
            break;
        } else
        {
            if (b >= c * d)                 // something inefficient ……
            {
                n = -1;
                break;
            }
            cyan += b;
            red += c;
            n++;
        }

        // test
        cout << n << " " << cyan << " " << red * d << " " << cyan - red * d << endl;
    }

    cout << n << endl;

    return 0;
}