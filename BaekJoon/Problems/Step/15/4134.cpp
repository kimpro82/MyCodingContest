// 4134. Next Prime(다음 소수)
// 2023.07.10

/* Sample input & output data
3
6
20
100

7
23
101
*/


#include <iostream>
#include <cmath>

#define endl '\n'

using namespace std;
using ll = long long;

int main()
{
    ll t;
    cin >> t;

    ll n, nSqrt;
    for (ll i = 0; i < t; i++)
    {
        cin >> n;
        n = max(n, ll(2));                                  // max(ll, int) causes an error

        while (true)
        {
            bool isPrime = true;
            nSqrt = ll(sqrt(n)) + 1;
            for (ll j = 2; j < nSqrt; j++)
            {
                if (n % j == 0)
                {
                    isPrime = false;
                    break;
                }
            }

            if (isPrime == true)
            {
                cout << n << endl;
                break;
            }
            else n++;
        }
    }

    return 0;
}
