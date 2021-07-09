/* Sample input & output data
734 893
437

221 231
132

839 237
938
*/


#include <iostream>
#include <string>

using namespace std;
#define endl "\n"

int main()
{
    // Input a, b : two three digit numbers
    string a, b;
    cin >> a >> b;

    // Reverse a, b
    char aReverse[4], bReverse[4];
    for (int i = 0; i < 3; i++)
    {
        aReverse[3 - i - 1] = a[i];
        bReverse[3 - i - 1] = b[i];
    }
    cout << aReverse << " " << bReverse << endl;    // test

    // Comepare aReverse with bReverse as int and find the larger
    if (stoi(aReverse) > stoi(bReverse))            // A and B will not be equal
    {
        cout << aReverse << endl;
    } else
    {
        cout << bReverse << endl;
    }

    return 0;
}