// 1931. 회의실 배정

/* Sample input & output data
11
1 4
3 5
0 6
5 7
3 8
5 9
6 10
8 11
8 12
2 13
12 14

4
*/


#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'

using namespace std;

bool comp(pair<int, int> p1, pair<int, int> p2)
{
    if (p1.second == p2.second) return p1.first <= p2.first;
    else return p1.second < p2.second;
}

int main()
{
    // Input data
    int n;
    cin >> n;

    vector<pair<int, int>> meeting;
    int start, end;
    for (int i = 0; i < n; i++)
    {
        cin >> start >> end;
        meeting.push_back(make_pair(start, end));
    }

    // Sort by start first, by end second
    sort(meeting.begin(), meeting.end(), comp);

    // Count by Greedy algorithm
    int count = 0, endPoint = 0;
    for (int i = 0; i < n; i++)
    {
        if (meeting[i].first >= endPoint)
        {
            count++;

            // test
            // cout << i << ' ' << meeting[i].first << ' ' << meeting[i].second << ' ' << endPoint << ' ' << count << endl;

            endPoint = meeting[i].second;
        }
    }

    // Output
    cout << count << endl;

    return 0;
}