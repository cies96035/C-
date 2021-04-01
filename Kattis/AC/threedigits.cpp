#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const ll M = 1000;
ll n;
ll nf = 1;
ll tmp;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> n;
    for(int i = 1; i <= n; i++){
        tmp = i;
        while(!(tmp % 10)){
            tmp /= 10;
        }
        nf *= (tmp % 1000);
        while(!(nf % 10)){
            nf /= 10;
        }
        if(nf > M){
            nf %= M;
        }
    }
    if(nf < 1000){
        cout << nf << '\n';
    }else{
        cout << setw(3) << setfill('0') << nf % 1000 << '\n';
    }
    return 0;
}