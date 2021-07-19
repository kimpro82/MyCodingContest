// [BOJ] 단계별로 풀어보기 > 9. 기본 수학 2

// 3009. 네 번째 점

/* Sample input & output data
5 5
5 7
7 5

7 7

30 20
10 10
10 20

30 10
*/


#include <iostream>
#include <vector>
#include <map>

using namespace std;
#define endl '\n'

int main()
{
    // Input data
    map<int, int> x, y;
    int temp1, temp2;
    for (int i = 0; i < 3; i++)
    {
        cin >> temp1 >> temp2;
        x.insert(pair<int, int> (temp1, 1));
        y.insert(pair<int, int> (temp2, 1));
    }

    // Find the 4th point : hope to find more efficient way, but ……
    int x4, y4;
    for (auto it = x.begin(); it != x.end(); it++)
    {
        if (x.count(it->second) == 1)
        {
            x4 = it->first;
            break;
        }
    }
    for (auto it = y.begin(); it != y.end(); it++)
    {
        if (y.count(it->second) == 1)
        {
            y4 = it->first;
            break;
        }
    }

    // Output
    cout << x4 << ' ' << y4 << endl;

    return 0;
}