// AtCoder Beginner Contest 208
// 2021-07-04(Sun) 21:00 - 22:40, 100 minutes

// A - Rolling Dice

/* Sample Input & Output
2 11
Yes

2 13
12

100 600
Yes
*/


#include <iostream>

using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;

    if (a * 6 >= b && a <= b)
    {
        cout << "Yes" << '\n';
    } else
    {
        cout << "No" << '\n';
    }

    return 0;
}