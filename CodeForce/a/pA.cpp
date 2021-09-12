#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for(int i = a; i < b; i++)

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    string n;
    int k;

    cin >> n >> k;
    int a = 0, b = k , c;
    k = (n.size() - k);
    string ans;
    while(k){
        // cout << a << ' ' << b << endl;
        int Max = 0, Maxpos;
        for(int i = a; i <= b; i++){
            if(n[i] > Max){
                Max = n[i];
                Maxpos = i;
            }
        }
        // cout << Maxpos << endl;
        a = Maxpos + 1;
        b++;
        ans += char(Max);
        k--;
    }
    cout << ans << '\n';
    return 0;
}