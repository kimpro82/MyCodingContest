// 2839. ŠEĆER

/* Sample input & output data
18
4

4
-1

6
2

0
3

11
3
*/


#include <iostream>

using namespace std;
#define endl '\n'

int main()
{
    int N;
    cin >> N;       // 3 <= n <= 5000

    int bag3 = 0;
    bool rest = true;
    for (int i = 0; i <= N / 3; i++)
    {
        if ((N - i * 3) % 5 == 0)
        {
            bag3 = i;
            rest = false;
            break;
        }
    }

    // Test
    // cout << bag3 << " " << bag3 * 3 << " " << (N - bag3 * 3) << endl;

    // Output
    if (rest == false)
    {
        cout << bag3 + (N - bag3 * 3) / 5 << endl;
    } else
    {
        cout << -1 << endl;
    }

    return 0;
}