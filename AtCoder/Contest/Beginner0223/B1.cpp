// AtCoder Beginner Contest 223
// 2021-10-17(Sun) 21:00 - 22:40, 100 minutes

// B - String Shifting

/* Sample Input & Output
aaba
aaab
baaa

z
z
z

abracadabra
aabracadabr
racadabraab
*/


#include <iostream>
#include <vector>

#define endl '\n'

using namespace std;

int main()
{
    // Input data
    string S;
    cin >> S;
    int size = S.length();

    // Declare vector v(26) to contain each alphabet
    vector<int> v(26, 0);
    for (int i = 0; i < size; i++) v[S[i] - 'a']++;

    // Output 1 : the lexicographically smallest
    for (int i = 0; i < 26; i++) for (int j = 0; j < v[i]; j++) cout << (char) (i + 'a');
    cout << endl;

    // Output 2 : the lexicographically largest
    for (int i = 25; i >=0; i--) for (int j = 0; j < v[i]; j++) cout << (char) (i + 'a');
    cout << endl;

    return 0;
}