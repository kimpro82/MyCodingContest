/* Sample input & output data
5
OOXXOXXOOO
OOXXOOXXOO
OXOXOXOXOXOXOX
OOOOOOOOOO
OOOOXOOOOXOOOOX

10
9
7
55
30
*/

#include <iostream>

using namespace std;

int main()
{
    int t;
    cin >> t;

    string input[t];

    for (int i = 0; i < t; i++)
    {
        cin >> input[i];

        int score = 0, combo = 0;
        for (int j = 0; j < input[i].length(); j++)
        // sizeof() : get memory size of array, not length that I mean
        {
            if (input[i][j] == 'O')
            {
                combo += 1;
                score += combo;
            } else
            {
                combo = 0;
            }

            // test
            cout << "(" << i << ", " << j << ") " 
               << input[i][j] << " " << combo << " " << score << endl;
        }

        cout << score << endl;

    }

    return 0;
}