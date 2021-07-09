/* Sample input & output data
2
3 ABC
5 /HTP

AAABBBCCC
/////HHHHHTTTTTPPPPP
*/


#include <iostream>
#include <string>

using namespace std;
#define endl "\n"

int main()
{
    int p;
    cin >> p;

    int n;
    string s;
    for (int i = 0; i < p; i++)
    {
        cin >> n >> s;

        for (int j = 0; j < s.length(); j++)
        {
            for (int k = 0; k < n; k++)
            {
                cout << s[j];
            }
        }
        cout << endl;
    }

    return 0;
}