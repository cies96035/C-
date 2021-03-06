#include<iostream>
using namespace std;

int wsCnt, llCnt, ulCnt, sCnt;
long double sumCnt;
char c;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    while(cin.get(c) && c != '\n'){
        if('a' <= c && c <= 'z'){
            llCnt++;
        }else if('A' <= c && c <= 'Z'){
            ulCnt++;
        }else if(c == '_'){
            wsCnt++;
        }else{
            sCnt++;
        }
    }
    sumCnt = wsCnt + llCnt + ulCnt + sCnt;
    cout << wsCnt / sumCnt << '\n';
    cout << llCnt / sumCnt << '\n';
    cout << ulCnt / sumCnt << '\n';
    cout << sCnt / sumCnt << '\n';
    return 0;
}