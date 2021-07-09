/* Sample input & output data
baekjoon
1 0 -1 -1 2 -1 -1 -1 -1 4 3 -1 -1 7 5 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1
*/


#include <iostream>
#include <string>
#include <vector>

using namespace std;
#define endl "\n"

int main()
{
    // Input
    string s;
    cin >> s;

    // Declare an array for counting a~z
    vector<int> alphabet (26, -1);

    // Count
    for (int i = 0; i < s.length(); i++)
    {
        if (alphabet[s[i] - 'a'] == -1)
        {
            alphabet[s[i] - 'a'] = i;
        }
    }

    // Output
    for (int j = 0; j < 25; j++)    // a ~ y
    {
        cout << alphabet[j] << " ";
    }
    cout << alphabet[25] << endl;   // z

    return 0;
}