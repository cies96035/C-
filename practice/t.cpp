#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pll = pair<ll, ll>;
#define rep(i, a, b) for(int i = a; i < b; i++)
#define rrep(i, a, b) for(int i = a; i <= b; i++)
#define rvep(i, a, b) for(int i = a; i >= b; i--)


int arr[MAX], id;
void DFS(int x){
    for(i : nei(x))
        DFS(i);
    arr[id++] = x;
    cout << x << endl;
}

// for(i : arr) cout << i << endl;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    
    return 0;
}