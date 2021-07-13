#include<bits/stdc++.h>
using namespace std;

inline int Try(int a, int b, int cnt){
    if(b == 1){
        return 0x3fffffff;
    }
    while(a){
        a /= b;
        cnt++;
    }
    return cnt;
}
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    int t;
    int a, b;
    int Min, tmp;
    cin >> t;
    while(t--){
        Min = 0x3fffffff;
        cin >> a >> b;
        for(int i = 0; i < 10; i++){
            tmp = Try(a, b + i, i);
            if(tmp < Min){
                Min = tmp;
            }
        }
        cout << Min << '\n';
    }
    return 0;
}