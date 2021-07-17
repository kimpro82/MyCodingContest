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

int factorial(int n)
{
    if (n <= 1) return 1;
 
    return n * factorial(n - 1);
}

int main()
{
    int p;
    cin >> p;

    // Find the largest coin
    int pTemp = p, largest = 1;
    for (int i = 1; i <= 10; i++)
    {
        if (pTemp > 1)
        {
            pTemp /= i;
            largest = i;

            // test
            cout << i << " " << pTemp << '\n';
        } 
        else break;
    }

    // Count the number of coins needed
    int count = 0, coin;
    for (int j = largest; j > 0; j--)
    {
        if (p >= factorial(j))
        {
            count += p / factorial(j);
        
            // test
            cout << j << " " << p << " " << count << '\n';

            p %= factorial(j);
        }
    }

    // Output
    cout << count << '\n';

    return 0;
}