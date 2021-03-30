#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAX_N = 5000500;
ll BIT[MAX_N];
int n, a, b, Q;
char op;

int lowbits(int x){
    return x & (-x);
}
void modify(int pos, ll x){
    while(pos <= n){
        BIT[pos] += x;
        pos += lowbits(pos);
    }
}
ll query(int pos){
    ll ans = 0;
    while(pos > 0){
        ans += BIT[pos];
        pos -= lowbits(pos);
    }
    return ans;
}
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> n >> Q;
    n++;
    while(Q--){
        cin >> op;
        if(op == '+'){
            cin >> a >> b;
            modify(a + 1, b);
        }else{
            cin >> a;
            cout << query(a) << '\n';
        }
    }
    return 0;
}