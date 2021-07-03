// AtCoder Beginner Contest 206
// 2021-06-19(Sat) 21:00 - 22:40, 100 minutes

// A - Maxi-Buying

/* Sample input & output
180
Yay!

200
:(

191
so-so   
*/

#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int price = int (n * 1.08);     // price : n + 8% tax
    cout << price << endl;          // test

    if (price < 206)
    {
        cout << "Yay!" << endl;
    } else if (price == 206)
    {
        cout << "so-so" << endl;
    } else
    {
        cout << ":(" << endl;
    }
 
    return 0;
}