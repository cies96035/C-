#include<iostream>
#include<map>
using namespace std;

map<string, string> dic;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    string str;
    while(getline(cin, str) && str != ""){
        for(int i = 0; i < str.size(); i++){
            if(str[i] == ' '){
                dic[str.substr(i + 1, str.size() - i)] = str.substr(0, i);
                break;
            }
        }
    }
    while(getline(cin, str)){
        if(dic.find(str) != dic.end()){
            cout << dic[str] << '\n';
        }else{
            cout << "eh\n";
        }
    }
    return 0;
}