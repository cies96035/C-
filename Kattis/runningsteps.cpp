#include<iostream>
using namespace std;
using ll = long long;

ll countStep(int twoAmount, int oneAmount){
    ll cnt = 1;
    for(int i = 1; i <= oneAmount; i++){
        cnt *= twoAmount + i;
        cnt /= i;
    }
    return cnt;
}

ll T, Case, num, twoCnt, oneCnt, Cnt;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> T;
    while(T--){
        Cnt = 0;
        cin >> Case >> num;
        num /= 2;
        twoCnt = num / 2;
        oneCnt = num % 2;
        while(twoCnt >= oneCnt){
            Cnt += countStep(twoCnt, oneCnt) * countStep(twoCnt, oneCnt);
            twoCnt--;
            oneCnt+=2;
        }
        cout << Case << ' ' << Cnt << '\n';
    }
    return 0;
}