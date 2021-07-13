#include<bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    int t;
    int n, ipt, sum;
    cin >> t;
    while(t--){
        sum = 0;
        cin >> n;
        for(int i = 0; i < n; i++){
            cin >> ipt;
            sum += ipt;
        }
        if(sum < n){
            cout << 1 << '\n';
        }else{
            cout << sum - n << '\n';
        }
    }
    return 0;
}