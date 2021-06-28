#include<bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    string s;

    getline(cin, s);
    long long num = 0;
        int sign = 1;
        bool numed = false;
        bool Signed = false;
        for(auto c : s){
            if('0' <= c && c <= '9'){
                num = num * 10 + c - '0';
                if(sign == 1 && num >= 2147483647){
                    return 2147483647;
                }else if(sign == -1 && num >= 2147483648){
                    return -2147483648;
                }
                numed = true;
            }else if(c == '+' || c == '-'){
                if(Signed || numed){
                    break;
                }
                Signed = true;
                if(c == '-'){
                    sign = -1;
                }
            }else if(c != ' '){
                break;
            }
        }
    cout << num << endl;
    return 0;
}