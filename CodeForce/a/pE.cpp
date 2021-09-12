#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for(int i = a; i < b; i++)

int **M;
int t = 1;
int n, a, b, aed, bed;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    M = new int*[20005] + 10001;
    rep(i, -10001, 10002){
        M[i] = new int[20005]{0} + 10001;
    }
    cin >> n;
    // clock_t ttt = clock();
    cin >> aed >> bed;
    aed = -10000, bed = -10000;
    int ans = 0x3ffffff;
    int sum = 0;
    rep(i, 1, n){
        // if(i % 4 == 1){
        //     a = -10000, b = 10000;
        // }else if(i % 4 == 2){
        //     a = 10000, b = 10000;
        // }else if(i % 4 == 3){
        //     a = 10000, b = -10000;
        // }else{
        //     a = -10000, b = -10000;
        // }
        cin >> a >> b;
        if(a == aed){
            if(bed > b){
                sum += bed - b;
                for(int j = bed; j > b; j--){
                    // cout << 'a' << a << ' ' << j << '\n';
                    t++;
                    if(M[a][j] != 0){
                        ans = min(ans, t - M[a][j]);
                    }
                    M[a][j] = t;
                }
            }else{
                sum += b - bed;
                for(int j = bed; j < b; j++){
                    // cout << 'b' << a << ' ' << j << '\n';
                    t++;
                    if(M[a][j] != 0){
                        ans = min(ans, t - M[a][j]);
                    }
                    M[a][j] = t;
                }
            }
        }else{
            if(aed > a){
                sum += aed - a;
                for(int j = aed; j > a; j--){
                    // cout << 'c' << j << ' ' << b << '\n';
                    t++;
                    if(M[j][b] != 0){
                        ans = min(ans, t - M[j][b]);
                    }
                    M[j][b] = t;
                }
            }else{
                sum += a - aed;
                for(int j = aed; j < a; j++){
                    // cout << 'd' << j << ' ' << b << '\n';
                    t++;
                    if(M[j][b] != 0){
                        ans = min(ans, t - M[j][b]);
                    }
                    M[j][b] = t;
                }
            }
        }
        aed = a, bed = b;
    }
    cout << min(ans, sum) << '\n';
    cout << clock() - ttt << endl;
    return 0;
}