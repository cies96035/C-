#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for(int i = a; i < b; i++)

stack<int> s;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    char c;
    while(cin >> c){
        if(c == '<'){
            cin >> c;
            if(c == 'U'){
                while(c != '>'){
                    cin >> c;
                }
                s.push(0);
            }else if(c == 'D'){
                while(c != '>'){
                    cin >> c;
                }
                s.push(1);
            }else{
                while(c != '>'){
                    cin >> c;
                }
                s.pop();
            }  
        }else{
            if(s.empty()){
                cout << c;
            }else if(s.top()){
                cout << char(('A' <= c && c <= 'Z') ? (c - 'A' + 'a') : c);
            }else{
                cout << char(('A' <= c && c <= 'Z') ? c : (c - 'a' + 'A'));
            }
        }
    }
    return 0;
}