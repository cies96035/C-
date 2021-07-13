#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for(int i = a; i < b; i++)

int t;
int n, k;
int r;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> t;
    while(t--){
        cin >> n >> k;
        //int a;
        //cin >> a;
        rep(i, 0, n){
            if(i == n - 1){
                cout << n - 1 << endl;
            }else{
                cout << ( i ^ (i + 1) ) << endl;
            }
            cin >> r;
            if(r == 1){
                break;
            }
            if(r == -1){
                return 0;
            }
            //cout << "z = " << (a = (a ^ ( i ^ (i + 1) ))) << endl;
        }
    }
    return 0;
}