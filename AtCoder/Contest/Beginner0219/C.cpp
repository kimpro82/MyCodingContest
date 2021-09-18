// AtCoder Beginner Contest 219
// 2021-09-18(Sat) 21:00 - 22:40, 100 minutes

// C - Neo-lexicographic Ordering

/* Sample Input & Output
bacdefghijklmnopqrstuvwxzy
4
abx
bzz
bzy
caa

bzz
bzy
abx
caa

zyxwvutsrqponmlkjihgfedcba
5
a
ab
abc
ac
b

b
a
ac
ab
abc
*/


#include <iostream>
#include <list>

#define endl '\n'

using namespace std;

int main()
{
    string X;
    int N;
    cin >> X >> N;

    list<string> S;
    string temp;

    string s;
    cin >> s;           // Insert the first element into list S
    S.push_back(s);

    for (int n = 1; n < N; n++)
    {
        cin >> s;
        bool sorted = false;
        for (auto it = S.begin(); it != S.end(); it++)
        {
            for (int i = 0; i < s.size(); i++)
            {
                int newIdx, oldIdx;
                newIdx = X.find(s[i]);
                if (i < (*it).size()) oldIdx = X.find((*it)[i]);
                else oldIdx = -1;
                
                // test
                // cout << n << ' ' << s << ' ' << s[i] << ' ' << newIdx << ' ' << *it << ' ' << (*it)[i] << ' ' << oldIdx << endl;

                if (newIdx < oldIdx)
                {
                    S.insert(it, s);
                    sorted = true;
                    break;
                }
                else if (newIdx > oldIdx) break;
            }

            if (sorted == true) break;
        }
        if (sorted == false) S.push_back(s);
    }

    for (auto it = S.begin(); it != S.end(); it++) cout << *it << endl;

    return 0;
}

// TLE