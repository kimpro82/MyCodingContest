// [BOJ] 단계별로 풀어보기 > 9. 기본 수학 2

// 9020. Goldbach’s Conjecture (골드바흐의 추측)

/* Sample input & output data
3
8
10
16

3 5
5 5
5 11
*/


#include <iostream>

using namespace std;
#define endl '\n'

int main()
{
    // maybe better than nothing?
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;

    // T test cases
    for (int t = 0; t < T; t++)
    {
        int n, m, prime;
        cin >> n;

        for (int i = n/2; i > 1; i--)
        {
            prime = 1;

            // Find the first prime number
            for (int j = 2; j <= i/j; j++)      // magic to avoid TLE! 
            {
                if (i % j  == 0)
                {
                    prime = 0;
                    break;
                }
            }

            // Find if (n - i) is also a prime number
            if (prime == 1)
            {
                m = n - i;
                for (int k = 2; k <= m/k; k++)
                {
                    if (m % k  == 0)
                    {
                        prime = 0;
                        break;
                    }
                }
            }

            // When both of the numbers are prime ones
            if (prime == 1)
            {
                cout << i << ' ' << m << endl;
                break;                          // need only once
            }
        } // The end of i loop
    } // The end of t loop

    return 0;
}