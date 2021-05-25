#include <iostream>

using namespace std;

/* Sample input & output data
5
1 1
12 34
5 500
40 60
1000 1000

2
46
505
100
2000
*/

int main()
{
    // make cin/cout faster
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int t, a, b;
    cin >> t;

    for (int i = 1; i <= t; i++)
    {
        cin >> a >> b;
        cout << a + b << '\n';          // \n is faster than endl
    }

    return 0;
}