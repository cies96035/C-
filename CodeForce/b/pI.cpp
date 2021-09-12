#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for(ll i = a; i < b; i++)
#define rrep(i, a, b) for(ll i = a; i <= b; i++)

const int LEN = 42;

void intToVec(ll n, vector<int> &vi){
    int vid = 0;
    while(n){
        if(n & 1){
            vi[vid++] = 1;
        }else{
            vi[vid++] = 0;
        }
        n >>= 1;
    }
    while(vid < LEN){
        vi[vid++] = 0;
    }
}
void getset(ll n, vector<vector<int>> &s){
    int j = 0;
    vector<int> tmp(LEN);
    intToVec(n, tmp);

    if(n & 1){
        for(; tmp[j]; j++){
            tmp[j] = 2;
        }
    }
    s.emplace_back(tmp);

    rep(i, j, LEN){
        if(tmp[i]){
            tmp[i] = 0;
            s.push_back(tmp);
        }
        tmp[i] = 2;
    }
}
ll caltwoset(vector<int> a, vector<int> b){
    vector<int> psb_num(LEN); //possible number
    ll ans = 0;
    rep(i, 0, LEN){
        if(a[i] != 2 && b[i] != 2){
            psb_num[i] = a[i] ^ b[i];
        }else if(a[i] != 2 ^ b[i] != 2){
            psb_num[i] = 2;
        }else{
            psb_num[i] = 3;
        }
    }

    ll cnt, mid;
    int tmp1, tmp2;
    rrep(len, 1, LEN){
        cnt = 1; mid = len >> 1;

        if(psb_num[0] == 0 || psb_num[len - 1] == 0){
            cnt = 0;
        }
        if(psb_num[0] == 3){
            cnt <<= 1;
        }
        if(len != 1 && psb_num[len - 1] == 3){
            cnt <<= 1;
        }
        rrep(i, len, LEN){
            if(psb_num[i] == 1){
                cnt = 0;
                break;
            }else if(psb_num[i] == 3){
                cnt <<= 1;
            }
        }

        if(cnt){
            rep(i, 1, mid){
                tmp1 = psb_num[i], tmp2 = psb_num[len - i - 1];
                if(tmp1 + tmp2 == 1){
                    cnt = 0;
                    break;
                }
                cnt <<= (tmp1 >= 2 && tmp2 >= 2) + (tmp1 == 3) + (tmp2 == 3);
            }
            if(len != 1 && len & 1){
                if(psb_num[mid] == 3){
                    cnt <<= 2;
                }else if(psb_num[mid] == 2){
                    cnt <<= 1;
                }
            }
        }
        ans += cnt;
    }
    return ans;
}
ll calans(ll x, ll y){// return [0, x] X [0, y]
    if(x < 0 || y < 0){
        return 0;
    }
    ll ans = 0;

    vector<vector<int>> xs, ys;
    getset(x, xs);
    getset(y, ys);

    for(auto i : xs){
        for(auto j : ys){
            ans += caltwoset(i, j);
        }
    }

    return ans + min(x, y) + 1;
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int T;
    ll L, R;
    cin >> T;
    while(T--){
        cin >> L >> R;
        L--;
        cout << calans(R, R) - calans(L, R) - calans(L, R) + calans(L, L) << '\n';
    }
    return 0;
}