// [BOJ] 단계별로 풀어보기 > 9. 기본 수학 2

// 11653. 소인수분해

/* Sample input & output data
72
2
2
2
3
3

9991
97
103
*/


#include <iostream>

using namespace std;
#define endl '\n'

int main()
{
    // Input data
    int n;                           // 1 <= n <= 10,000,000
    cin >> n;

    // Prime factorization
    int divisor = 2;
    while (n > 1)
    {
        if (n % divisor == 0)
        {
            cout << divisor << endl;
            n /= divisor;
        }
        else divisor++;
    }

    return 0;
}