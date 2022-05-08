// Codeforces Round #784 (Div. 4)
// 2022.04.21 23:35, 2 hrs

// A. Division?

/* Sample Input & Output
7
-789
1299
1300
1399
1400
1679
2300

Division 4
Division 4
Division 4
Division 4
Division 3
Division 2
Division 1
*/


#include <iostream>

#define endl '\n'

using namespace std;

int main()
{
    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        // Input data
        int rating;
        cin >> rating;

        int division;
        if (rating >= 1900) division = 1;
        else if (rating >= 1600) division = 2;
        else if (rating >= 1400) division = 3;
        else division = 4;

        // Output
        cout << "Division " << division << endl;
    }

    return 0;
}