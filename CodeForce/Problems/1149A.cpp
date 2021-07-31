#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for(int i = a; i < b; i++)

const int MAX_N = 200005;
int n, ipt;
int two, one;
int arr[MAX_N];
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> n;
    rep(i, 0, n){
        cin >> ipt;
        ipt == 1 ? one++ : two++;
    }
    if(one && two){
        arr[0] = 2;
        two--;
        arr[1] = 1;
        rep(i, 2, n){
            if(two){
                arr[i] = 2;
                two--;
            }else{
                arr[i] = 1;
            }
        }
    }else{
        rep(i, 0, n){
            arr[i] = (one ? 1 : 2);
        }
    }
    rep(i, 0, n - 1){
        cout << arr[i] << ' ';
    }
    cout << arr[n - 1] << '\n';
    return 0;
}