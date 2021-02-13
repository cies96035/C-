#include<iostream>
#include<set>
#include<algorithm>
using namespace std;

int op;
int gender;
int cnt;
string name;
string S, E;
set<string> boybaby;
set<string> girlbaby;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    while(cin >> op && op){
        if(op == 1){
            cin >> name >> gender;
            if(gender == 1){
                boybaby.insert(name);
            }else{
                girlbaby.insert(name);
            }
        }else if(op == 2){
            cin >> name;
            if(boybaby.find(name) != boybaby.end()){
                boybaby.erase(name);
            }else{
                girlbaby.erase(name);
            }
        }else{
            cnt = 0;
            cin >> S >> E >> gender;
            if(gender == 0 || gender == 1){
                cnt += boybaby.upper_bound(E) - boybaby.begin();//.lower_bound(S);
            }
            if(gender == 0 || gender == 2){
                cnt += girlbaby.upper_bound(E) = girlbaby.lower_bound(S);
            }
            cout << cnt << '\n';
        }
    }
    return 0;
}