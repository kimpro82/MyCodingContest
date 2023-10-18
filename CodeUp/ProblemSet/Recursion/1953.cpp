// 1953 : (재귀함수) 삼각형 출력하기 1
// 2023.10.16


#include <iostream>

#define endl '\n'

using namespace std;


void star(int m)
{
    cout << '*';

    if (m == 1) return;
    else star(m - 1);
}

void Recursion(int n, int m)
{
    star(m);
    cout << endl;

    if (n == m) return;
    else Recursion(n, m + 1);
}

int main()
{
    int n;
    cin >> n;

    Recursion(n, 1);

    return 0;
}
