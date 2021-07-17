#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for(int i = a; i < b; i++)

int n, q;
int one;
int t, x;
bool a[100100];
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> n >> q;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        if(a[i]){
            one++;
        }
    }
    while(q--){
        cin >> t >> x;
        if(t == 1){
            if(a[x]){
                one--;
                a[x] = false;
            }else{
                one++;
                a[x] = true;
            }
        }else{
            cout << (x <= one ? 1 : 0) << '\n';
        }
    }

    return 0;
}