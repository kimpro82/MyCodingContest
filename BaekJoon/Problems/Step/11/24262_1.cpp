// 24262. 알고리즘 수업 - 알고리즘의 수행 시간 1
// 2023.07.04

/* Sample input & output data
1

1
0
*/


#include <iostream>

#define endl '\n'

using namespace std;

int MenOfPassion(int *n)
{
    if (*n == 0) return 0;

    int temp = *n / 2;
    if (temp > 3) temp = 4;

    // Output
    cout << temp << endl;

    return MenOfPassion(&temp);
}

int main()
{
    // Input
    int n;
    cin >> n;

    // Operate
    MenOfPassion(&n);

    return 0;
}

// 틀렸습니다
