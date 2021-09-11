// AtCoder Beginner Contest 218
// 2021-09-11(Sat) 21:00 - 22:40, 100 minutes

// D - Rectangles

/* Sample Input & Output
6
0 0
0 1
1 0
1 1
2 0
2 1
3

4
0 1
1 2
2 3
3 4
0

7
0 1
1 0
2 0
2 1
2 2
3 0
3 2
1
*/


#include <iostream>
#include <vector>
#include <map>

#define endl '\n'

using namespace std;

int main()
{
    // Input data
    int N;
    cin >> N;
    vector<vector<int>> points;
    for (int i = 0; i < N; i++)
    {
        int x, y;
        cin >> x >> y;
        vector<int> xy = {x, y};
        points.push_back(xy);
    }

    // Get 4 points' permutations and determine if it is a rectangle
    int count = 0;
    map<int, int> regt1, regt2;
    for (int i = 0; i < N - 3; i++)
    {
        regt1[points[i][0]]++;
        regt2[points[i][1]]++;

        for (int j = i + 1; j < N - 2; j++)
        {
            regt1[points[j][0]]++;
            regt2[points[j][1]]++;

            for (int k = j + 1; k < N - 1; k++)
            {
                regt1[points[k][0]]++;
                regt2[points[k][1]]++;

                for (int l = k + 1; l < N; l++)
                {
                    regt1[points[l][0]]++;
                    regt2[points[l][1]]++;

                    if (regt1.size() == 2 && regt2.size() == 2) count++;

                    regt1[points[l][0]]--;
                    regt2[points[l][1]]--;
                }

                regt1[points[k][0]]--;
                regt2[points[k][1]]--;
            }

            regt1[points[j][0]]--;
            regt2[points[j][1]]--;
        }
        regt1[points[i][0]]--;
        regt2[points[i][1]]--;
    }

    cout << count << endl;

    return 0;
}