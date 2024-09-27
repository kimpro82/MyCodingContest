// AtCoder Beginner Contest 216
// 2021-08-29(Sun) 21:00 - 22:40, 100 minutes

// B - Same Name

/* Sample Input & Output
3
tanaka taro
sato hanako
tanaka taro
Yes

3
saito ichiro
saito jiro
saito saburo
No

4
sypdgidop bkseq
bajsqz hh
ozjekw mcybmtt
qfeysvw dbo
No
*/


#include <iostream>
#include <vector>
#include <algorithm>

#define endl '\n'

using namespace std;

int main()
{
    int N;
    cin >> N;

    vector<pair<string, string>> name;
    bool same = false;
    for (int n = 0; n < N; n++)
    {
        string s, t;
        cin >> s >> t;

        // Determine if the same name exists
        auto it = find(name.begin(), name.end(), pair<string, string> (s, t));
        if (it == name.end()) name.push_back(pair<string, string> (s, t));
        else
        {
            same = true;
            break;
        }
    }

    // Output
    if (same == true) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}