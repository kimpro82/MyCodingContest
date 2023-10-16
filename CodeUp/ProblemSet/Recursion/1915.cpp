// 1915 : (재귀함수) 피보나치 수열
// 2023.10.16


#include <iostream>

#define endl '\n'

using namespace std;


int Fibonacci(int n)
{
    if (n <= 2)
        return 1;
    else
        return Fibonacci(n - 1) + Fibonacci(n - 2);
}

int main()
{
    int n;
    cin >> n;

    cout << Fibonacci(n) << endl;

    return 0;
}
