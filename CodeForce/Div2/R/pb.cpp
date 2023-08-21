#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for(int i = a; i < b; i++)

const int MAX_N = 55;
int t, n;
string arr;
int M[MAX_N][MAX_N];
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cin >> t;
    while(t--){
        cin >> n;
        rep(i, 0, n){
            rep(j, 0, n){
                M[i][j] = 0;
            }
        }
        cin >> arr;
        rep(i, 0, n){
            if(arr[i] == '1'){
                rep(j, 0, n){
                    M[i][j] = 1;
                    M[j][i] = 1;
                }
            }
        }

        bool flg2 = true;
        bool flg;
        rep(i, 0, n){
            if(arr[i] == '2'){
                flg = false;
                rep(j, 0, n){
                    if(i == j){
                        continue;
                    }
                    if(M[i][j] == 0){
                        M[i][j] = 2;
                        M[j][i] = 3;
                        flg = true;
                        break;
                    }
                }
                if(!flg){
                    flg2 = false;
                }
            }
        }
        if(flg2){
            cout << "YES\n";
            rep(i, 0, n){
                rep(j, 0, n){
                    if(i == j){
                        cout << 'X';
                    }else if(M[i][j] == 1 || M[i][j] == 0){
                        cout << '=';
                    }else if(M[i][j] == 2){
                        cout << '+';
                    }else{
                        cout << '-';
                    }
                }
                cout << endl;
            }
        }else{
            cout << "NO\n";
        }
    }
    return 0;
}