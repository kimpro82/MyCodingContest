// [BOJ] 단계별로 풀어보기 > 9. 기본 수학 2

// 1929. 소수 구하기

/* Sample input & output data
3 16

3
5
7
11
13
*/


#include <iostream>

using namespace std;
#define endl '\n'

int main()
{
    // seems to be needed ……
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);

    // Input data
    int m, n;       // 1 <= m <= n <= 1,000,000, guarantee at least one prime number
    cin >> m >> n;

    // Determine if each number between m and n is a prime number
    int prime;
    if (m == 1) m++;                    // don't need to consider 1
    for (int i = m; i <= n; i++)
    {
        prime = 1;

        for (int j = 2; j <= i/j; j++)  // magic to avoid TLE! 
        {
            if (i % j  == 0)
            {
                prime = 0;
                break;
            }
        }

        if (prime == 1) cout << i << endl;
    }

    return 0;
}