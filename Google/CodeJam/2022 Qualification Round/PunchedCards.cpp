/* Sample Input & Output
3
3 4
2 2
2 3

Case #1:
..+-+-+-+
..|.|.|.|
+-+-+-+-+
|.|.|.|.|
+-+-+-+-+
|.|.|.|.|
+-+-+-+-+
Case #2:
..+-+
..|.|
+-+-+
|.|.|
+-+-+
Case #3:
..+-+-+
..|.|.|
+-+-+-+
|.|.|.|
+-+-+-+
*/


#include <iostream>

#define endl '\n'

using namespace std;

int main()
{
    int T;
    cin >> T;

    for (int t = 1; t <= T; t++)
    {
        int R, C;
        cin >> R >> C;

        cout << "Case #" << t << ':' << endl;

        for (int r = 0; r <= 2 * R; r++)
        {
            for (int c = 0; c <= 2 * C; c++)
            {
                // test
                // cout << r << c;

                // The first row (additional) : ..+-+-+-+
                if (r == 0)
                {
                    if (c == 0)                                         // c == 0 : for running only once in the first row
                    {
                        for (int i = 0; i <= 2 * C; i++)
                        {
                            if (i < 2) cout << '.';
                            else if (i % 2 == 0) cout << '+';
                            else cout << '-';
                        }
                    }
                }
                // The first column except the first row (additional)
                else if (c == 0)
                {
                    if (r == 1) cout << ".";
                    else if (r % 2 == 0) cout << '+';
                    else cout << '|';
                }
                // Residual cells
                else if (r % 2 == 1)
                {
                    if (c % 2 == 1) cout << '.';
                    else cout << '|';
                }
                else
                {
                    if (c % 2 == 1) cout << '-';
                    else cout << '+';
                }
            }
            cout << endl;
        }
    }

    return 0;
}