#include <iostream>

using namespace std;

int main()
{
    int a;
    cin >> a;                   // 99, 82, 79, 60, 37

    if (a >= 90)
    {
        cout << "A" << endl;
    } else if (a >= 80)
    {
        cout << "B" << endl;
    } else if (a >= 70)
    {
        cout << "C" << endl;
    } else if (a >= 60)
    {
        cout << "D" << endl;
    } else
    {
        cout << "F" << endl;
    }

    return 0;
}