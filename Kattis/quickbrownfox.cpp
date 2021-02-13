#include<iostream>
#include<cstring>
using namespace std;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int N;
    cin >> N;
    cin.ignore();
    bool letter[26];
    bool findLetter;
    string s;
    while(N--){
        findLetter = 1;
        memset(letter, 0, sizeof(letter));
        getline(cin, s);
        for(auto c : s){
            if('a' <= c && c <= 'z'){
                letter[c - 'a'] = 1;
            }else if('A' <= c && c <= 'Z'){
                letter[c - 'A'] = 1;
            }
        }
        for(int i = 0; i < 26; i++){
            if(letter[i] == 0){
                if(findLetter){
                    cout << "missing ";
                    findLetter = 0;
                }
                cout << char(i + 'a');
            }
        }
        if(findLetter)
            cout << "pangram";
        cout << '\n';
    }
    return 0;
}