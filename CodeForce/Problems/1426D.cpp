#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for(int i = a; i < b; i++)

//const int MAX_N = 1e9 + 1;

map<ll, bool> exist;
int n, a;
stack<ll> s;
ll sum;
int cnt;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> n;
    s.push(0);
    exist[0] = true;
    while(n--){    
        cin >> a;
        sum += a;
        if(exist[sum]){
            cnt++;
            //cout << a << ' ' << sum << endl;
            while(!s.empty()){
                exist[s.top()] = false;
                s.pop();
            }
            s.push(0);
            exist[0] = true;
            sum = a;
        }
        exist[sum] = true;
        s.push(sum);
    }
    cout << cnt << '\n';
    return 0;
}