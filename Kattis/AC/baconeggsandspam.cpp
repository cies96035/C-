#include<iostream>
#include<map>
#include<set>
#include<sstream>
using namespace std;

map<string, set<string> >menu;
string tmp, name;
int n;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    while(cin >> n && n){
        cin.ignore();
        for(int i = 0; i < n; i++){
            getline(cin, tmp);
            stringstream ss(tmp);
            ss >> name;
            while(ss >> tmp){
                menu[tmp].insert(name);
            }
        }
        for(auto food : menu){
            cout << food.first;
            for(auto name : food.second){
                cout << ' ' << name;
            }
            cout << '\n';
        }
        cout << '\n';
        menu.clear();
    }

    return 0;
}