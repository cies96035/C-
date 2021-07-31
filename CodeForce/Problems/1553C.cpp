#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for(int i = a; i < b; i++)

int Min;
int t;
string s;
void DFS(int i, int a, int b){
    // cout << i << ' ' << a << ' ' << b << endl;
    if(i >= 10){
        return;
    }
    if(a + (5 - (i + 1) / 2) < b){
        Min = min(i, Min);
        return;
    }else if(b + (5 - i / 2) < a){
        Min = min(i, Min);
        return;
    }
    if(s[i] == '?'){
        DFS(i + 1, a + !(i & 1), b + (i & 1));
        DFS(i + 1, a, b);
    }else if(s[i] == '1'){
        DFS(i + 1, a + !(i & 1), b + (i & 1));
    }else{
        DFS(i + 1, a, b);
    }
}
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> t;
    while(t--){
        cin >> s;
        Min = 10;
        DFS(0, 0, 0);
        cout << Min << '\n';
    }
    return 0;
}