// 1620. 나는야 포켓몬 마스터 이다솜
// 2023.07.08

/* Sample input & output data
26 5
Bulbasaur
Ivysaur
Venusaur
Charmander
……

Pikachu
26
Venusaur
16
14
*/


#include <iostream>
#include <map>
#include <algorithm>

#define endl '\n'

using namespace std;


int pokedex(string name, map<string, int>* pokedexByName)
{
    int num = (*pokedexByName).find(name)->second;

    return num;
}

string pokedex(int num, map<int, string>* pokedexByNo)
{
    string name = (*pokedexByNo).find(num)->second;;

    return name;
}

int main()
{
    // Fast I/O
    cin.tie(0);
	ios::sync_with_stdio(false);

    // Input pokedexByNo
    int n, m;
    cin >> n >> m;
    map<string, int> pokedexByName;
    map<int, string> pokedexByNo;
    string temp;
    for (int i = 1; i <= n; i++)
    {
        cin >> temp;
        pokedexByName[temp] = i;
        pokedexByNo[i] = temp;
    }

    // Output
    for (int i = 1; i <= m; i++)
    {
        cin >> temp;
        if (temp[0] >= 'A' && temp[0] <= 'z') cout << pokedex(temp, &pokedexByName) << endl;
        else cout << pokedex(stoi(temp), &pokedexByNo) << endl;
    }

    return 0;
}
