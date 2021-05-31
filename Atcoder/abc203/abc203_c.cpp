#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAX_N = 200200;
int N, K;
ll pos, mny;
int a, b;
struct Friend{
    ll A;
    ll B;
    bool operator< (const Friend x)const{
        return A < x.A;
    }
}f[MAX_N];
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> N >> K;
    for(int i = 0; i < N; i++){
        cin >> f[i].A >> f[i].B;
    }
    sort(f, f + N);
    
    int id = 0;
    mny = K;
    pos = 0;
    while(id < N){
        pos += mny;
        mny = 0;
        if(pos >= f[id].A){
            mny += f[id].B;
        }
        id++;
    }
    cout << pos + mny << '\n';
    return 0;
}