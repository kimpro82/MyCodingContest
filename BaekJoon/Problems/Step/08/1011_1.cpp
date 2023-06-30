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


#pragma GCC optimize ("O2")
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

        int distance = y - x, move = 0, turn = 0;
        while (true)
        {
            turn++;
            
            if (turn % 2 == 1) move = pow((turn + 1)/2, 2);
            else move = (pow(turn + 1, 2) - 1)/4;

            // test
            cout << turn << " " << move << " " << distance << " " << move - distance << endl;

            if (move >= distance) break;
        }

        // Output
        cout << turn << endl;
    }

    return 0;
}

/*
(ex) n = 3
    1 + 2 + 1
    = (1 + 2) * 2 - 2
    = {(n + 1)/2 * [{(n + 1)/2 + 1}/2] * 2 - (n + 1)/2
    * t = (n + 1)/2
    = t * (t + 1) - t
    = t^2
    = {(n + 1)/2}^2

(ex) n = 4
    1 + 2 + 2 + 1
    = (1 + 2) * 2
    = {(n/2) * (n/2 + 1)}/2 * 2
    = (n/2) * (n/2 + 1)
    = (n^2 + 2n + 1 - 1)/4
    = {(n + 1)^2 - 1}/4
*/