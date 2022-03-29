// [BOJ] 단계별로 풀어보기 > 11. 브루트 포스

// 1018. 체스판 다시 칠하기

/* Sample input & output data
11 12
BWWBWWBWWBWW
BWWBWBBWWBWW
WBWWBWBBWWBW
BWWBWBBWWBWW
WBWWBWBBWWBW
BWWBWBBWWBWW
WBWWBWBBWWBW
BWWBWBWWWBWW
WBWWBWBBWWBW
BWWBWBBWWBWW
WBWWBWBBWWBW

15
*/


#include <iostream>
#include <vector>

using namespace std;

#define endl '\n'

int main()
{
    // Input N, M
    int N, M;                                                                               // 8 <= N, M <= 50
    cin >> N >> M;

    // Input wb
    vector<string> wb;
    for (int i = 0; i < N; i++)
    {
        string temp;
        cin >> temp;
        wb.push_back(temp);
    }

    // Find the minimum number to paint the cell for (N - 8 + 1, M - 8 + 1)
    int min = 8 * 8;
    // Loop for (r, c) : the reference point at the top left corner
    for (int r = 0; r < N - 8 + 1; r++)
    {
        for (int c = 0; c < M - 8 + 1; c++)
        {
            // Loop for 8 * 8 from each (r, c)
            int change, changeW = 0, changeB = 0;                                           // changeW/B : the reference point can be W and B both
            for (int i = 0; i < 8; i++)
            {
                for (int j = 0; j < 8; j++)
                {
                    if ((i + j) % 2 == 0)                                                   // no change if the same with (r, c)
                    {
                        if (wb[r + i][c + j] == 'W') changeB++;
                        else changeW++;
                    }
                    else                                                                    // change if the same with (r, c)
                    {
                        if (wb[r + i][c + j] == 'B') changeB++;
                        else changeW++;
                    }
                }
            }

            // determine if the number of changes is smaller than the previous min
            if (changeW < changeB) change = changeW;
            else change = changeB;
            if (min > change) min = change;
        }
    }

    // Output
    cout << min << endl;

    return 0;
}