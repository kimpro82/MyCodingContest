#include <iostream>

using namespace std;

/* Sample input & output data
5
1 1
2 3
3 4
9 8
5 2

2
5
7
17
7
*/

int main()
{
    int t, a, b;
    cin >> t;

    for (int i = 1; i <= t; i++)
    {
        cin >> a >> b;
        cout << a + b << endl;
    }

    return 0;
}