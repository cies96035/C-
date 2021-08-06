#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i, a, b) for(int i = a; i <= b; i++)

const int MAX_N = 2e5 + 5;
int n, x;
pii a[MAX_N];
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> n >> x;
    rep(i, 1, n){
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a + 1, a + n + 1);
    int i = 1, j = n;
    while(i < j){
        if(a[i].first + a[j].first == x){
            cout << a[i].second << ' ' << a[j].second << '\n';
            return 0;
        }else if(a[i].first + a[j].first < x){
            i++;
        }else{
            j--;
        }
    }
    cout << "IMPOSSIBLE\n";
    return 0;
}