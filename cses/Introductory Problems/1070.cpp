#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for(int i = a; i < b; i++)

int n;
bool flg;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> n;
    if(n == 2 || n == 3){
        cout << "NO SOLUTION\n";
    }else{
        for(int i = n - !(n & 1); i > 0; i -= 2){
            if(flg){
                cout << ' ';
            }else{
                flg = true;
            }
            cout << i;
        }
        for(int i = n - (n & 1); i > 0; i -= 2){
            cout << ' ' << i; 
        }
        cout << '\n';
    }
    return 0;
}