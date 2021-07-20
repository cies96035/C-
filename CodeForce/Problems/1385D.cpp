#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for(int i = a; i < b; i++)

int t;
int n;
string str;
int cost(int l, int r, char depth){ //[l, r)
    int cnt = 0;
    while(l < r){
        if(str[l] != depth){
            cnt++;
        }
        l++;
    }
    return cnt;
}
int Mingood(int l, int r, char depth){ //[l, r)
    if(r - l == 1){
        return str[l] != depth;
    }
    int mid = (l + r) >> 1;
    return min( 
        Mingood(mid, r, depth + 1) + cost(l, mid, depth),
        Mingood(l, mid, depth + 1) + cost(mid, r, depth)
    );
}
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> t;
    while(t--){
        cin >> n >> str;
        cout << Mingood(0, n, 'a') << '\n';
    }
    return 0;
}