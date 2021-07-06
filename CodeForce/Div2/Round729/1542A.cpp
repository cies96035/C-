#include<bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    int t;
    int n;
    int oddCnt;
    int ipt;
    cin >> t;
    while(t--){
        cin >> n;
        oddCnt = n;
        n *= 2;
        while(n--){
            cin >> ipt;
            if(ipt & 1){
                oddCnt--;
            }
        }
        if(oddCnt == 0){
            cout << "Yes\n";
        }else{
            cout << "No\n";
        }
    }
    return 0;
}