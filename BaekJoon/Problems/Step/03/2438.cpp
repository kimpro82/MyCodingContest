#include <iostream>

using namespace std;

/* Sample input & output data
5

*
**
***
****
*****
*/

int main()
{
    int a;
    cin >> a;

    for (int i = 1; i <= a; i++)
    {
        // cout << '*' * i << endl;        // calculate ascii code number(42) * i
        for (int j = 1; j <= i; j++)
        {
            cout << '*' ;
        }
        cout << '\n' ;
    }

    return 0;
}