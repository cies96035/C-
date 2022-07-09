#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pll = pair<ll, ll>;
#define rep(i, a, b) for(int i = a; i < b; i++)
#define rrep(i, a, b) for(int i = a; i <= b; i++)
#define rvep(i, a, b) for(int i = a; i >= b; i--)

const int MAX_N = 2e5 + 5;
int n, m;
int a[2], p[2];
int arr[MAX_N], pos[MAX_N];
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> n >> m;
    rrep(i, 1, n){
        cin >> arr[i];
        pos[ arr[i] ] = i;
    }
    pos[0] = arr[0] = 0;
    pos[n + 1] = arr[n + 1] = n + 1;
    int cnt = 1;
    rrep(i, 1, n){
        if(pos[i] < pos[i - 1]) cnt++;
    }
    rep(i, 0, m){
        cin >> p[0] >> p[1];

        a[0] = arr[ p[0] ], a[1] = arr[ p[1] ];
        if(a[0] > a[1]) swap(a[0], a[1]);

        rep(j, 0, 2){
            if(pos[ a[j] ] < pos[ a[j] - 1 ]) cnt--;
            if(pos[ a[j] + 1 ] < pos[ a[j] ]) cnt--;
        }
        if(a[1] - a[0] == 1 && pos[ a[1] ] < pos[ a[0] ]) cnt++;

        swap(pos[ a[0] ], pos[ a[1] ]);
        swap(arr[ p[0] ], arr[ p[1] ]);

        rep(j, 0, 2){
            if(pos[ a[j] ] < pos[ a[j] - 1 ]) cnt++;
            if(pos[ a[j] + 1 ] < pos[ a[j] ]) cnt++;
        }
        if(a[1] - a[0] == 1 && pos[ a[1] ] < pos[ a[0] ]) cnt-- ;

        cout << cnt << '\n';
    }
    return 0;
}