// AtCoder Beginner Contest 219
// 2021-09-18(Sat) 21:00 - 22:40, 100 minutes

// B - Maritozzo

/* Sample Input & Output
mari
to
zzo
1321
marizzotomari

abra
cad
abra
123
abracadabra

a
b
c
1
a
*/


#include <iostream>
#include <vector>

#define endl '\n'

using namespace std;

int main()
{
    vector<string> S;
    string T, temp;
    for (int i = 0; i < 3; i++)
    {
        cin >> temp;
        S.push_back(temp);
    }
    cin >> T;

    int idx;
    for (int i = 0; i < T.size(); i++)
    {
        idx = T[i] - '0' - 1;
        cout << S[idx];
    }
    cout << endl;

    return 0;
}