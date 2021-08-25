#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for(int i = a; i < b; i++)

const int MAX_N = 1e5 + 5;
const int INF = 0x3fffffff;
int n, arr[MAX_N];
int getnum(int x){
    int num;
    if(arr[x]){
        return arr[x];
    }else{
        cout << "? " << x << endl;
        cin >> num;
    }
    return arr[x] = num;
}
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> n;
    arr[0] = arr[n + 1] = INF;
    int l = 1, r = n + 1, mid;
    while(l < r){
        mid = (l + r) / 2;
        if(getnum(mid) > getnum(mid + 1)){
            l = mid + 1;
        }else{
            r = mid;
        }
    }
    cout << "! " << l << endl;
    return 0;
}