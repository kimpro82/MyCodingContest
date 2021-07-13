// 1011. Fly me to the Alpha Centauri

/* Sample input & output data
3
0 3
1 5
45 50

3
3
4
*/


#pragma GCC optimize ("Ofast")
#pragma GCC target ("avx")

#include <iostream>
#include <cmath>
#include<bits/stdc++.h>

using namespace std;
#define endl '\n'

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int T;
    cin >> T;

    // Test T times
    for (int t = 0; t < T; t++)
    {
        int x, y;
        cin >> x >> y;

        int distance = y - x, move = 0;
        int turn = 2 * sqrt(distance) - 2;
        
        while (true)
        {
            turn++;
            
            if (turn % 2 == 1) move = pow((turn + 1)/2, 2);
            else move = (pow(turn + 1, 2) - 1)/4;

            // test
            // cout << turn << " " << move << " " << distance << " " << move - distance << endl;

            if (move >= distance) break;
        }

        // Output
        cout << turn << endl;
    }

    return 0;
}

// n is even : distance = {(n + 1)/2}^2
// → n = 2 * sqrt(distance) - 1
// n is odd  : distance = {(n + 1)^2 - 1}/4