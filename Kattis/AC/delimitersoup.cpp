#include<iostream>
#include<stack>
using namespace std;

stack<char> s;
string str;
int Map[256];
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    Map['('] = 1;
    Map[')'] = -1;
    Map['['] = 2;
    Map[']'] = -2;
    Map['{'] = 3;
    Map['}'] = -3;

    cin >> str;
    cin.ignore();
    getline(cin, str);

    for(int i = 0; i < str.size(); i++){
        if(Map[str[i]] > 0){
            s.push(Map[str[i]]);
        }else if(Map[ str[i] ] < 0){
            if(s.empty() || s.top() != -Map[ str[i] ]){
                cout << str[i] << ' ' << i <<'\n';
                return 0;
            }else{
                s.pop();
            }
        }
    }
    cout << "ok so far\n";
    return 0;
}