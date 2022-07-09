#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pll = pair<ll, ll>;
#define rep(i, a, b) for(int i = a; i < b; i++)
#define rrep(i, a, b) for(int i = a; i <= b; i++)
#define rvep(i, a, b) for(int i = a; i >= b; i--)

int n, alpha[3];
string str;
map<int, char> itoch;
map<char, int> chtoi;

bool solve1(){
    int lost = -1;
    rep(i, 0, 3){
        if(alpha[i] < n){
            if(lost == -1) lost = i;
            else return false;
        }
    }
    int l = 0, r = 1; // [l, r)
    bool aflg, bflg;
    alpha[ chtoi[str[l]] ]--;
    while(r < str.size()){
        aflg = bflg = false;
        rep(i, 0, 3){
            if(i != lost){
                if(alpha[i] > n){// too more
                    bflg = true;
                    break;
                }else if(alpha[i] < n){// too less
                    aflg = true;
                    break;
                }
            }
        }

        if(aflg){// add alpha
            alpha[ chtoi[str[l++]] ]++;
        }else if(bflg){// reduce alpha
            alpha[ chtoi[str[r++]] ]--;
        }else{
            break;
        }
    }
    rep(i, 0, 3){
        if(i != lost && alpha[i] != n){
            return false;
        }
    }
    //output ans
    cout << 1 << '\n';
    cout << l + 1 << ' ' << r << ' ' << itoch[lost] << '\n';
    return true;

}
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    itoch[0] = 'A', itoch[1] = 'B', itoch[2] = 'C';
    chtoi['A'] = 0, chtoi['B'] = 1, chtoi['C'] = 2;

    cin >> n;
    cin >> str;
    for(auto c : str){
        alpha[ chtoi[c] ]++;
    }
    if(alpha[0] == alpha[1] && alpha[1] == alpha[2]) cout << "0\n";
    else if(!solve1()){
        int cnt[3] = {0};
        rep(i, 0, n * 3){
            cnt[ chtoi[str[i]] ]++;
            if(cnt[ chtoi[str[i]] ] == n){
                int x = (chtoi[ str[i] ] + 1) % 3, y = (chtoi[ str[i] ] + 2) % 3;

                cout << 2 << '\n';
                cout << i + 2 << ' ' << 3 * n << ' ' << itoch[x] << '\n';
                cout << 2 * n + cnt[y] + 1 << ' ' << 3 * n << ' ' << itoch[y] << '\n';
                break;
            }
        }
    }

    return 0;
}