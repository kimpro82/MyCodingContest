// 1902 : (재귀 함수) 1부터 n까지 역순으로 출력하기
// 2023.10.16


#include <iostream>

#define endl '\n'

using namespace std;


void recursion(int n, int cnt)
{
    cout << cnt << endl;

    if (cnt == 1)
        return;
    else
        recursion(n, cnt - 1);
}

int main()
{
    int n;
    cin >> n;

    int cnt = n;
    recursion(n, cnt);

    return 0;
}
