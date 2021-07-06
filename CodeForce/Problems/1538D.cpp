#include<bits/stdc++.h>
using namespace std;

const int MAX_N = 40000;

bool isntPrime[MAX_N];
vector<int> Prime;
int PrimeNumber(int x){
    int id = 0, cnt = 0;
    while(x != 1 && id < Prime.size()){
        while( !(x % Prime[id]) ){
            x /= Prime[id];
            cnt++;
        }
        id++;
    }
    return cnt + (x != 1);
}
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    int t;
    int a, b, k;
    for(int i = 2; i < MAX_N; i++){
        if(!isntPrime[i]){
            for(int j = i * i; j < MAX_N; j += i){
                isntPrime[j] = true;
            }
            Prime.push_back(i);
        }
    }

    cin >> t;
    int Max, Min;
    while(t-- && cin >> a >> b >> k){
        Max = PrimeNumber(a) + PrimeNumber(b);
        Min = ( a != b && (a % b == 0 || b % a == 0) ) ? 1 : 2;
        if(Min <= k && k <= Max){
            cout << "YES\n";
        }else{
            cout << "NO\n";
        }
    }
    
    return 0;
}