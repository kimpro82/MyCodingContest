// 1928 : (재귀함수) 우박수 (3n+1) (basic)
// 2023.10.16


#include <iostream>

#define endl '\n'

using namespace std;


void Recursion(int n)
{
    cout << n << endl;

    if (n == 1) return;
    else if (n % 2 == 1) Recursion(3 * n + 1);
    else Recursion(n / 2);
}

int main()
{
    int n;
    cin >> n;

    Recursion(n);

    return 0;
}
