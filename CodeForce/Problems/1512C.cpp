#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for(int i = a; i < b; i++)

int t, a, b;
string bitstr;
bool checkAndCount(){
    if( (a & 1) && (b & 1) ){
        return false;
    }
    if(bitstr.size() & 1){
        if(a & 1){
            if(bitstr[bitstr.size() / 2] == '1'){
                return false;
            }
            a--;
            bitstr[bitstr.size() / 2] = '0';
        }else{
            if(bitstr[bitstr.size() / 2] == '0'){
                return false;
            }
            b--;
            bitstr[bitstr.size() / 2] = '1';
        }
    }
    queue<int> q;
    for(int i = 0, j = bitstr.size() - 1; i < j; i++, j--){
        if(bitstr[i] + bitstr[j] == '1' + '0'){
            return false;
        }
        if(bitstr[i] == '0' || bitstr[j] == '0'){
            bitstr[i] = bitstr[j] = '0';
            a -= 2;
        }else if(bitstr[i] == '1' || bitstr[j] == '1'){
            bitstr[i] = bitstr[j] = '1';
            b -= 2;
        }else{
            q.push(i);
        }
    }
    while( !q.empty() ){
        if(a > 0){
            bitstr[ q.front() ] = bitstr[ bitstr.size() - q.front() - 1 ] = '0';
            a -= 2;
        }else if(b > 0){
            bitstr[ q.front() ] = bitstr[ bitstr.size() - q.front() - 1 ] = '1';
            b -= 2;
        }else{
            break;
        }
        q.pop();
    }
    return (a == 0 && b == 0);
}
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> t;
    while(t--){
        cin >> a >> b >> bitstr;
        if(checkAndCount()){
            cout << bitstr << '\n';
        }else{
            cout << "-1\n";
        }
    }
    return 0;
}