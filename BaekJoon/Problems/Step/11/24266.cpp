// 24266. 알고리즘 수업 - 알고리즘의 수행 시간 5
// 2023.07.04

/* Sample input & output data
7

343
3
*/


#include <iostream>

#define endl '\n'

using namespace std;

int main()
{
    // Input
    long long n;
    cin >> n;

    // Output
    cout << (long long) n * n * n << endl;
    cout << 3 << endl;

    return 0;
}
