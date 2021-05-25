#include <iostream>

using namespace std;

/* Sample input & output data
10 5
1 10 4 9 2 3 8 5 7 6

1 4 2 3
*/

int main()
{
    int n, x;
    int arr[10000];                 // .exe file stops when int arr[n], although compilation succeeded
    cin >> n >> x;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        if (arr[i] < x)
        {
            cout << arr[i] << ' ';
        }
    }
    cout << '\n';

    return 0;
}