// 10250. ACM Hotel

/* Sample input & output data
2
6 12 10
30 50 72

402
1203
*/


#include <iostream>

using namespace std;
#define endl '\n'

int main()
{
    int T, H, W, N;
    // T : the number of test cases
    // H : the number of floors, < 99
    // W : the number of rooms on each floor, < 99
    // N : the index of the arrival time of the guest, < H * W 
    cin >> T;

    // Test T times
    for (int t = 0; t < T; t++)
    {
        cin >> H >> W >> N;

        // Operation
        int room = (N - 1) / H + 1; // room is prior to floor
        int floor = N % H;          // the first floor's room number is 1XX
        if (floor == 0)
        {
            floor = H;
        }

        // Output
        if (room < 10)
        {
            cout << floor << 0 << room << endl;
        } else
        {
            cout << floor << room << endl;
        }
    }

    return 0;
}