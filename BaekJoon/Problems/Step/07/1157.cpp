/* Sample input & output data
Mississipi
?

zZa
Z

z
Z

baaa
A
*/


#include <iostream>
#include <string>
#include <array>

using namespace std;
#define endl "\n"

int main()
{
    // Input
    string s;
    cin >> s;

    // Change all letter to upper case
    const int sLength = s.length();
    for (int i = 0; i < sLength; i++)
    {
        s[i] = toupper(s[i]);
    }
    // cout << s << endl;                   // test

    // Count each alphabet
    array<int, 26> alphabet = {0, };
    for (int j = 0; j < sLength; j++)
    {
        alphabet[s[j]-'A']++;
    }

    // Find the max value
    int maxValue = 0, maxIndex;
    for (int k = 0; k < 26; k++)
    {
        if (alphabet[k] > maxValue)
        {
            maxValue = alphabet[k];
            maxIndex = k;
        }
    }

    // Determine if the max value is unique
    int ifUnique = 0; 
    for (int l = 0; l < 26; l++)
    {
        if (alphabet[l] == maxValue)
        {
            ifUnique++;
        }
    }

    // test
    cout << maxValue << " " << maxIndex << " " << ifUnique << endl;

    // Output
    if (ifUnique > 1)
    {
        cout << '?' << endl;
    } else
    {
        cout << char ('A' + maxIndex) << endl;
    }

    return 0;
}