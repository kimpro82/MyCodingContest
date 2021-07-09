/* Sample input & output data
1
1
1

5
54321
15

25
7000000000000000000000000
7

11
10987654321
46
*/


#include <iostream>
#include <string>

using namespace std;
#define endl "\n"

int main()
{
    // Input
    int n;
    string x;
    cin >> n >> x;

    // Operate and output
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += (int) x[i] - '0';
        // cout << x[i] << " " << sum << endl;  // test
    }
    cout << sum << endl;

    return 0;
}