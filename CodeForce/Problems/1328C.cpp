#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for(int i = a; i < b; i++)

int t;
int n;
bool flg;
string x;
string a, b;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> t;
    while(t--){
        cin >> n >> x;
        a = b = x;
        flg = false;
        rep(i, 0, n){
            if(x[i] == '2'){
                if(flg){
                    a[i] = '0';
                    b[i] = '2';
                }else{
                    a[i] = b[i] = '1';
                }
            }else if(x[i] == '1'){
                if(flg){
                    a[i] = '0';
                    b[i] = '1';
                }else{
                    a[i] = '1';
                    b[i] = '0';
                    flg = true;
                }
            }else{
                a[i] = b[i] = '0';
            }
        }
        cout << a << '\n' << b << '\n';
    }
    return 0;
}