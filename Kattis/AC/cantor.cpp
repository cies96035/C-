#include<iostream>
#include<sstream>
using namespace std;
using ld = long double;

string s;
stringstream ss;
ld num;

bool Check(ld num){
    for(int i = 0; i < 10; i++){
        num *= 3;
        if((int)num == 1){
            return false;
        }
        num -= (int)num;
    }
    return true;
}
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    while(cin >> s && s != "END"){
        ss << s;
        ss >> num;
        if(Check(num)){
            cout << "MEMBER\n";
        }else{
            cout << "NON-MEMBER\n";
        }
        ss.clear();
    }
    return 0;
}