#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for(int i = a; i < b; i++)

int t, n, cnt;
string s1, s2;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> t;
    while(t--){
        cin >> n >> s1;
        s2 = s1;
        sort(s1.begin(), s1.end());
        cnt = 0;
        rep(i, 0, s1.size()){
            cnt += (s1[i] != s2[i]);
        }
        cout << cnt << '\n';
    }
    return 0;
}