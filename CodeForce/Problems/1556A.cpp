#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for(int i = a; i < b; i++)

int t, c, d;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> t;
    while(t--){
        cin >> c >> d;
        if(c == d){
            if(c){
                cout << "1\n";
            }else{
                cout << "0\n";
            }
        }else if((c - d) & 1){
            cout << "-1\n";
        }else{
            cout << "2\n";
        }
    }
    return 0;
}