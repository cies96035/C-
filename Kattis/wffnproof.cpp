#include<iostream>
#include<queue>
using namespace std;

string s;
queue<char> K;
queue<char> N;
queue<char> p;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    while(cin >> s && s != "0"){
        for(auto c : s){
            if(c == 'N'){
                N.push(c);
            }else if(c == 'K' || c == 'A' || c == 'C' || c == 'E'){
                K.push(c);
            }else if(c == 'p' || c == 'q' || c == 'r' || c == 's' || c == 't'){
                p.push(c);
            }
        }
        if(p.empty()){
            cout << "no WFF possible\n";
        }else{
            while(K.size() && p.size() > 1){
                cout << K.front() << p.front();
                K.pop();
                p.pop();
            }
            while(!N.empty()){
                cout << N.front();
                N.pop();
            }
            cout<< p.front() << '\n';
        }
        
        while(!K.empty()){
            K.pop();
        }
        while(!N.empty()){
            N.pop();
        }
        while(!p.empty()){
            p.pop();
        }
    }
    return 0;
}