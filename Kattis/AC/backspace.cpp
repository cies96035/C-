#include<iostream>
#include<algorithm>
using namespace std;

const int MAX_S = 1001000;
char words[MAX_S];
int wordsIndex;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    while(cin >> words[wordsIndex]){
        if(words[wordsIndex] == '<' && wordsIndex != 0){
            wordsIndex--;
        }else{
            wordsIndex++;
        }
    }
    words[wordsIndex] = '\0';
    cout << words << '\n';
    return 0;
}