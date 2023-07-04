// 10101. Triangle Times(삼각형 외우기)
// 2023.07.02

/* Sample input & output data
60
70
50

Scalene
*/


#include <iostream>

#define endl '\n'

using namespace std;

int main()
{
    // Input
    int a, b, c;
    cin >> a >> b >> c;

    // Operate
    string ans;
    if (a + b + c == 180)
    {
        if (a == 60 && b == 60) ans = "Equilateral";
        else if (a == b || b == c || c == a) ans = "Isosceles";
        else ans = "Scalene";
    }
    else ans = "Error";

    // Output
    cout << ans << endl;
    return 0;
}
