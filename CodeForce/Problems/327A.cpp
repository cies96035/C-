#include<bits/stdc++.h>
using namespace std;

int n;
int cnt, Max, sum;
int ipt;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> n;
    while(n--){
        cin >> ipt;
        if(ipt){
            sum++;
            cnt--;
        }else{
            cnt++;
        }
        if(cnt < 0){
            cnt = 0;
        }
        if(Max < cnt){
            Max = cnt;
        }
    }
    if(Max == 0){
        Max--;
    }
    cout << Max + sum << '\n';
    return 0;
}