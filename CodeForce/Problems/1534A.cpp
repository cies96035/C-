#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for(int i = a; i < b; i++)

int t;
int n, m;
char c;
bool check[2];
char RW[2][55];
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> t;
    while(t--){
        check[0] = check[1] = true;
        for(int i = 0; i < m; i += 2){
            RW[0][i] = RW[1][i + 1] = 'R';
            RW[0][i + 1] = RW[1][i] = 'W';
        }
        cin >> n >> m;
        rep(i, 0, n){
            rep(j, 0, m){
                cin >> c;
                if(c != '.'){
                    if(RW[i & 1][j] != c){
                        check[0] = false;
                    }else if(RW[!(i & 1)][j] != c){
                        check[1] = false;
                    }

                }
            }
        }
        if(check[0] || check[1]){
            cout << "YES\n";
            RW[0][m] = RW[1][m] = '\0';
            rep(i, 0, n){
                cout << RW[ i & 1 ^ check[1] ] << '\n';
            }
        }else{
            cout <<"NO\n";
        }
    }
    return 0;
}