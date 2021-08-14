// AtCoder Beginner Contest 214
// 2021-08-14(Sat) 21:00 - 22:40, 100 minutes

// B - How many?

/* Sample Input & Output
1 0
4

2 5
10

10 10
213

30 100
2471
*/


#include <iostream>

#define endl '\n'

using namespace std;

int main()
{
    int S, T;
    cin >> S >> T;

    int s = 0, t = 1, count = 0;
    for (int i = 0; i <= S; i++)
    {
        for (int j = 0; j <= S - i; j++)
        {
            if (i + j > S) break;

            for (int k = 0; k <= S - i - j; k++)
            {
                if (i + j + k > S || i * j * k > T) break;
                else
                {
                    count++;

                    // test
                    cout << i << ' ' << j << ' ' << k << ' ' << count << endl;
                }
            }
        }
    }

    cout << count << endl;

    return 0;
}