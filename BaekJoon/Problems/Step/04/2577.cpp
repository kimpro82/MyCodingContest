/* Sample input & output data
150
266
427

3
1
0
2
0
0
0
2
0
0
*/

#include <iostream>

using namespace std;

int main()
{
    int a, b, c;                        // 100 <= a, b, c < 1000
    cin >> a >> b >> c;

    string prod = to_string(a * b * c); 
    int length = sizeof(prod);
    int arr[length] = {};               // initialize arr[] as {0, 0, ……, 0}

    for (int i = 0; i < length; i++)
    {
        arr[prod[i]-'0']++;             // I did this amazing code! 
    }

    for (int j = 0; j < 10; j++)
    {
        cout << arr[j] << endl;
    }

    return 0;
}