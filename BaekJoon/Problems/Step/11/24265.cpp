// 24265. 알고리즘 수업 - 알고리즘의 수행 시간 4
// 2023.07.04

/* Sample input & output data
7

21
2
*/


#include <iostream>

#define endl '\n'

using namespace std;

int main()
{
    // Input
    long long n;
    cin >> n;

    // Operate
    long long cnt = 0;
    for (int i = 1; i < n; i++) for (int j = i + 1; j <= n; j++) cnt++;

    // Output
    cout << cnt << endl;
    cout << 2 << endl;

    return 0;
}
