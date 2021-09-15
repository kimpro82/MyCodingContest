// [BOJ] 단계별로 풀어보기 > 10. 재귀

// 10870. 피보나치 수 5

/* Sample input & output data
10
55
*/


#include <iostream>

using namespace std;

#define endl '\n'

int fibonacci(int n)
{
    if (n == 0) return 0;
    if (n == 1) return 1;

    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main()
{
    int n;
    cin >> n;

    cout << fibonacci(n) << endl;

    return 0;
}