// 2775. 부녀회장이 될테야

/* Sample input & output data
2
1
3
2
3

6
10
*/


#include <iostream>

using namespace std;
#define endl '\n'

int main()
{
    int T;
    cin >> T;

    // Test T times
    for (int t = 0; t < T; t++)
    {
        int K, N;
        cin >> K >> N;

        int resident[15][15] = {};      // assumed 0-th floor and 0-th room
        for (int k = 0; k <= K; k++)
        {
            for (int n = 0; n <= N; n++)
            {
                if (k == 0) resident[k][n] = n;
                else if (n <= 1) resident[k][n] = n;
                else resident[k][n] = resident[k-1][n] + resident[k][n-1];
            }
        }

        // Output
        cout << resident[K][N] << endl;
    }

    return 0;
}