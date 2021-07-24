// 1712. 손익분기점

/* Sample input & output data
1000 70 170
11

3 2 1
-1

2100000000 9 10
2100000001
*/


#include <iostream>

using namespace std;
#define endl '\n'

int main()
{
    int a, b, c;
    cin >> a >> b >> c;

    int margin = c - b;
    if (c - b > 0)                      // Find if price(c) - variable cost(b) > 0
    {
        cout << a / margin + 1 << endl;
    } else                              // Never can reach BEP
    {
        cout << -1 << endl;
    }

    return 0;
}