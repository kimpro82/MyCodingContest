// [BOJ] 단계별로 풀어보기 > 9. 기본 수학 2

// 1978. 소수 찾기2581. 소수

/* Sample input & output data
60
100
620
61

64
65
-1
*/


#include <iostream>
#include <vector>

using namespace std;
#define endl '\n'

int main()
{
    // Input data
    int m, n;                           // 1 <= m <= n <= 10,000
    cin >> m >> n;

    // Determine if each number between m and n is a prime number
    int sum = 0, min = 10000, prime;
    if (m == 1) m++;                    // don't need to consider 1
    for (int i = m; i <= n; i++)
    {
        prime = 1;

        for (int j = 2; j <= i/2; j++)
        {
            if (i % j  == 0)
            {
                prime = 0;
                break;
            }
        }

        if (prime == 1)
        {
            sum += i;
            if (i < min) min = i;       // enough to operate just once first but ……

            // test
            cout << i << " " << sum << " " << min << endl;
        }
    }

    // Output
    if (sum > 0) cout << sum << '\n' << min << endl;
    else cout << -1 << endl;

    return 0;
}