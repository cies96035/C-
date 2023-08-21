#include<bits/stdc++.h>
using namespace std;
#define f0r(i, n) for(int i = 0; i < n; i++)

const int MAX_N = 55;
int t, n;
int arr[MAX_N];
string str;
bool check(){
    map<int, char> dict;
    f0r(i, n){
        if(dict.count(arr[i]) && str[i] != dict[arr[i]]){
            return false;
        }else{
            dict[arr[i]] = str[i];
        }
    }
    return true;
}
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cin >> t;
    while(t--){
        cin >> n;
        f0r(i, n){
            cin >> arr[i];
        }
        cin >> str;
        if(check()){
            cout << "YES\n";
        }else{
            cout << "NO\n";
        }
    }
}