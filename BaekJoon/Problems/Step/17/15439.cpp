// 15439. Vera and Outfits(베라의 패션)
// 2023.07.12

/* Sample input & output data
5

20
*/


#include <iostream>

#define endl '\n'

using namespace std;


int main()
{
    // Input
    int n;
    cin >> n;

    // Output
    int ans = n * n - n;                                    // do not need to use combination
    cout << ans << endl;

    return 0;
}
