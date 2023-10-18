// 1904 : (재귀함수) 두 수 사이의 홀수 출력하기
// 2023.10.16


#include <iostream>

#define endl '\n'

using namespace std;


void recursion(int a, int b)
{
    if (a % 2 == 1)
        cout << a << ' ';

    if (a >= b)
    {
        cout << endl;
        return;
    }
    else
        recursion(a + 1, b);
}

int main()
{
    int a, b;
    cin >> a >> b;

    recursion(a, b);

    return 0;
}
