#include<iostream>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

ll P, K, N;
pll frac;

void getAns(){
    N >>= 1;
    if(N == 1){
        frac = pll(1, 1);
        return;
    }
    if(N & 1){
        getAns();
        frac.first += frac.second;
    }else{
        getAns();
        frac.second += frac.first;
    }
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    
    cin >> P;
    while(P--){
        cin >> K >> N;
        N <<= 1;
        getAns();
        cout << K << ' ' << frac.first << '/' << frac.second << '\n';
    }
    return 0;
}