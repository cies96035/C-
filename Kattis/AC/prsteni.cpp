#include<iostream>
using namespace std;
using ull = unsigned long long;

ull N;
ull prsteni, ipt;
ull gcd(ull a, ull b){
    while((a %= b) && (b %= a));
    return a + b;
}
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> N >> prsteni;
    while(--N){
        cin >> ipt;
        cout << prsteni / gcd(prsteni, ipt) << '/' << ipt / gcd(prsteni, ipt) << '\n';
    }
    return 0;
}