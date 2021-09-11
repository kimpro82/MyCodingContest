// AtCoder Beginner Contest 218
// 2021-09-11(Sat) 21:00 - 22:40, 100 minutes

// B - qwerty

/* Sample Input & Output
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26
abcdefghijklmnopqrstuvwxyz

2 1 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26
bacdefghijklmnopqrstuvwxyz

5 11 12 16 25 17 18 1 7 10 4 23 20 3 2 24 26 19 14 9 6 22 8 13 15 21
eklpyqragjdwtcbxzsnifvhmou
*/


#include <iostream>
#include <vector>

#define endl '\n'

using namespace std;

int main()
{ 
    vector<int> P;
    int p;
    for (int i = 0; i < 26; i++)
    {
        cin >> p;
        P.push_back(p);
    }

    for (int i = 0; i < 26; i++) cout << (char) ('a' + P[i] - 1);
    cout << endl;

    return 0;
}