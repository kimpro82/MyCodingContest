/* Sample input & output data
5
20 10 35 30 7

7 35
*/

#include <iostream>
#include <cmath>    // for using min() & max(), but I really hate it

using namespace std;

int main()
{
    int t;
    cin >> t;

    int arr[t];
    int minValue = 1000000, maxValue = -1000000, temp;

    for (int i = 0; i < t; i++)
    {
        cin >> temp;
        arr[i] = temp;
        maxValue = max(maxValue, arr[i]);
        minValue = min(minValue, arr[i]);        
    }

    cout << minValue << " " << maxValue << endl;

    return 0;
}