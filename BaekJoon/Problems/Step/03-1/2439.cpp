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
        for (int j = 1; j <= a; j++)
        {
            if (i < a - j + 1)
            {
                cout << ' ' ;
            } else {
                cout << '*' ;
            }
        }
        cout << '\n' ;
    }

    return 0;
}