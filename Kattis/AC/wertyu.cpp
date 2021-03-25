#include<iostream>
#include<map>
using namespace std;

const string keyboard[4] = {
    "`1234567890-=",
    "QWERTYUIOP[]\\",
    "ASDFGHJKL;\'",
    "ZXCVBNM,./"
};
map<char, char> Map;
char c;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    for(int i = 0; i < 4; i++){
        for(int j = 1; j < keyboard[i].size(); j++){
            Map[ keyboard[i][j] ] = keyboard[i][j - 1];
        }
    }
    Map[' '] = ' ';
    Map['\n'] = '\n';
    while(cin.get(c)){
        cout << Map[c];
    }
    return 0;
}