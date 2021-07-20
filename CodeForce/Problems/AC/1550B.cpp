#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for(int i = a; i < b; i++)

int t;
int n, a, b;
string str;
char c;
int cnt;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> t;
    while(t--){
        cin >> n >> a >> b >> str;
        a *= n;
        if(b >= 0){
            a += b * n;
        }else{
            cnt = 0;
            c = str[0];
            for(auto i : str){
                if(c != i){
                    c = i;
                    cnt++;
                }
            }
            a += b * ((cnt + 3) >> 1);
        }
        cout << a << '\n';
    }
    return 0;
}