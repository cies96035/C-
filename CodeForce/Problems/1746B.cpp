#include<bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < b; i++)
#define rrep(i, a, b) for(int i = a; i <= b; i++)
const int MAX_N = 1e5 + 5;
int t, n, a[MAX_N];
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cin >> t;
    while(t--){
        cin >> n;
        queue<int> o;
        stack<int> z;
        rep(i, 0, n){
            cin >> a[i];
            if(a[i]){
                o.push(i);
            }else{
                z.push(i);
            }
        }
        int cnt = 0;
        while(!o.empty() && !z.empty() && o.front() < z.top()){
            cnt++;
            o.pop();
            z.pop();
        }
        cout << cnt << '\n';
    }
    return 0;
}