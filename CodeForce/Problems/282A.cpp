#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for(int i = a; i < b; i++)

int n, cnt;
char c;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cin >> n;
    while(cin >> c){
        if(c == '+'){
            cnt++;
        }else if(c == '-'){
            cnt--;
        }
    }
    cout << cnt / 2 << '\n';
    return 0;
}