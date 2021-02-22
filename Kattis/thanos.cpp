#include<iostream>
using namespace std;
using ll = long long;

int T;
ll P, R, F, cnt;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> T;
    while(T--){
        cnt = 0;
        cin >> P >> R >> F;
        while(P <= F){
            P *= R;
            cnt++;
        }
        cout << cnt << '\n';
    }
    return 0;
}