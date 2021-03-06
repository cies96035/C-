#include<iostream>
#include<sstream>
using namespace std;

const int MAX_S = 10100;

string tmp;
string text;
int n;
char encryp[MAX_S];
int encrypId;

char Upper(char c){
    if('a' <= c && c <= 'z'){
        return c + 'A' - 'a';
    }
    return c;
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    while(cin >> n && n){

        cin.ignore();
        encrypId = 0;
        getline(cin, tmp);
        stringstream ss(tmp);
        
        while(ss >> tmp){
            text += tmp;
        }

        for(int i = 0; i < text.size(); i++){
            encryp[encrypId] = Upper(text[i]);
            encrypId += n;
            if(encrypId >= text.size()){
                encrypId = encrypId % n + 1;
            }
        }
        encryp[text.size()] = '\0';
        
        cout << encryp << '\n';
        text.clear();
    }
    return 0;
}