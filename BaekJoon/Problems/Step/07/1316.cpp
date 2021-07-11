/* Sample input & output data
3
happy
new
year
3

4
aba
abab
abcabc
a
1
*/


#include <iostream>
#include <string>
#include <array>

using namespace std;
#define endl '\n'

int main()
{
    // Input
    int n;
    cin >> n;

    string s;
    int sLength, count = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        sLength = s.size();

        // Find if there are seperated same letters
        array<int, 26> alphabet = {0, };
        bool isSeperated = false;
        for (int j = 0; j < sLength; j++)
        {
            if (alphabet[s[j] - 'a'] == 0)
            {
                alphabet[s[j] - 'a']++;
            } else
            {
                if (s[j] != s[j-1])
                {
                    isSeperated = true;
                    break;
                }
            }
        }

        // Count
        if (isSeperated == false)
        {
            count++;
        }

        // test
        cout << s << " " << isSeperated << " " << count << endl;
    }

    // Output
    cout << count << endl;

    return 0;
}