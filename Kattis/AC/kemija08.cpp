#include<iostream>
using namespace std;

string str;
bool blank;
bool Map[256];
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    Map['a'] = Map['e'] = Map['i'] = Map['o'] = Map['u'] = true;
    while(cin >> str){
        if(blank){
            cout << ' ';
        }else{
            blank = true;
        }
        for(int i = 0; i < str.size(); i++){
            cout << str[i];
            if(i + 2 < str.size() && str[i] == str[i + 2] && str[i + 1] == 'p' && Map[ str[i] ]){
                i += 2;
            }
        }
    }
    cout << '\n';
    return 0;
}