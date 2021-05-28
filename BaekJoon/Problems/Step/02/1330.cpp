#include <iostream>

using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;          // 1 2, 10 2, 5 5

    if (a > b)
    {
        cout << ">" << endl;
    } else if (a < b)
    {
        cout << "<" << endl;
    } else
    {
        cout << "==" << endl;
    }

    return 0;
}