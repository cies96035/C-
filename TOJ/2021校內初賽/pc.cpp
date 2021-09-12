#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
#define rep(i, a, b) for(int i = a; i < b; i++)
#define X first
#define Y second

int q;
pll a = {1, 0}, b = {1, 0};
int op, x, y;
char c;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> q;
    while(q--){
        cin >> op;
        if(op == 1){
            cin >> x;
            cout << max(a.X * x + a.Y, b.X * x + b.Y) << '\n';
        }else if(op == 2){
            cin >> x >> c >> y;
            if(x == 1){
                if(c == '+'){
                    a.Y += y;
                }else{
                    a.X *= y;
                    a.Y *= y;
                }
            }else{
                if(c == '+'){
                    b.Y += y;
                }else{
                    b.X *= y;
                    b.Y *= y;
                }
            }
        }else{
            if(a.X == b.X || (b.Y - a.Y) % (a.X - b.X)){
                cout << "no\n";
            }else{
                cout << (b.Y - a.Y) / (a.X - b.X) << '\n';
            }
        }
    }
    return 0;
}