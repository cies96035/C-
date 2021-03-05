#include<iostream>
using namespace std;

int k;
int S;
string str;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> k;
    S = (k - 1) / 25 + 1;
    if(S == 1){
        cout << 'a' << char(k % 26 + 'a') << '\n';
    }else{
        for(int i = 0; i <= S; i++){
            if(i % 2){
                str += 'z';
            }else{
                str += 'a';
            }
        }
        k -= S * 25;
        while(k < -1){
            str[1]--;
            k += 2;
        }
        if(k){
            if(str.back() == 'a'){
                str.back()++;
            }else{
                str.back()--;
            }
        }
        cout << str << '\n';
    }
    return 0;
}