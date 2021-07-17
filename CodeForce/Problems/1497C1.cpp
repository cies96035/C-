#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for(int i = a; i < b; i++)

int t;
int n, k;
void findAns(int num, int &a, int &b, int &c){
    if(num & 1){
        a = 1;
        b = c = num / 2;
        return;
    }else if(num == 4){
        a = b = 1;
        c = 2;
        return;
    }
    findAns(num / 2, a, b, c);
    a *= 2;
    b *= 2;
    c *= 2;
    return;
}
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    int a, b, c;
    cin >> t;
    while(t--){
        cin >> n >> k;
        findAns(n, a, b, c);
        cout << a << ' ' << b << ' ' << c << '\n';
    }
    return 0;
}