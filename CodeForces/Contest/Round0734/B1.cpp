// Codeforces Round #734 (Div. 3)
// 2021.07.23 23:35, 2 hrs
 
// B1. Wonderful Coloring - 1
 
/* Sample Input & Output
5
kzaaa
codeforces
archive
y
xxxxxx
 
2
5
3
0
1
*/
 
 
#include <iostream>
#include <string>
#include <vector>

using namespace std;
#define endl '\n'

int main()
{
    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        // Input data
        string s;
        cin >> s;

        // Make vector v from the number of each alphabet of string s
        vector<int> v (26, 0);
        for (int j = 0; j < s.size(); j++) v[s[j]-'a']++;

        // Count the pairs of the red and green colored
        int count = 0;
        while (true)
        {
            // test
            for (int m = 0; m < 26; m++) cout << v[m] << ' ';
            cout << "/ " << count << endl;

            int candidate1 = -1, candidate2 = -1;

            // find candidate1
            for (int k = 0; k < 26; k++)
            {
                if (v[k] > 0)
                {
                    candidate1 = k;
                    break;
                }
            }
            if (candidate1 == -1) break;

            // find candidate2
            for (int l = candidate1 + 1; l < 26; l++)
            {
                if (v[l] > 0)
                {
                    candidate2 = l;
                    break;
                }
            }
            if (v[candidate1] < 2 && candidate2 == -1) break;

            // count
            if (v[candidate1] > 1)          // if a letter exists 2 or more
            {
                v[candidate1] = 0;
                count++;
            } else if (v[candidate2] > 1)
            {
                v[candidate2] = 0;
                count++;
            } else
            {
                v[candidate1]--;
                v[candidate2]--;
                count++;
            }
        } // The end of while loop

        // Output
        cout << count << endl;
    } // The end of t loop

    return 0;
}