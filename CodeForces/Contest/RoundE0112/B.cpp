// Educational Codeforces Round 112 (Rated for Div. 2)
// 2021.07.30 23:35, 2 hrs

// B. Two Tables

/* Sample Input & Output
5
8 5
2 1 7 4
4 2
5 4
2 2 5 4
3 3
1 8
0 3 1 6
1 5
8 1
3 0 6 1
5 1
8 10
4 5 7 8
8 5

1.000000000
-1
2.000000000
2.000000000
0.000000000
*/
 
 
#include <iostream>
#include <cmath>
#include <array>

using namespace std;

#define endl '\n'
 
int main()
{
    int t;
    cin >> t;
 
    for (int i = 0; i < t; i++)
    {
        // Input data
        int W, H, x1, y1, x2, y2, w, h;
        cin >> W >> H >> x1 >> y1 >> x2 >> y2 >> w >> h;
 
        // Calculate distance
        int distance, dist1 = -1, dist2 = -1, dist3 = -1, dist4 = -1;   // don't need to declare distance as double
        if ((x2 - x1) + w > W && (y2 - y1) + h > H) distance = -1;
        else if ((x2 - x1) + w <= W && (y2 - y1) + h > H)
        {
            dist1 = max(w - x1, 0);
            dist2 = max((x2 + w) - W, 0);
            distance = min(dist1, dist2);

            // test
            cout << (x2 - x1) + w << ' ' << (y2 - y1) + h << " (else if 1) "  << dist1 << ' ' << dist2 << endl;
        }
        else if ((x2 - x1) + w > W && (y2 - y1) + h <= H)
        {
            dist1 = max(h - y1, 0);
            dist2 = max((y2 + h) - H, 0);
            distance = min(dist1, dist2);

            // test
            cout << (x2 - x1) + w << ' ' << (y2 - y1) + h << " (else if 2) "  << dist1 << ' ' << dist2 << endl;
        }
        else
        {
            dist1 = max(w - x1, 0);
            dist2 = max((x2 + w) - W, 0);
            dist3 = max(h - y1, 0);
            dist4 = max((y2 + h) - H, 0);
            array<int, 3> dist = {dist2, dist3, dist4};
            int minValue = dist1;
            for (int j = 0; j < 3; j++) if (dist[j] < minValue) minValue = dist[j];
            distance = minValue;

            // cout << "An else case exists! {" << i << '}' << endl;    // to find failed test case
            // continue;
        }

        // Output
        // cout.precision(10);
        cout << distance << endl;

    } // The end of t loop

    return 0;
}