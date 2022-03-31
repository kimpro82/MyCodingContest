// [BOJ] 단계별로 풀어보기 > 9. 기본 수학 2

// 1085. 직사각형에서 탈출

/* Sample input & output data
6 2 10 3

1
*/


#include <iostream>

using namespace std;
#define endl '\n'

int main()
{
    int x, y, w, h;
    cin >> x >> y >> w >> h;

    int minValue;
    minValue = min(min(x, w-x), min(y, h-y));

    cout << minValue << endl;

    return 0;
}