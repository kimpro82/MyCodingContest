#include <iostream>

using namespace std;

/* Sample input & output data
5

1
2
3
4
5
*/

int main()
{
    // make cin/cout faster
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int a;
    cin >> a;

    for (int i = 1; i <= a; i++)
    {
        cout << i << '\n';              // \n is faster than endl
    }

    return 0;
}