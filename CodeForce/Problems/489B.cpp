#include<bits/stdc++.h>
using namespace std;
#define rep(a, b, c) for(int a = b; a < c; a++)
const int MAX_NM = 100;
int n, m;
int A[MAX_NM], B[MAX_NM];
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> n;
    rep(i, 0, n){
        cin >> A[i];
    }
    cin >> m;
    rep(i, 0, m){
        cin >> B[i];
    }
    sort(A, A + n);
    sort(B, B + m);
    int i = 0, j = 0, cnt = 0;
    while(i < n && j < m){
        if(abs(A[i] - B[j]) <= 1){
            i++;
            j++;
            cnt++;
        }else if(A[i] > B[j]){
            j++;
        }else{
            i++;
        }
    }
    cout << cnt << '\n';
    return 0;
}