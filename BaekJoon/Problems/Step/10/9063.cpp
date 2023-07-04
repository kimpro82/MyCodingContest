// 9063. 대지
// 2023.07.02

/* Sample input & output data
3
20 24
40 21
10 12

360
*/


#include <iostream>

// #define test
#define endl '\n'

using namespace std;

int main()
{
    // Input
    int n;
    cin >> n ;;

    int x, y;
    int xMin = 10000, yMin = 10000, xMax = -10000, yMax = -10000;
    for (int i = 0; i < n; i++)
    {
        cin >> x >> y;
        if (x < xMin) xMin = x;
        if (x > xMax) xMax = x;
        if (y < yMin) yMin = y;
        if (y > yMax) yMax = y;
    }

    // test
    #ifdef test
        printf("xMax:%d, xMin:%d, yMax:%d, yMin:%d\n", xMax, xMin, yMax, yMin);
        printf("xMax-xMin:%d, yMAx-yMin:%d\n", xMax-xMin, yMax-yMin);
    #endif

    // Output
    int area = (xMax - xMin) * (yMax - yMin);
    cout << area << endl;

    return 0;
}
