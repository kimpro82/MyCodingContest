// AtCoder Beginner Contest 212
// 2021-07-31(Sat) 21:00 - 22:40, 100 minutes

// B - Weak Password

/* Sample Input & Output
7777
Weak

0112
Strong

9012
Weak
*/


#include <iostream>
#include <string>

#define endl '\n'

using namespace std;

int main()
{
    // Input data
    string X;
    cin >> X;

    // Determine
    int weak1 = 0, weak2 = 0;
    for (int i = 1; i < 4; i++)
    {
        if (X[i] != X[0]) weak1++;
        if (X[i-1] < '9')
        {
            if (X[i] == X[i-1] + 1) weak2++;
        } else
        {
            if (X[i] == '0') weak2++;
        }
    }

    // Output
    if (weak1 == 0 || weak2 == 3) cout << "Weak" << endl;
    else cout << "Strong" << endl;

    return 0;
}