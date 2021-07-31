#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for(int i = a; i < b; i++)

int cnt[256];
string str;
bool solve(){
    bool flg = str.size() & 1;
    int i = 0, j = str.size() - 1;
    for(int c = 'A'; c <= 'Z'; c++){
        if(cnt[c] & 1){
            if(flg){
                str[str.size() / 2] = c;
                flg = false;
                cnt[c]--;
            }else{
                return false;
            }
        }
        while(cnt[c]){
            str[i] = str[j] = c;
            i++, j--;
            cnt[c] -= 2;
        }
        
    }
    return true;
}
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> str;
    for(auto c : str) cnt[c]++;
    
    if(solve()){
        cout << str << '\n';
    }else{
        cout << "NO SOLUTION\n";
    }
    
    return 0;
}