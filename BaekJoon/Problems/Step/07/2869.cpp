// 2869. PUŽ

/* Sample input & output data
2 1 5
4

5 1 6
2

100 99 1000000000
999999901
*/


#include <iostream>

using namespace std;
#define endl '\n'

int main()
{
    int a, b, v;
    // a : climb upwards in a day
    // b : back down each night, always a > b
    // v : wooden pole's height
    cin >> a >> b >> v;

    // Find the minimum day
    int day = (v - b) / (a - b) - 1;
    int location = (a - b) * day;

    // Climb
    while (true)
    {
        day++;
        location += a;
        
        // test
        cout << day << " " << location << " " << location - v << endl;

        if (location >= v)
        {
            break;
        }
        location -= b;
    }

    // Output
    cout << day << endl;

    return 0;
}