// [BOJ] 단계별로 풀어보기 > 10. 재귀

// 10872. 팩토리얼

/* Sample input & output data
10
3628800

0
1
*/


#include <iostream>

using namespace std;

#define endl '\n'

int factorial(int n)
{
    if (n <= 1) return 1;

    return n * factorial(n - 1);
}

int main()
{
    int N;
    cin >> N;

    cout << factorial(N) << endl;

    return 0;
}