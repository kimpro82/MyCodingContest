#include <iostream>

using namespace std;

/* Sample input & output data
3

6
*/

int main()
{
    int a;
    cin >> a;

    int sum = 0;
    for (int i = 1; i <= a; i++)
    {
        sum += i;
    }
    cout << sum << endl;

    return 0;
}