#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pll = pair<ll, ll>;
#define rep(i, a, b) for(int i = a; i < b; i++)
#define rrep(i, a, b) for(int i = a; i <= b; i++)
#define rvep(i, a, b) for(int i = a; i >= b; i--)

bool vis[50];
set<int> s;
int cnt = 0;
int n, k;
int arr[50], aid = 0;
void DFS(int c){
    if(vis[c]){
        return;
    }
    vis[c] = true;
    arr[aid++] = c;
    s.insert(c % n);
    int a = 0, b = 0;
    for(int i = c + 1; true; i++){
        if(!s.count(i % n)){
            break;
        }
        a++;
    }
    for(int i = c - 1; true; i += n - 1){
        if(!s.count(i % n)){
            break;
        }
        b++;
    }
    if(a + b + c >= k){
        cnt++;
        rep(i, 0, aid){
            cout << arr[i] << ' ';
        }
        cout << endl;
    }
    rrep(i, 1, n){
        DFS(i);
    }
    s.erase(c % n);
    vis[c] = false;
    aid--;
}
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> n;
    k = n / 2;
    DFS(1);
    return 0;
}