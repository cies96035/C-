#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for(int i = a; i < b; i++)

int t, n, cnt;
string a, b;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> t;
    while(t--){
        cnt = 0;
        cin >> n >> a >> b;
        rep(i, 0, n){
            if(b[i] == '1'){
                if(a[i] == '0'){
                    cnt++;
                }else if(i > 0 && a[i - 1] == '1'){
                    cnt++;
                }else if(i < n && a[i + 1] == '1'){ 
                    a[i + 1] = '0';
                    cnt++;
                }
            }
        }
        cout << cnt << '\n';
    }
    return 0;
}