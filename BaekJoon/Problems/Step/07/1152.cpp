/* Sample input & output data
The Curious Case of Benjamin Button
6

Mazatneunde Wae Teullyeoyo
3

Teullinika Teullyeotzi 
2
*/


#include <iostream>
#include <string>
#include <vector>

using namespace std;
#define endl '\n'

int main()
{
    // Input
    vector<string> s;
    string temp;
    while (true)
    {
        cin >> temp;
        if (cin.eof() == true)
        {
            break;
        } else
        {
            s.push_back(temp);
        }
    }

    cout << s.size() << endl;

    return 0;
}