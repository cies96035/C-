#include<iostream>
#include<vector>
using namespace std;
using ull = unsigned long long;

string str;
vector<string> num;
string tmp;

int charToNum(char c){
    if('a' <= c && c <= 'f'){
        return c - 'a' + 10;
    }else if('A' <= c && c <= 'F'){
        return c - 'A' + 10;
    }else if('0' <= c && c <= '9'){
        return c - '0';
    }else{
        return -1;
    }
}

void Print(){
    cout << tmp << ' ';
    ull n = 0;
    for(int i = 2; i < tmp.size(); i++){
        n = 16 * n + charToNum(tmp[i]);
    }
    cout << n << '\n';
    tmp.clear();
    return;
}
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    while(cin >> str){
        for(int i = 1; i < str.size(); i++){
            if(str[i - 1] == '0' && (str[i] == 'x' || str[i] == 'X')){
                tmp = str[i - 1];
                tmp += str[i];
                i++;
                while(i < str.size()){
                    if(charToNum(str[i]) != -1){
                        tmp += str[i];
                    }else{
                        break;
                    }
                    i++;
                }
                if(!tmp.empty()){
                    Print();
                }
            }
        }
    }
    return 0;
}