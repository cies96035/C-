#include<iostream>
#include<sstream>
#include<set>
using namespace std;

int T;
string str;
string a, b, c;
set<string> Sound;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> T;
    while(T--){
        cin.ignore();
        getline(cin, str);
        stringstream ss(str);
        while(cin >> a >> b >> c){
            if(b == "does"){
                cin >> c >> c;
                break;
            }
            Sound.insert(c);
        }
        while(ss >> str){
            if(Sound.find(str) == Sound.end()){
                cout << str << ' ';
            }
        }
        cout << '\n';
        Sound.clear();
    }
    return 0;
}