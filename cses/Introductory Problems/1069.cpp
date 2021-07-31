#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for(int i = a; i < b; i++)

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    char ipted, ipt;
    int cnt = 1, Max = 1;

    cin >> ipted;
    while(cin >> ipt){
        if(ipted != ipt){
            cnt = 1;
        }else{
            cnt++;
            Max = max(Max, cnt);
        }
        ipted = ipt;
    }
    cout << Max << '\n';
    return 0;
}