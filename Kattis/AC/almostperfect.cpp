#include<iostream>
using namespace std;
using ll = long long;


const int MAX_N = 44800;
int N;
int tmp;

int checkPerfect(int n){
    ll sum = 0;
    int k = n;
    for(ll i = 1; i * i <= n; i++){
        if(n % i == 0){
            sum += i;
            if(n / i != i && i != 1){
                sum += n / i;
            }
        }
    }
    if(std::abs(sum - n) == 0){
        return 1;
    }else if(std::abs(sum - n) <= 2){
        return 2;
    }else{
        return 0;
    }
}
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    while(cin >> N){
        tmp = checkPerfect(N);
        if(tmp == 1){
            cout << N << " perfect\n";
        }else if(tmp == 0){
            cout << N << " not perfect\n";
        }else{
            cout << N << " almost perfect\n";
        }
    }
    return 0;
}