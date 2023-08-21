#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
using ppll = pair<ll,pair<ll, ll>>;
using ld = long double;
#define rep(i, a, b) for(int i = a; i < b; i++)
ifstream fin("bouns.in");
ofstream fout("bouns.out");
const int MAX_N = 1e5 + 5;
int n, arr[MAX_N];

// ... 1 2 3 3
/*
010 110 001 000 111 110 100
1.
: 010
010 -> 010:1
2.
: 010 
010 -> 010:1, 100:1
3.
: 000
000 -> 011:1, 101:1, 001:1
4.
: 000
000 -> 011:1, 101:1, 001:1, 000:1
5.
: 000 111
000 -> 110:1, 010:1, 110:1, 111:1
111 -> 111:1

*/

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    #define  cin fin
    #define  cout fout

    cin >> n;

    rep(i, 0, n) cin >> arr[i];
    return 0;
}

/*
a : 10 + 1
b : 10

a -> 2
b -> 1

30
32

a : 9 + 1
b : 10

a -> 4
b -> 2


a : 10 + 1
b : 9

a -> 4
b -> 2

*/