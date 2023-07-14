// 26069. 붙임성 좋은 총총이
// 2023.07.14

/* Sample input & output data
12
bnb2011 chansol
chansol chogahui05
chogahui05 jthis
jthis ChongChong
jthis jyheo98
jyheo98 lms0806
lms0806 pichulia
pichulia pjshwa
pjshwa r4pidstart
r4pidstart swoon
swoon tony9402
tony9402 bnb2011

10
*/


#include <iostream>
#include <set>
#include <algorithm>

#define endl '\n'

using namespace std;


int main()
{
    int n;
    cin >> n;

    string s1, s2, cc = "ChongChong";
    set<string> m = {cc};
    for (int i = 0; i < n; i++)
    {
        cin >> s1 >> s2;
        if (m.find(s1) != m.end()) m.insert(s2);
        if (m.find(s2) != m.end()) m.insert(s1);
    }

    // Output
    int cnt = m.size();
    cout << cnt << endl;

    return 0;
}
