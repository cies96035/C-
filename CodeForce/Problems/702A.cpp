#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for(int i = a; i < b; i++)

int cnt = 1;
int Max = 1;
int n;
int ipt, ipted;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> n;
    cin >> ipted;
    rep(i, 1, n){
        cin >> ipt;
        if(ipt > ipted){
            cnt++;
            if(Max < cnt){
                Max = cnt;
            }
        }else{
            cnt = 1;
        }
        ipted = ipt;
    }
    cout << Max << '\n';
    return 0;
}