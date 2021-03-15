#include<iostream>
using namespace std;

string str;
int T;
bool even;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    for(int Case = 1; cin >> str && str != "END"; Case++){
        even = true;
        for(int i = 1; i < str.size(); i++){
            if(str[i] == '*'){
                T = i;
                break;
            }
        }
        for(int i = T; i < str.size(); i++){
            if(str[i - T] != str[i]){
                even = false;
                break;
            }
        }
        cout << Case << (even ? " EVEN" : " NOT EVEN") << '\n';
    }
    return 0;
}