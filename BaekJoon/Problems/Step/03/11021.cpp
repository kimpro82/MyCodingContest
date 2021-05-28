#include <iostream>

using namespace std;

/* Sample input & output data
5
1 1
2 3
3 4
9 8
5 2

Case #1: 2
Case #2: 5
Case #3: 7
Case #4: 17
Case #5: 7
*/

int main()
{
    int t, a, b;
    cin >> t;

    for (int i = 1; i <= t; i++)
    {
        cin >> a >> b;
        cout << "Case #" << i << ": " << a + b << endl;
    }

    return 0;
}