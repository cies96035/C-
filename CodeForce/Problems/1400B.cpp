#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for(int i = a; i < b; i++)

int t;
int p, f, cs, cw, s, w; 
int test(int x){ // p take x sword
    int ans = 0;
    int lp = p, lf = f, lcs = cs, lcw = cw, tmp;
    lp -= x * s, lcs -= x, ans += x; //p take x sword

    tmp = min(lcw, lp / w); 
    lp -= tmp * w, lcw -= tmp, ans += tmp; //p take tmp waraxe

    tmp = min(lcs, lf / s);
    lf -= tmp * s, ans += tmp; //f take sword

    ans += min(lcw, lf / w); // f take waraxe
    return ans;
}
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> t;
    while(t--){
        cin >> p >> f >> cs >> cw >> s >> w;

        if(s > w){ // make s < w
            swap(s, w);
            swap(cs, cw);
        }

        int Max = 0;
        for(int i = 0, e = min(cs, p / s); i <= e ; i++){
            Max = max(Max, test(i));
        }
        cout << Max << '\n';
    }
    return 0;
}