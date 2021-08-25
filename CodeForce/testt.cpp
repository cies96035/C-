#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for(int i = a; i < b; i++)
bool checkValidString(string s) {
    int left = 0, star = 0;
    for(auto c : s){
        if(c == '('){
            left++;
        }else if(c == '*'){
            star++;
        }else{
            if(left){
                left--;
            }else if(star){
                star--;
            }else{
                return false;
            }
        }
    }
    cout << left << ' ' << star << endl;
    return star >= left;
}
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    string str = "(((((*(((((*)*(**())))))))))))((((*)))))(((**(*)))(*)";
    string str = "(((((*(((((*)*(**())))))))))))((((*)))))(((**(*)))(*)";
    int a = 0, b = 0, c = 0;
    for(auto cc : str){
        if(cc == '(')
            a++;
        if(cc == ')')
            b++;
        if(cc == '*')
            c++;
    }
    // c = a - b;
    // for(int i = str.size() - 1; i >= 0 && c; i--){
    //     if(str[i] == '*'){
    //         str[i] = ')';
    //         c--;
    //     }
    // }
    // cout << str << endl;
    cout << a << ' ' << b <<' ' << c << endl;
    checkValidString(str);
    return 0;
}