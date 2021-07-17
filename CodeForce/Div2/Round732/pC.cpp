#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for(int i = a; i < b; i++)

const int MAX_N = 100500;
struct NUMS{
    int num, pos;
    bool operator <(const NUMS &x){
        return num == x.num ? pos < x.pos : num < x.num;
    }
}a[MAX_N];
int t, n;
bool check(){
    int tmp;
    stack<bool> si;
    a[n].num = -1;
    rep(i, 0, n){
        if(!si.empty() && ((a[i].pos - i) & 1) == si.top()){
            si.pop();
        }else{
            si.push((a[i].pos - i) & 1);
        }
        if(a[i].num != a[i + 1].num){
            while(!si.empty()){
                if(si.top()){
                    return false;
                }
                si.pop();
            }
        }
    }
    return true;
}
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> t;
    while(t--){
        cin >> n;
        rep(i, 0, n){
            cin >> a[i].num;
            a[i].pos = i;
        }
        sort(a, a + n);                                  
        if( check() ){
            cout << "YES\n";
        }else{
            cout << "NO\n";
        }
    }
    return 0;
}