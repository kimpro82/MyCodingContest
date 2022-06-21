// 11047. 동전 0

/* Sample input & output data
10 4200
1
5
10
50
100
500
1000
5000
10000
50000

6
*/


#include <iostream>
#include <vector>
#define endl '\n'

using namespace std;

int main()
{
    // Input data
    int n, k;
    cin >> n >> k;

    vector<int> coins;
    int coin;
    for (int i = 0; i < n; i++)
    {
        cin >> coin;
        coins.push_back(coin);
    }

    // Count with the Greedy algorithm
    int count = 0, freq;
    for (int i = 0; i < n; i++)
    {
        freq = k / coins[n - i - 1];
        k -= freq * coins[n - i - 1];
        count += freq;
    }
    
    // Output
    cout << count << endl;

    return 0;
}