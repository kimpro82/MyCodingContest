// 2745. 진법 변환
// 2023.06.27

/* Sample input & output data
ZZZZZ 36

60466175
*/


#include <iostream>
#include <cmath>

// #define test
#define endl '\n'

using namespace std;

int main()
{
    // Input : N <= 10^9, 2 <= B <= 36
    string N;
    int B;
    cin >> N >> B;

    // Operate
    int len = N.size();
    int sum = 0;
    char c;
    for (int i = 0; i < len; i++)
    {
        c = N[len-i-1];
        if (c <= '9') sum += (c - '0')  * int(pow(B, i));
        else sum += (c - 'A' + 10) * int(pow(B, i));

        #ifdef test
            printf("%d %c %d\n", i, c, sum);
        #endif
    }

    // Output
    cout << sum << endl;

    return 0;
}
