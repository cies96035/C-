#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for(int i = a; i < b; i++)

string num;
bool leadingZero;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> num;
    leadingZero = true;
    for(auto &c : num){
        if('5' <= c){
            c = '9' - c + '0';
        }
    }
    if(num[0] == '0'){
        num[0] = '9';
    }
    cout << num << '\n';
    return 0;
}