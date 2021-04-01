#include<bits/stdc++.h>
using namespace std;

int N;
int t;
int sum;
int cnt;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> t;
        if(i & 1){
            sum += t - cnt;
        }else{
            cnt = t;
        }
    }
    if(N & 1){
        cout << "still running\n";
    }else{
        cout << sum << '\n';
    }
    return 0;
}