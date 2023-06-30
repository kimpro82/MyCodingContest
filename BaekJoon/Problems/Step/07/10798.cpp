// 10798. 세로읽기
// 2023.06.27

/* Sample input & output data
AABCDD
afzz
09121
a8EWg6
P5h3kx

Aa0aPAf985Bz1EhCz2W3D1gkD6x
*/


#include <iostream>
#include <vector>

#define endl '\n'

using namespace std;

int main()
{
    // Declare
    int row = 5, col = 15;
    vector<vector<char>> v(row, vector<char>(col, '.'));

    // Input
    string s;
    int len;
    for (int i = 0; i < row; i++)
    {
        cin >> s;
        len = s.size();
        for (int j = 0; j < len; j++) v[i][j] = s[j];
    }

    // Output
    for (int j = 0; j < col; j++) for (int i = 0; i < row; i++) if (v[i][j] != '.') cout << v[i][j];
    cout << endl;

    return 0;
}