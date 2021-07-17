#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for(int i = a; i < b; i++)

int num[4];
char c;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    while(cin >> c){
        if(c == '1') num[1]++;
        if(c == '2') num[2]++;
        if(c == '3') num[3]++;
    }
    bool flg = false;
    for(int i = 1; i <= 3; i++){
        while(num[i]--){
            if(flg){
                cout << '+';
            }else{
                flg = true;
            }
            cout << i;
        }
    }
    cout << '\n';
    return 0;
}