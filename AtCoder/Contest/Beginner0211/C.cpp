// AtCoder Beginner Contest 211
// 2021-07-24(Satn) 21:00 - 22:40, 100 minutes

// C - chokudai

/* Sample Input & Output
chchokudai
3

atcoderrr
0

chokudaichokudaichokudai
45
*/


#include <iostream>
#include <string>

using namespace std;
#define endl '\n'

int main()
{
    // Indput data
    string chokudai = "chokudai", s;
    // cout << chokudai[1] << endl;         // test : ok
    cin >> s;

    int count = 0;
    for (int i = 0; i < s.size() - 8; i++)
    {
        string sub;
        for (int j = i; j < s.size(); j++)
        {
            cout << s[j];
        }
        cout << endl;
    }

    return 0;
}