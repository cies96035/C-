#include<bits/stdc++.h>
using namespace std;
using ull = unsigned long long;

const int MAX_N = 200;
const ull LARGE = 1e18 + 10;
ull N, K;
ull fib[MAX_N], fibId;
void Foo(){
    fib[0] = 0;
    fib[1] = 1;
    for(fibId = 2; fib[fibId - 1] < LARGE; fibId++){
        fib[fibId] = fib[fibId - 1] + fib[fibId - 2];
    }
}
bool RE(ull k){
    int p = lower_bound(fib, fib + fibId, k) - 1 - fib;
    if(k - fib[p] <= 1){
        return p % 2;
    }else{
        return RE(k - fib[p]);
    }
}
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    Foo();
    cin >> N >> K;
    if(K == 1){
        if(N % 2){
            cout << "N\n";
        }else{
            cout << "A\n";
        }
    }else if(K == 2){
        if(N % 2){
            cout << "A\n";
        }else{
            cout << "N\n";
        }
    }else{
        if(RE(K - 1)){
            cout << 'N' << '\n';
        }else{
            cout << 'A' << '\n';
        }
    }
    return 0;
}