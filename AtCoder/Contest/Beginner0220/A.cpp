// AtCoder Beginner Contest 220
// 2021-09-26(Sun) 21:00 - 22:40, 100 minutes

// A - Find Multiple

/* Sample Input & Output
123 456 100
200

630 940 314
-1
*/


#include <iostream>

#define endl '\n'

using namespace std;

int main()
{
    int A, B, C;
    cin >> A >> B >> C;

    int multiple = C;
    while (multiple <= B)
    {
        if (multiple >= A && multiple <= B)
        {
            cout << multiple << endl;
            return 0;
        }
        else multiple += C;
    }

    // If failed
    cout << -1 << endl;

    return 0;
}