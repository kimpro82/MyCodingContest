// 2563. 색종이
// 2023.06.27

/* Sample input & output data
3
3 7
15 7
5 2

260
*/


#include <iostream>
#include <vector>

#define endl '\n'

using namespace std;

int main()
{
    // Declare
    int len1 = 100, len2 = 10;
    vector<vector<int>> v(len1, vector<int> (len1, 0));
    int N, a, b;
    cin >> N;

    // Input
    int temp;
    for (int n = 0; n < N; n++)
    {
        cin >> a >> b;
        for (int i = 0; i < len2; i++) for (int j = 0; j < len2; j++) v[a+i][b+j] = 1;
    }

    // Output
    int sum = 0;
    for (int i = 0; i < len1; i++) for (int j = 0; j < len1; j++) if (v[i][j] > 0) sum++;
    cout << sum << endl;

    return 0;
}