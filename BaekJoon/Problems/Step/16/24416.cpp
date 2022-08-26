// [BOJ] 단계별로 풀어보기 > 16. 동적 계획법 1

// 24416. 알고리즘 수업 - 피보나치 수 1

/* Sample input & output data
5
5 3

30
832040 28
*/


#include <iostream>
#include <vector>

using namespace std;

#define endl '\n'

// Recursion
int fib(int n, int* p1)
{
    if (n == 1 || n == 2)
    {
        (*p1)++;
        return 1;
    }
    else return fib(n - 1, p1) + fib(n - 2, p1);
}

// Dynamic Programming …… originally, but?
int fibonacci(int n, int* p2)
{
    // do not need to get the fibonacci number
    *p2 = n - 2;

    return 1;
}

int main()
{
    int n;
    cin >> n;

    int cnt1 = 0, cnt2 = 0;
    int* p1 = &cnt1;
    int* p2 = &cnt2;
    fib(n, p1);
    fibonacci(n, p2);

    cout << cnt1 << " " << cnt2 << endl;

    return 0;
}