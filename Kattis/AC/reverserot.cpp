#include<iostream>
using namespace std;

string str;
int shift;
void S(char &c){
    int id;
    if('A' <= c && c <= 'Z'){
        id = c - 'A';
    }else if(c == '_'){
        id = 26;
    }else{
        id = 27;
    }
    id += shift;
    id %= 28;
    if(0 <= id && id <= 25){
        c = id + 'A';
    }else if(id == 26){
        c = '_';
    }else{
        c = '.';
    }
}
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    while(cin >> shift && shift){
        cin >> str;
        for(auto &c : str){
            S(c);
        }
        for(int i = str.size() - 1; i >= 0; i--){
            cout << str[i];
        }
        cout << '\n';
    }
    return 0;
}