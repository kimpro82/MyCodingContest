// 1912 : (재귀함수) 팩토리얼 계산
// 2023.10.16


#include <iostream>

#define endl '\n'

using namespace std;


void factorial(int n, int prod)
{
    prod *= n;

    if (n == 1)
    {
        cout << prod << endl;
        return;
    }
    else
        factorial(n - 1, prod);
}

int main()
{
    int n;
    cin >> n;

    int prod = 1;
    factorial(n, prod);

    return 0;
}
