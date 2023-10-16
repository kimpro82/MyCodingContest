// 1916 : (재귀함수) 피보나치 수열 (Large) - Trial 4
// 2023.10.16


#include <iostream>
#include <vector>

#define endl '\n'
#define test

using namespace std;


vector<int> bottomUp;

int Fibonacci(int n, int m)
{
    if (m <= 2)
        bottomUp[m] = 1;
    else
        bottomUp[m] = (bottomUp[m-1] + bottomUp[m-2]) % 10009;

    #ifdef test
        cout << m << ' ' << bottomUp[m] << endl;
    #endif

    if (m == n)
        return bottomUp[m];
    else
        Fibonacci(n, m + 1);
}

int main()
{
    int n;
    cin >> n;

    bottomUp.assign(n + 1, -1);         // not 0 but -1 (∵ 10009 % 10009 = 0)
    cout << Fibonacci(n, 1) << endl;

    return 0;
}

// Runtime Error:Segmentation fault
