#include <iostream>

using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;           // 12 5, 9 -13
    // A given condition : Neither of the two coordinates will be 0.

    if (a > 0 && b > 0)
    {
        cout << 1 << endl;
    } else if (a < 0 && b > 0)
    {
        cout << 2 << endl;
    } else if (a < 0 && b < 0)
    {
        cout << 3 << endl;
    } else
    {
        cout << 4 << endl;
    }

    return 0;
}