#include<bits/stdc++.h>
using namespace std;

const int MAX_Q = 1000001000;

bool isntPrime[MAX_Q];
int Q;
int q;
bool hasPrime;

bool check(){
    while(Q > 1){
        if(Q % q){
            return false;
        }
        Q /= q;
    }
    return true;
}
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> Q;
    if(Q == 1){
        cout << "no\n";
    }else{
        for(q = 2; q * q < Q; q++){
            if( !(Q % q) ){
                break;
            }
        }
        if(q * q > Q || check()){
            cout << "yes\n";
        }else{
            cout << "no\n";
        }
    }
    return 0;
}