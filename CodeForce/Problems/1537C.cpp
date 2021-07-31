#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for(int i = a; i < b; i++)

const int MAX_N = 200005;
int t;
int n;
int h[MAX_N];
bool flg;
int MinId;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> t;
    while(t--){
        cin >> n;
        rep(i, 0, n){
            cin >> h[i];
        }

        MinId = 1;
        sort(h, h + n);
        rep(i, 1, n){
            if(h[i] - h[i - 1] < h[MinId] - h[MinId - 1]){
                MinId = i;
            }
        }
        if(n == 2){
            MinId--;
        }

        flg = false;
        rep(i, 0, n){
            if(flg){
                cout << ' ';
            }else{
                flg = true;
            }
            cout << h[ (MinId + i) % n];
        }
        cout << '\n';
    }
    
    return 0;
}