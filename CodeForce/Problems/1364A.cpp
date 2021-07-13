#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for(int i = a; i < b; i++)

const int MAX_X = 10100;
int t;
int n, x;
int ipt;
int id;
int sum;
int Max;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> t;
    while(t--){
        cin >> n >> x;
        Max = sum = 0;
        id = -1;
        for(int i = 0; i < n; i++){
            cin >> ipt;
            sum += ipt;
            sum %= x;
            if(sum == 0){
                Max = max(Max, i - id);
            }else{
                Max = i + 1;
                if(id == -1)
                id = i;
            }
        }
        if(id == -1){
            cout << "-1\n";
        }else{
            cout << Max << '\n';
        }
    }
    return 0;
}