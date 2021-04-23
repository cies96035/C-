#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAX_N = 300300;

int n, m;
int a[MAX_N], s[MAX_N];
int t = 0;
int cnt;
int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> a[i] >> s[i];
        s[i] += a[i];
    }
    sort(a, a + n);
    sort(s, s + n);
    t = 0;
    for(int i = 0; i < n; i++){
        if(a[i] < s[t]){
            cnt++;
        }else if(a[i] >= s[t]){
            while(t < n && a[i] > s[t] + m){
                t++;
            }
            if(t < n && s[t] <= a[i] && a[i] <= s[t] + m){
                t++;
            }else{
                cnt++;
            }
        }
    }
    cout << n - cnt << '\n';
}