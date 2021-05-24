#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    int a;
    // char b[3];                       // trial 1-1 : a = 256 when declare char b[3]
    // char b[4];                       // trial 1-2 
    string b;                           // trial 1-3 : change char[] to string
    cin >> a;                           // 472
    cin >> b;                           // 385
    // cout << a << " " << b << endl;   // test
    int len = b.length();

    int sum = 0;
    for (int i = 0; i < len; i++)
    {
        // Test : get each cipher's integer number, not ascii code
        // cout << "b[" << len-i-1 << "] : " << b.at(len-i-1) << endl;              // b[2], b[1], b[0] / OK
        // cout << "convert to int 1 : " << (int) b.at(len-i-1) << endl;            // failure because output its ascii code
        // cout << "convert to int 2 : " << (int) (b.at(len-i-1) - '0') << endl;    // success
        short digit = (int) (b[3-i-1] - '0');

        // The ways to get 100 by pow(10, 3) (Remove // from only one line)
        // int cipher = pow(10, i);                                                 // trial 2-1 : vanilla double pow() - 99- 180304
        // int cipher = (int) pow(10, i);                                           // trial 2-2 : (int) double pow() - 99 - 180304
        // int cipher = (int) powl(10, i);                                          // trial 2-3 : (int) long double powl() - 99 - 180304
        // int cipher = pow(10, i);                                                 // trial 2-4 : the same with 1 but run by C++17(Clang) - Correct
        // int cipher = pow(10.0, i);                                               // trial 2-5 : use 10.0 - 99 - 180304
        int cipher = round(pow(10, i));                                          // trial 2-6 : round(pow()) - Correct
        // cout << a << " " << (int) digit << " " << cipher << endl;                // test

        // Operation for each cipher
        int prod = a * (int) digit;                                                 // get difference between ascii codes of (b[3-i-1]) and '0'
        sum += prod * cipher;

        // Output
        // cout << prod << " " << sum - prod << " " << sum << endl;    // test
        cout << prod << endl;
    }

    // Output
    // cout << sum + 1 << endl; // can't find why lack of 1 - crazy!
    cout << sum << endl;        // go honest

    return 0;
}