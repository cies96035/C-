#include<bits/stdc++.h>
using namespace std;
#define f0r(i, a) for(int i = 0; i < a; i++)
#define f1r(i, a) for(int i = 1; i <= a; i++)
int t, n, k, ipt;
bool flg;
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> t; 
    while(t--){
        cin >> n >> k;
        flg = false;
        f0r(i, n){
            cin >> ipt;
            if(ipt) flg = true;
        }
        cout << (flg ? "YES\n" : "NO\n");
    }
    return 0;
}