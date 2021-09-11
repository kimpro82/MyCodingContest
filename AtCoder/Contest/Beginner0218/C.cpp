// AtCoder Beginner Contest 218
// 2021-09-11(Sat) 21:00 - 22:40, 100 minutes

// C - Shapes

/* Sample Input & Output
5
.....
..#..
.###.
.....
.....
.....
.....
....#
...##
....#
Yes

5
#####
##..#
#..##
#####
.....
#####
#..##
##..#
#####
.....
No

4
#...
..#.
..#.
....
#...
#...
..#.
....
Yes

4
#...
.##.
..#.
....
##..
#...
..#.
....
No
*/


#include <iostream>
#include <vector>

#define endl '\n'

using namespace std;

int main()
{
    // Input data
    int N;
    cin >> N;

    vector<string> S, T;
    string temp;
    for (int i = 0; i < N; i++)
    {
        cin >> temp;
        S.push_back(temp);
    }
    for (int i = 0; i < N; i++)
    {
        cin >> temp;
        T.push_back(temp);
    }

    // Find the row and column range including '#' from S and T
    int sRowS = -1, sRowE = -1, sColS = -1, sColE = -1;
    int tRowS = -1, tRowE = -1, tColS = -1, tColE = -1;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (S[i][j] == '#')
            {
                if (sRowS == -1) sRowS = j;
                if (sColS == -1) sColS = i;
            }
        }        
    }

    return 0;
}