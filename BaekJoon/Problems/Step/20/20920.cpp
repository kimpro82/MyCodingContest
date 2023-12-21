// 20920. 영단어 암기는 괴로워
// 2023.07.14

/* Sample input & output data
12 5
appearance
append
attendance
swim
swift
swift
swift
mouse
wallet
mouse
ice
age

swift
mouse
appearance
attendance
append
wallet
*/


#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

// #define test
#define endl '\n'

using namespace std;


bool comp(const pair<string, int>& a, const pair<string, int>& b)                                   // return true : a is the first & b is the second
{
    if (a.second != b.second) return a.second > b.second;                                           // 1) frequency
    else if (a.first.size() != b.first.size()) return a.first.size() > b.first.size();              // 2) length of the word
    else return a.first < b.first;                                                                  // 3) lexicographical order
}


int main()
{
    // Faster I/O
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    // Input
    int n, m;
    cin >> n >> m;
    map<string, int> mp;
    for (int i = 0; i < n; i++)
    {
        string temp;
        cin >> temp;

        if (temp.size() >= m)
        {
            if (mp.find(temp) == mp.end()) mp[temp] = 1;
            else mp[temp]++;
        }
    }

    // Sort with a new vector
    vector<pair<string, int>> v;
    for (auto it = mp.begin(); it != mp.end(); it++) v.push_back(pair<string, int> ((*it).first, (*it).second));
    sort(v.begin(), v.end(), comp);

    // Output
    for (auto it = v.begin(); it != v.end(); it++)
    {
        #ifdef test
            cout << (*it).first << ' ' << (*it).second << endl;
        #else
            cout << (*it).first << endl;
        #endif
    }

    return 0;
}
