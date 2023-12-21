// 1037. 약수
// 2023.07.13

/* Sample input & output data
6
3 4 2 12 6 8

24
*/


#include <iostream>

#define endl '\n'

using namespace std;


int main()
{
    int n;
    cin >> n;

    int a, max = 0, min = 1'000'000;
    while (n--)
    {
        cin >> a;
        if (a > max) max = a;
        if (a < min) min = a;
    }

    // Output
    int ans = max * min;
    cout << ans << endl;

    return 0;
}
