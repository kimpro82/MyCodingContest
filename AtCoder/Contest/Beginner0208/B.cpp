// AtCoder Beginner Contest 208
// 2021-07-04(Sun) 21:00 - 22:40, 100 minutes

// B - Factorial Yen Coin

/* Sample Input & Output
9
3

119
10

10000000
24
*/


#include <iostream>

using namespace std;

int factorial(int num)
{
    if (num <= 1) return 1;
 
    return num * factorial(num - 1);
}

int main()
{
    int p;
    cin >> p;

    // fine the largest coin
    int pTemp = p, largest = 1;
    for (int i = 1; i <= 10; i++)
    {
        if (pTemp > 1)
        {
            pTemp /= i;
            largest = i;
        } else
        {
            break;
        }
        // test
        // cout << p << " " << i << " " << pTemp << " " << largest << '\n';
    }

    // count the number of coins needed
    int count = 0, coin;
    if (p == 1)
    {
        count++;
    } else
    {
        for (int j = largest; j > 0; j--)
        {
            if (p >= factorial(j))
            {
                count += p / factorial(j);
                p %= factorial(j);
            }
            // test
            // cout << j << " " << p << " " << count << '\n';
        }
    }

    // output
    cout << count << '\n';

    return 0;
}