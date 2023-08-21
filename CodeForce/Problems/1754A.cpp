#include <bits/stdc++.h>
using namespace std;
int t, n;
string str;
bool f(){
    int cnt = 0;
    for(auto c : str){
        if(c == 'Q'){
            cnt++;
        }else{
            if(cnt > 0){
                cnt--;
            }
        }
    }
    return cnt == 0;
}
int main(){

    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cin >> t;
    while(t--){
        cin >> n;
        cin >> str;
        if(f()){
            cout << "Yes\n";
        }else{
            cout << "No\n";
        }
    }
    return 0;
}