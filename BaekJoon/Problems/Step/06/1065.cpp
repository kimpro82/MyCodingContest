/* Sample input & output data
110
99

1
1

210
105

1000
144
*/

#include <iostream>

using namespace std;

int main()
{
    int n;      // n <= 1000
    cin >> n;

    int count = 0;
    if (n < 100)
    {
        count = n;
    } else
    {
        int a, b, c;
        count = 99;
        if (n == 1000)      // can determine 1000 is not
        {
            n = 999;
        }
        for (int i = 100; i <= n; i++)
        {
            a = i / 100;
            b = (i % 100) / 10;
            c = i % 10;
            if ((b - a) == (c - b))
            {
                count++;
            }
            cout << a << " " << b << " " << c << " " << count << endl;  // test
        }
    }
    // else             // n == 1000
    // {
    //     count = 144; // given as a sample output …… crazy
    // }

    cout << count << endl;

    return 0;
}