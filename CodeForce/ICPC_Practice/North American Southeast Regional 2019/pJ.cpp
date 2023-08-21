#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
#define rep(i, a, b) for(int i = a; i < b; i++)
#define rrep(i, a, b) for(int i = a; i <= b; i++)
#define rvep(i, a, b) for(int i = a; i >= b; i--)

const int MAX_N = 2e5 + 5;
const int MAX_K = 2e5 + 5;
int n, k;

int cnt[MAX_K], cnt2;
int arr[MAX_N];
int best = -1;
void change(int n, int value){ // value != 0
    cnt[n] += value;
    if(cnt[n] == 1){
        cnt2++;
    }else if(cnt[n] == 0){
        cnt2--;
    }
}
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> n >> k;
    rep(i, 0 ,n){
        cin >> arr[i];
    }
    rep(i, 0, k){
        change(arr[i], 1);
    }
    if(cnt2 == k){
        best = 0;
    }
    rep(i, k, n){
        change(arr[i - k], -1);
        change(arr[i], 1);
        if(cnt2 == k){
            if(best == -1){
                best = i - k + 1;
            }else{
                rep(j, 0, k){
                    if(arr[best + j] != arr[i - k + 1 + j]){
                        if(arr[best + j] > arr[i - k + 1 + j]){
                            best = i - k + 1;
                        }
                        break;
                    }
                }
            }
        }
    }
    rep(i, 0, k){
        cout << arr[best + i] << ' ';
    }
    cout << endl;
    return 0;
}

/*
1234123412341234
*/