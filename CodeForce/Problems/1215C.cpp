#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
#define rep(i, a, b) for(int i = a; i < b; i++)

int n;
string s, t;
queue<int> ab, ba;
queue<pii> ans;
int cnt = 0;
int getQueue(queue<int> &qi){
    int tmp = qi.front();
    qi.pop();
    return tmp;
}
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> n;
    cin >> s >> t;
    rep(i, 0, n){
        if(s[i] != t[i]){
            if(s[i] == 'a'){
                ab.push(i + 1);
            }else{
                ba.push(i + 1);
            }
        }
    }
    while(ab.size() > 1)
        ans.push( {getQueue(ab), getQueue(ab)} );
    while(ba.size() > 1)
        ans.push( {getQueue(ba), getQueue(ba)} );
    if(ab.size() && ba.size()){
        ans.push( {ab.front(), ab.front()} );
        ans.push( {getQueue(ab), getQueue(ba)} );
    }
    
    if(ab.size() || ba.size()){
        cout << "-1\n";
    }else{
        cout << ans.size() << '\n';
        while(!ans.empty()){
            cout << ans.front().first << ' ' << ans.front().second << '\n';
            ans.pop();
        }
    }
    return 0;
}