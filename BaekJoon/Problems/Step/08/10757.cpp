// 10757. 큰 수 A+B

/* Sample input & output data
9223372036854775807 9223372036854775808

18446744073709551615
*/


#include <iostream>
#include <string>

using namespace std;
#define endl '\n'

int main()
{
    string a, b;
    char sum[10002];
    cin >> a >> b;

    int aSize = a.size(), bSize = b.size();
    int minSize = min(aSize, bSize);
    int maxSize = max(aSize, bSize);
    int buffer = 0;

    // test
    // cout << minSize << " " << maxSize << endl;   // 19 19 - OK

    // Sum each digit : 0 ~ minSize - 1
    // sum contains numbers in reverse order
    for (int i = 0; i < minSize; i++)
    {
        buffer += (a[aSize - 1 - i] - '0') + (b[bSize - 1 - i] - '0');
        if (buffer < 10)
        {
            sum[i] = (char) (buffer + '0');
            buffer = 0;
        } else
        {
            sum[i] = (char) (buffer - 10 + '0');
            buffer = 1;
        }

        // test
        cout << i << " " << a[aSize - 1 - i] << " " << b[bSize - 1 - i] << " " << buffer << " " << sum[i] << endl; 
    }

    // Residual digit : minSize ~ maxSize - 1
    for (int j = minSize; j < maxSize; j++)
    {
        if (aSize > bSize) buffer += a[aSize - 1 - j] - '0';
        else buffer += b[bSize - 1 - j] - '0';   

        if (buffer < 10)
        {
            sum[j] = (char) (buffer + '0');
            buffer = 0;
        } else
        {
            sum[j] = (char) (buffer - 10 + '0');
            buffer = 1;
        }
    }

    // Residual digit : maxSize
    if (buffer == 1)
    {
        sum[maxSize] = '1';
        maxSize++;
    }

    // test
    cout << sum << endl;

    // Output
    for (int l = 0; l < maxSize; l++)
    {
        cout << sum[maxSize - 1 - l];
    }
    cout << endl;

    return 0;
}