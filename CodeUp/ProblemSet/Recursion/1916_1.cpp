// 1916 : (재귀함수) 피보나치 수열 (Large) - Trial 1
// 2023.10.16


#include <iostream>

#define endl '\n'

using namespace std;


int Fibonacci(int n)
{
    if (n <= 2)
        return 1;
    else
        return (Fibonacci(n - 1) % 10009 + Fibonacci(n - 2) % 10009) % 10009;
}

int main()
{
    int n;
    cin >> n;

    cout << Fibonacci(n) << endl;

    return 0;
}

// 시간 초과
