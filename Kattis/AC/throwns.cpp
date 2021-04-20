#include<bits/stdc++.h>
using namespace std;

stack<int> s;
int n, k;
int p, ans;
string str;

int strToNum(const string & x){
    int num = 0;
    for(auto c : x){
        if(c == '-'){
            continue;
        }
        if(x[0] == '-'){
            num = num * 10 - (c - '0');
        }else{
            num = num * 10 + (c - '0');
        }
    }   
    return num;
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> n >> k;
    while(k--){
        cin >> str;
        if(str == "undo"){
            cin >> p;
            while(p--){
                s.pop();
            }
        }else{
            s.push( strToNum(str) );
        }
    }
    while(!s.empty()){
        ans += s.top();
        s.pop();
    }
    cout << (ans % n + n) % n << '\n';
}