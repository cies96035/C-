#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for(int i = a; i < b; i++)

int t;
int k, n, m;
int a[150];
int b[150];
int ans[310];
bool check(){
    int i = 0;
    int j = 0;
    while(i < n && j < m){
        if(a[i] < b[j]){
            if(a[i] == 0){
                k++;
            }else if(a[i] > k){
                return false;
            }
            ans[i + j] = a[i];
            i++;
        }else{
            if(b[j] == 0){
                k++;
            }else if(b[j] > k){
                return false;
            }
            ans[i + j] = b[j];
            j++;
        }
    }
    while(i < n){
        if(a[i] == 0){
            k++;
        }else if(a[i] > k){
            return false;
        }
        ans[i + j] = a[i];
        i++;
    }
    while(j < m){
        if(b[j] == 0){
            k++;
        }else if(b[j] > k){
            return false;
        }
        ans[i + j] = b[j];
        //cout << i << ' ' << j  << ans[i + j] << endl;
        j++;
    }
    return true;
}
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> t;
    while(t--){
        cin >> k >> n >> m;
        rep(i, 0, n){
            cin >> a[i];
        }
        rep(i, 0, m){
            cin >> b[i];
        }
        if(check()){
            n += m - 1;
            rep(i, 0, n){
                cout << ans[i] << ' ';
            }
            cout << ans[n] << '\n';
        }else{
            cout << -1 << '\n';
        }
    }
    return 0;
}