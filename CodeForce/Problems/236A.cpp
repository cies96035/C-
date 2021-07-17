#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for(int i = a; i < b; i++)

string str;
int cnt;
bool alpha[256];
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> str;
    for(auto c : str){
        if(!alpha[c]){
            cnt++;
            alpha[c] = true;
        }
    }
    if(cnt & 1){
        cout << "IGNORE HIM!\n";
    }else{
        cout << "CHAT WITH HER!\n";
    }
    return 0;
}