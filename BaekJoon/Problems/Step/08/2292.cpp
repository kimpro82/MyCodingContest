// 2292. 벌집

/* Sample input & output data
13
3
*/


#include <iostream>

using namespace std;
#define endl '\n'

int main()
{
    int a;
    cin >> a;

    int move = 0;
    while (a > 1)
    {
        move++;
        a -= 6 * move;

        // test
        // cout << a << " " << move << endl;
    }

    cout << move + 1 << endl;

    return 0;
}