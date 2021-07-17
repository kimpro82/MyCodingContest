// AtCoder Beginner Contest 210
// 2021-07-17(Sat) 21:00 - 22:40, 100 minutes

// B - Bouzu Mekuri

/* Sample Input & Output
5
00101
Takahashi

3
010
Aoki
*/


#include <iostream>

#define endl '\n'

using namespace std;

int main()
{
    int n;
    string s;

    cin >> n;
    cin >> s;

    // Find the first 1's index
    int index = s.find('1');

    // test
    cout << index << endl;

    // Output
    if (index % 2 == 0) cout << "Takahashi" << endl;
    else cout << "Aoki" << endl;

    return 0;
}