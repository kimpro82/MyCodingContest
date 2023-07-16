// 25192. 인사성 밝은 곰곰이
// 2023.07.13

/* Sample input & output data
7
ENTER
pjshwa
chansol
chogahui05
ENTER
pjshwa
chansol

5
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

    int cnt = 0;
    string name;
    set<string> names;
    for (int i = 0; i < n; i++)
    {
        cin >> name;
        if (name == "ENTER") names.clear();
        else if (names.find(name) == names.end())
        {
            cnt++;
            names.insert(name);
        }
    }

    // Output
    cout << cnt << endl;

    return 0;
}
