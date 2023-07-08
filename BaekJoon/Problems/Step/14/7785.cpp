// 7785. Easy work(회사에 있는 사람)
// 2023.07.07

/* Sample input & output data
4
Baha enter
Askar enter
Baha leave
Artem enter

Askar
Artem
*/


#include <iostream>
#include <map>
#include <algorithm>

#define endl '\n'

using namespace std;


int main()
{
    // Input
    int n;
    cin >> n;
    map<string, string, greater<string>> m;                                     // required heavy googling
    string name, present;
    for (int i = 0; i < n; i++)
    {
        cin >> name >> present;
        m[name] = present;                                                      // more efficient
        // if (m.find(name) == m.end()) m.insert(pair<string, string> (name, present));
        // else m.find(name)->second = present;
    }

    // Output
    for (auto it = m.begin(); it != m.end(); it++) if (it->second == "enter") cout << it->first << endl;
  
    return 0;
}
