#include<bits/stdc++.h>
using namespace std;

string a, b;
int cnt;
int CountCarry(){
    cnt = 0;
    if(a.size() < b.size()){
        swap(a, b);
    }
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    for(int i = 0; i < a.size(); i++){
        if(i < b.size()){
            a[i] += b[i] - '0';
        }
        if(a[i] > '9'){
            a[i] -= 10;
            a[i + 1]++;
            cnt++;
        }
    }
    return cnt;
}
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    while(cin >> a >> b && (a != "0" || b != "0") ){
        CountCarry();
        if(cnt == 1){
            cout << "1 carry operation.\n";
        }else if(cnt > 1){
            cout << cnt << " carry operations.\n";
        }else{
            cout << "No carry operation.\n";
        }
    }

    return 0;
}