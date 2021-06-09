/* Sample input & output data
3
29
38
12
57
74
40
85
61

85
8
*/

#include <iostream>

using namespace std;

int main()
{
    // make it faster
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    const int length = 9;   // the length of arr[] is fixed as 9
    int arr[length];
    int maxValue = 0, temp, loc = 0;

    for (int i = 0; i < length; i++)
    {
        cin >> temp;
        arr[i] = temp;

        if (arr[i] > maxValue)  // all elements of arr[] are different from each other
        {
            maxValue = arr[i];
            loc = i + 1;
        }
    }

    cout << maxValue << "\n" << loc << "\n";

    return 0;
}