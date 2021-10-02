// AtCoder Beginner Contest 221
// 2021-10-02(Sat) 21:00 - 22:40, 100 minutes

// A - Seismic magnitude scales

/* Sample Input & Output
6 4
1024

5 5
1
*/


#include <iostream>
#include <cmath>

#define endl '\n'

using namespace std;

int main()
{
    int A, B;
    cin >> A >> B;
    cout << (long long) pow(32, A - B) << endl;

    return 0;
}