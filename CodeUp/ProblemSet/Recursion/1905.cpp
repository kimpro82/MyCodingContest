// 1905 : (재귀함수) 1부터 n까지 합 구하기
// 2023.10.16


#include <iostream>

#define endl '\n'

using namespace std;


void recursion(int n, int m, int sum)
{
    sum += m;

    if (n == m)
    {
        cout << sum << endl;
        return;
    }
    else
        recursion(n, m + 1, sum);
}

int main()
{
    int n;
    cin >> n;

    int m = 1, sum = 0;
    recursion(n, m, sum);

    return 0;
}
