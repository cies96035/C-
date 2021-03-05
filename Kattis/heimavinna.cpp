#include<iostream>
using namespace std;

string hw;
int strToNum(string x){
    int n = 0;
    for(auto i : x){
        n = 10 * n + i - '0';
    }
    return n;
}
int pos;
int cnt;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    while(getline(cin, hw, ';')){
        while((hw.back() == ';') || hw.back() == '\n'){
            hw.resize(hw.size() - 1);
        }
        pos = -1;
        for(int i = 0; i < hw.size(); i++){
            if(hw[i] == '-'){
                pos = i;
                break;
            }
        }
        if(pos != -1){
            cnt += strToNum(hw.substr(pos + 1, hw.size() - pos - 1)) - 
            strToNum(hw.substr(0, pos));
        }
        cnt++;
    }
    cout << cnt << '\n';
    return 0;
}