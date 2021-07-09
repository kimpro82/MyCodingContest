/* Sample input & output data
WA
13

UNUCIC
36
*/


#include <iostream>
#include <string>

using namespace std;
#define endl "\n"

int main()
{
    // Input
    string s;
    cin >> s;

    // Operate
    int sLength = s.size();
    int dial, time, sum = 0;
    for (int i = 0; i < sLength; i++)
    {
        if (s[i] <= 'R')
        {
            dial = (s[i] - 'A') / 3 + 2;
        } else if (s[i] >= 'S' && s[i] <= 'X')
        {
            dial = (s[i] - 'A' - 1) / 3 + 2;
        } else
        {
            dial = (s[i] - 'A' - 2) / 3 + 2;
        }

        time = dial + 1;
        sum += time;
        cout << s[i] << " " << dial << " " << time << " " << sum << endl;   // test
    }

    // Output
    cout << sum << endl;

    return 0;
}