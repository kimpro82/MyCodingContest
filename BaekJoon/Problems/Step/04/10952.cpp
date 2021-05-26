/* Sample input & output data
1 1
2 3
3 4
9 8
5 2
0 0

2 5 7 17 7 (vertically)
*/

#include <iostream>

using namespace std;

int main()
{
    int a, b;

    while (true)
    {
        cin >> a >> b;
        if (a != 0 || b != 0)       // Readability? vs (a == 0 && b == 0)
        {
            cout << a + b << endl;            
        } else
        {
            break;
        }
    }

    return 0;
}