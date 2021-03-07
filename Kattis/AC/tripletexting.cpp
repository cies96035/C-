#include<iostream>
using namespace std;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    string s;
    cin >> s;
    int len = s.size() / 3;
    string a = s.substr(0, len);
    string b = s.substr(len, len);
    string c = s.substr(2 * len, len);
    if(a == b){
        cout << a << '\n';
    }else if(a == c){
        cout << a << '\n';
    }else{
        cout << b << '\n';
    }
    return 0;
}