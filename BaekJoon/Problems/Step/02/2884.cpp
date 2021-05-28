#include <iostream>

using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;           // 10 10, 0 30, 23 40

    if (b < 45)
    {
        a--;
        b += 60;
    }
    if (a < 0)
    {
        a += 24;
    }

    cout << a << " " << b - 45 << endl;

    return 0;
}