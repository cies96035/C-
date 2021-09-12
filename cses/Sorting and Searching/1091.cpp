#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for(int i = a; i < b; i++)

int n, m;
int h, t;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> n >> m;
    multiset<int> ticket;
    ticket.insert(-1);
    rep(i, 0, n){
        cin >> h;
        ticket.insert(h);
    }
    rep(i, 0, m){
        cin >> t;
        auto tmp = --ticket.upper_bound(t);
        cout << *tmp << '\n';
        if(*tmp != -1){
            ticket.erase(tmp);
        }
    }
    return 0;
}