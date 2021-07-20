// [BOJ] 단계별로 풀어보기 > 9. 기본 수학 2

// 4948. Chebyshev's Theorem (베트르랑 공준)

/* Sample input & output data
1
10
13
100
1000
10000
100000
0

1
4
3
21
135
1033
8392
*/


#include <iostream>

using namespace std;
#define endl '\n'

int main()
{
    // maybe better than nothing?
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);

    int n;
    while (true)
    {
        // Input data
        cin >> n;
        if (n == 0) break;

        // Determine if each number between n and 2n is a prime one
        int m = 2 * n, prime, count = 0;
        for (int i = n + 1; i <= m; i++)    // "greater than n and less than or equal to 2n"
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
            if (prime == 1) count++;
        }

        // Output
        cout << count << endl;
    }

    return 0;
}