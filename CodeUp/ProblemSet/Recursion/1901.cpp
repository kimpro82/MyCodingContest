// 1901 : (재귀 함수) 1부터 n까지 출력하기
// 2023.10.16


#include <iostream>

#define endl '\n'

using namespace std;


void recursion(int n, int cnt)
{
    cout << cnt << endl;

    if (n == cnt)
        return;
    else
        recursion(n, cnt + 1);
}

int main()
{
    int n, cnt = 1;
    cin >> n;

    recursion(n, cnt);

    return 0;
}
