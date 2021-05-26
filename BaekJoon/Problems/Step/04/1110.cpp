/* Sample input & output data
26
55
1
0

4 3 60 1 (vertically)
*/

#include <iostream>

using namespace std;

int main()
{
    int n, a, b, ab, t = 0;         // 0 <= n <= 99, n = a * 10 + b, ab = a + b
    cin >> n ;                      // n = 26

    ab = n;                         // ab = 26

    while (true)
    {
        a = ab / 10;                // a  = 2    6
        b = ab % 10;                // b  = 6    8
        ab = a + b;                 // ab = 8   14

        if (ab < 10)
        {
            ab += b * 10;           // ab = 68  

        } else
        {
            ab = b * 10 + ab % 10;  // ab =     84
        }

        t++;

        // Test
        // cout << "n: " << n << " t: " << t << " a: " << a << " b: " << b << " ab: " << ab << '\n';

        if (n == ab)
        {
            break;
        }
    }

    cout << t << '\n';

    return 0;
}