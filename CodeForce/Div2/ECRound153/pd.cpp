#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pll = pair<ll, ll>;
#define rep(i, a, b) for(int i = a; i < b; i++)
#define rrep(i, a, b) for(int i = a; i <= b; i++)
#define rvep(i, a, b) for(int i = a; i >= b; i--)

/*
0__1 -> 1__0 :
  01 -> -b - (a + 1) = - len - 1
  10 -> +a + (b + 1) = len + 1
  
1__0 -> 0__1 :
  01 -> +b + (a + 1) = len + 1
  10 -> -a - (b + 1) = - len - 1


0__1 -> 1__0 : -len-1
1__0 -> 0__1 : len+1
*/
void f(){
}
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int t = 1;
    cin >> t;
    while(t--) f();
    
    return 0;
}