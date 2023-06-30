// 2738. 행렬 덧셈
// 2023.06.26

/* Sample input & output data
3 3
1 1 1
2 2 2
0 1 0
3 3 3
4 4 4
5 5 100

4 4 4
6 6 6
5 6 100
*/


#include <iostream>
#include <vector>

#define endl '\n'

using namespace std;

int main()
{
    // Declare
    int N, M;
    cin >> N >> M;
    vector<vector<int>> v(N, vector<int>(M, 0));

    // Input
    int temp;
    for (int i = 0; i < 2; i++)
    {
        for (int n = 0; n < N; n++)
        {
            for (int m = 0; m < M; m++)
            {
                cin >> temp;
                v[n][m] += temp;
            }
        }
    }

    // Output
    for (int n = 0; n < N; n++)
    {
        for (int m = 0; m < M; m++) cout << v[n][m] << ' ';
        cout << endl;
    }

    return 0;
}