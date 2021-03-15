#include<iostream>
using namespace std;

const string trans[26] = {
    "@", "8", "(", "|)", "3",
    "#", "6", "[-]", "|", "_|",
    "|<", "1", "[]\\/[]", "[]\\[]", "0",
    "|D", "(,)", "|Z", "$", "\'][\'",
    "|_|", "\\/", "\\/\\/", "}{", "`/",
    "2"
};
char ipt;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    while(cin.get(ipt)){
        if('a' <= ipt && ipt <= 'z'){
            cout << trans[ipt - 'a'];
        }else if('A' <= ipt && ipt <= 'Z'){
            cout << trans[ipt - 'A'];
        }else{
            cout << ipt;
        }
    }
    cout << '\n';
    return 0;
}