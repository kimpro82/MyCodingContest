// 5086. Factors And Multiples(배수와 약수)
// 2023.07.03

/* Sample input & output data
8 16
32 4
17 5
0 0

factor
multiple
neither
*/


#include <iostream>
#include <vector>

// #define test
#define endl '\n'

using namespace std;

int main()
{
    int a, b;
    while (true)
    {
        // Input
        cin >> a >> b;

        if (a == 0 && b == 0) break;
        else if (a < b && b % a == 0) cout << "factor" << endl;
        else if (a > b && a % b == 0) cout << "multiple" << endl;
        else cout << "neither" << endl;
    }

    return 0;
}
