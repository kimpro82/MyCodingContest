// 1541. 잃어버린 괄호

/* Sample input & output data
55-50+40
-35

10+20+30+40
100

00009-00009
0
*/


#include <iostream>
#define endl '\n'

using namespace std;

int main()
{
    // Input data
    string s;
    cin >> s;
    int len = s.size();

    // Read formula
    int endPoint = 0, sum = 0, sign = 1;
    for (int i = 0; i < len; i++)
    {
        if (s[i] == '+' || s[i] == '-' || i == len - 1)
        {
            sum += stoi(s.substr(endPoint)) * sign;         // stoi() cuts substring before sign (ex. 55-50+40 → 55)

            // test
            // cout << i << ' ' << s[i] << ' ' << sign << ' ' << endPoint << ' ' << s.substr(endPoint) << ' ' << sum << endl;

            endPoint = i + 1;
            if (s[i] == '-') sign = -1;
        }
    }

    // Output
    cout << sum << endl;

    return 0;
}