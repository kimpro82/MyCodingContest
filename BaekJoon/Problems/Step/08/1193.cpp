// 1193. 분수찾기

/* Sample input & output data
14
2/4
*/


#include <iostream>

using namespace std;
#define endl '\n'

int main()
{
    int x;
    cin >> x;

    int zigzag = 0, sum = 0;
    while (x > sum)
    {
        zigzag++;
        sum += zigzag;

        // test
        cout << x << " " << zigzag << " " << sum << endl;
    }

    int numerator, denominator;
    if (zigzag % 2 == 0)
    {
        denominator = sum - x + 1;
        numerator = zigzag - denominator + 1;         
    } else
    {
        numerator = sum - x + 1;
        denominator = zigzag - numerator + 1;
    }

    cout << numerator << '/' << denominator << endl;

    return 0;
}