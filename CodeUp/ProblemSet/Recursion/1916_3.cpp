// 1916 : (재귀함수) 피보나치 수열 (Large) - Trial 3
// 2023.10.16


#include <iostream>

#define endl '\n'

using namespace std;


int memo[201];

int Fibonacci(int n)
{
    if (memo[n] > -1)
        return memo[n];
    else if (n <= 2)
        return 1;
    else
        return (Fibonacci(n - 1) + Fibonacci(n - 2)) % 10009;
}

int main()
{
    int n;
    cin >> n;

    fill(memo, memo + 201, -1);         // not 0 but -1 (∵ 100009 % 100009 = 0)
    cout << Fibonacci(n) << endl;

    return 0;
}

// 시간 초과
