// [BOJ] 단계별로 풀어보기 > 11. 브루트 포스

// 2798. JACK

/* Sample input & output data
5 21
5 6 7 8 9

21

10 500
93 181 245 214 315 36 185 138 216 295

497
*/


#include <iostream>
#include <vector>

using namespace std;

#define endl '\n'

int main()
{
    // Input 1 : N, M
    int N, M;
    cin >> N >> M;

    // Input 2 : N cards
    vector<int> cards;
    int temp;
    for (int n = 0; n < N; n++)
    {
        cin >> temp;
        cards.push_back(temp);
    }

    // Find the max value that does not exceed 21
    int sum, max = 0;
    for (int i = 0; i < N - 2; i++)
    {
        if (cards[i] > M) continue;

        for (int j = i + 1; j < N - 1; j++)
        {
            if (cards[i] + cards[j] > M) continue;

            for (int k = j + 1; k < N; k++)
            {
                sum = cards[i] + cards[j] + cards[k];

                // test
                cout << cards[i] << ' ' << cards[j] << ' ' << cards[k] << ' ' << sum << ' ' << max << endl;

                if (sum > M) continue;
                else if (sum > max) max = sum;
            }
        }
    }

    // Output
    cout << max << endl;

    return 0;
}