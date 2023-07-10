// 17103. 골드바흐 파티션
// 2023.07.10

/* Sample input & output data
5
6
8
10
12
100

1
1
2
1
6
*/


#include <iostream>
#include <cmath>

#define test
#define endl '\n'

using namespace std;


int main()
{
    int t;
    cin >> t;

    int n;
    for (int i = 0; i < t; i++)
    {
        cin >> n;

        int cnt = 0;
        for (int j = 2; j <= n / 2; j++)
        {
            // Get a as a prime number
            bool aIsPrime = true;
            for (int k = 2; k <= int(sqrt(j)); k++)
            {
                if (j % k == 0)
                {
                    aIsPrime = false;
                    break;
                }
            }

            // Run only when a is a prime number
            if (aIsPrime == true)
            {
                int a = j;
                int b = n - j;

                // Get b as a prime number
                bool bIsPrime = true;
                for (int k = 2; k <= int(sqrt(b)); k++)
                {
                    if (b % k == 0)
                    {
                        bIsPrime = false;
                        break;
                    }
                }

                // Do cnt++ when a and b both are prime numbers
                if (bIsPrime == true)
                {
                    cnt++;

                    #ifdef test
                        printf("a:%d b:%d cnt:%d\n", a, b, cnt);
                    #endif
                }
            }
        }

        cout << cnt << endl;
    }

    return 0;
}

// 시간 초과
