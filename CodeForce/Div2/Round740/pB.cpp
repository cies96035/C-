#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for(int i = a; i < b; i++)

int a, b;
int z, o;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    int t;
    cin >> t;
    while(t--){
        set<int> ans;
        int u, d;
        cin >> a >> b;
        z = (a + b) / 2;
        o = (a + b) - z;

        //a's 0 + b's 1
        if(b > z){
            u = (a + b) - (b - o);
        }else{
            u = b + o;
        }

        if(b < o){
            d = o - b;
        }else{
            d = b - o;
        }

        // cout << u << ' ' << d << endl;
        for(int i = d; i <= u; i += 2){
            ans.insert(i);
        }

        //a's 1 + b's 0
        if(a > z){
            u = (a + b) - (a - o);
        }else{
            u = a + o;
        }

        if(a < o){
            d = o - a;
        }else{
            d = a - o;
        }
        // cout << u << ' ' << d << endl;
        
        for(int i = d; i <= u; i += 2){
            ans.insert(i);
        }
        cout << ans.size() << '\n';
        for(auto i : ans){
            cout << i << ' ';
        }
        cout << '\n';
    }
    return 0;
}