#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
using ppll = pair<ll,pair<ll, ll>>;
using ld = long double;
#define rep(i, a, b) for(ll i = a; i < b; i++)
#define rrep(i, a, b) for(ll i = a; i <= b; i++)
ifstream fin("bonus.in");
ofstream fout("bonus.out");
ll n, a, b;
ll cnt;
bool mode;
map<ppll, ld> DP[2];
ld f2(ll aa, ll bb){
    rrep(i, 0, n){
        DP[mode][{0, {aa - n + i, bb - i}}] = 1;
    }
    /*
    aa + bb - (n - i)
    aa - i ~ a
    aa - n + i + j
    */
    rrep(i, 1, n){
        rrep(j, 1, n){
            ld ans, c1 = 0, c2 = 0;
            ld round = (n - i + 1);
            ld sum = aa * 2 * round + bb * round;
            // DP[mode][i]
            if(mode){
                if(aa >= 1)
                    c1 = DP[mode][{i - 1, {aa - n + i + j - 1, bb - j}}] * (1 - (bb - 1) * round / (sum - round));
                if(bb >= 2)
                    c2 = DP[mode][{i - 1, {aa - n + i + j, bb - j - 1}}] * ((bb - 1) * round / (sum - round));
                ans = (sum - round) / sum * (c1 + c2);
            }
            else{
                if(aa >= 2)
                    c1 = DP[mode][{i - 1, {aa - n + i + j - 1, bb - j}}] * ((aa - 1) * 2 * round / (sum - 2 * round));
                if(bb >= 1)
                    c2 = DP[mode][{i - 1, {aa - n + i + j, bb - j - 1}}] * 2 * round / (sum - 2 * round);
                ans = (sum - 2 * round) / sum * (c1 + c2);
            }
            
        }
    }
}
ld f(ll nn, ll aa, ll bb){
    if(nn <= 0 || aa < 0 || bb < 0) return 1;
    if(DP[mode].count({nn, {aa, bb}})) return DP[mode][{nn, {aa, bb}}];
    ld round = (n - nn + 1);
    ld sum = aa * 2 * round + bb * round;
    ld ans, c1 = 0, c2 = 0;
    if(mode){
        if(aa >= 1)
            c1 = f(nn - 1, aa - 1, bb) * (1 - (bb - 1) * round / (sum - round));
        if(bb >= 2)
            c2 = f(nn - 1, aa, bb - 1) * ((bb - 1) * round / (sum - round));
        ans = (sum - round) / sum * (c1 + c2);
    }
    else{
        if(aa >= 2)
            c1 = f(nn - 1, aa - 1, bb) * ((aa - 1) * 2 * round / (sum - 2 * round));
        if(bb >= 1)
            c2 = f(nn - 1, aa, bb - 1) * (1 - ((aa - 1) * 2 * round / (sum - 2 * round)));
        ans = (sum - 2 * round) / sum * (c1 + c2);
    }
    cout << nn << ' ' << aa << ' ' << bb << endl;
    return DP[mode][{nn, {aa, bb}}] = ans;
}
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);


    fin >> n >> a >> b;
    fout << fixed << setprecision(16);
    if(n > a + b){
        fout << "1\n1\n";
    }else{
        fout << 1 - f(n, a + 1, b) << '\n';
        mode = 1;
        fout << 1 - f(n, a, b + 1) << '\n';

    }
    return 0;
}