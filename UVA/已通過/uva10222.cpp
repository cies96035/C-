#include<iostream>
using namespace std;

#define MAXN 128
const string kb[3]=
{
    "qwertyuiop[]",
    "asdfghjkl;\'"
    "zxcvbnm,."
};
char c[MAXN];
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    for(int i = 0;i<3 ; i++)
        for(int j = 2; j < kb[i].size(); j++)
            c[ kb[i][j] ] = c[ kb[i][j] - 'a' + 'A' ] = kb[ i ][ j - 2 ];
    c[' '] = ' ';
    c['\n'] = '\n';
    char ch;
    while(cin.get(ch))
        cout << c[ch];
    return 0;
}