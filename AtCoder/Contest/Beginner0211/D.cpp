// AtCoder Beginner Contest 211
// 2021-07-24(Satn) 21:00 - 22:40, 100 minutes

//  - Number of Shortest paths

/* Sample Input & Output
4 5
2 4
1 2
2 3
1 3
3 4

2

4 3
1 3
2 3
2 4

1
*/


#include <iostream>
#include <vector>

using namespace std;

int main()
{
    // Input data
    int N, M;
    cin >> N >> M;

    vector<pair<int, int>> v;
    int temp1, temp2;
    for (int i = 0; i < M; i++)
    {
        cin >> temp1 >> temp2;
        v.push_back(pair<int, int> (temp1, temp2));
    }

    // Find the minimum hours to move
    int count = 0, start = 1;
    while (true)
    {
        // need more codes ……
    }

    // I can't postpone anymore to say good game ……

    return 0;
}