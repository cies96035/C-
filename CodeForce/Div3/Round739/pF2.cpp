#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for(int i = a; i < b; i++)

string n;
int t, k;

// use digit set, find a smallest num bigger than n
string tryans(int digset){ 
    int lgdig = 0; // largest digit
    for(int j = 9; j >= 0; j--){
        if(digset & (1 << j)){
            lgdig = j;
            break;
        }
    }

    string num(n.size(), '0' + lgdig);
    rep(i, 0, n.size()){
        rep(j, 0, 10){ //find smallest ans good digit for num[i]
            if(digset & 1 << j){
                num[i] = '0' + j;
                if(num >= n){
                    break;
                }
            }
        }
    }
    return num;
}

//find a smallest num use k-diff digit and bigger than n
string GetAns(){
    string ans(n.size(), '9');
    int digitset = 0;
    rep(i, 0, n.size()){
        // if we can add n[i] into set or n[i] is in the set
        if(__builtin_popcount(digitset | (1 << (n[i] - '0'))) < k ){
            digitset |= 1 << (n[i] - '0');
        }else{
            break;
        }
    }
    for(int i = 0; i < 10; i++){
        string tmp = tryans(digitset | (1 << i));
        if(tmp >= n && ans > tmp){
            ans = tmp;
        }
    }
    return ans;
}
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> t;
    while(t--){
        cin >> n >> k;
        cout << GetAns() << '\n';
    }
    return 0;
}