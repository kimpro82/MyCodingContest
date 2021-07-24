// AtCoder Beginner Contest 211
// 2021-07-24(Satn) 21:00 - 22:40, 100 minutes

// B - Cycle Hit

/* Sample Input & Output
3B
HR
2B
H

Yes

2B
3B
HR
3B

No
*/


#include <iostream>
#include <map>

using namespace std;

int main()
{
    map<string, int> m;
    string temp;
    bool isYes = true;
    for (int i = 0; i < 4; i++)
    {
        cin >> temp;
        if (m.find(temp) == m.end())
        {
            m.insert(pair<string, int> (temp, 1));
        }
        else
        {
            isYes = false;
            break; 
        };        
    }

    if (isYes == true) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}