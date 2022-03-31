/* Sample input & output data
ljes=njak
6

ddz=z=
3

nljj
3

c=c=
2

dz=ak
3
*/


#include <iostream>
#include <string>
#include <array>
#include <vector>

using namespace std;
#define endl '\n'

int main()
{
    // Input
    string s;
    cin >> s;

    // Make an array of specific Croatian alphabets
    array<string, 8> specific = {"c=", "c-", "d-", "lj", "nj", "s=", "z=", "dz="};

    // Make substrings from s
    int sLength = s.size();
    // 1) two letters
    vector<string> sSub1;
    for (int i = 0; i < sLength - 1; i++)
    {
        sSub1.push_back(s.substr(i, 2));
    }
    // 2) three letters
    vector<string> sSub2;
    for (int j = 0; j < sLength - 2; j++)
    {
        sSub2.push_back(s.substr(j, 3));
    }

    // Count specific Croatian alphabets
    int count = 0;
    // 1) two letters : specific[0, 6]
    for (int k = 0; k < sLength - 1; k++)
    {
        for (int l = 0; l < 7; l++)
        {
            if (s.substr(k, 2) == specific[l])
            {
                count++;
            }
        }
    }
    // 2) three letters : specific[7]
    for (int m = 0; m < sLength - 2; m++)
    {
        if (s.substr(m, 3) == specific[7])
        {
            count++;
        }
    }

    // Output
    cout << sLength - count << endl;

    return 0;
}