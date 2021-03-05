#include<iostream>
#include<stack>
using namespace std;

const int MAX_S = 1001000;
char words[MAX_S];
int wordsIndex;
char c;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    while(cin >> c){
        if(c == '<' && wordsIndex != 0){
            wordsIndex--;
        }else{
            words[wordsIndex++] = c;
        }
    }
    words[wordsIndex] = '\0';
    cout << words << '\n';
    return 0;
}