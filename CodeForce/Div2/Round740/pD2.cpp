#include <algorithm>
#include <iostream>
#include <map>
#include <numeric>
#include <utility>
#include <vector>

using namespace std;

// clang-format off
struct M {
    static int MOD;
    int v;
    M(int x = 0) {
        if (x < -MOD || x >= MOD) x %= MOD;
        v = (x >= 0) ? x : x + MOD;
    }
    explicit operator int() const { return v; }
    bool operator==(const M& b) const { return v == b.v; }
    bool operator!=(const M& b) const { return v != b.v; }
    M operator-() const { return M(-v); }
    M operator+=(const M& b) { if ((v += b.v) >= MOD) v -= MOD; return *this; }
    M operator-=(const M& b) { if ((v -= b.v) < 0) v += MOD; return *this; }
    M operator*=(const M& b) { v = (long long)v * b.v % MOD; return *this; }
    M operator/=(const M& b) { return *this *= b ^ (MOD - 2); }
    friend M operator^(M a, int b) {
        M ret = 1;
        for (; b; a *= a, b >>= 1) if (b & 1) ret *= a;
        return ret;
    }
    friend M operator+(M a, const M& b) { return a += b; }
    friend M operator-(M a, const M& b) { return a -= b; }
    friend M operator*(M a, const M& b) { return a *= b; }
    friend M operator/(M a, const M& b) { return a /= b; }
    friend istream& operator>>(istream& i, M& m) { return i >> m.v; }
    friend ostream& operator<<(ostream& o, M m) { return o << m.v; }
};
using Mod = M;
int Mod::MOD = 69;
// clang-format on

void solve() {
    int n;
    cin >> n >> Mod::MOD;

    vector<Mod> dp(n + 1), cur(n + 1);
    dp[1] = 1;

    Mod pre = 0;
    for (int i = 1; i <= n; i++) {
        cur[i] += cur[i - 1];
        dp[i] += cur[i] + pre;
        for (int j = 2 * i; j <= n; j += i) {
            cur[j] += dp[i] - dp[i - 1];
        }
        cout << cur[i] << endl;
        pre += dp[i];
    }

    cout << dp[n] << '\n';
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int owo = 1;
    // cin >> owo;
    while (owo--)
        solve();
}
