#include <iostream>

using namespace std;

/* Sample input & output data
5

5
4
3
2
1
*/

int main()
{
    // make cin/cout faster
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int a;
    cin >> a;

    for (int i = a; i >= 1; i--)
    {
        cout << i << '\n';              // \n is faster than endl
    }

    return 0;
}