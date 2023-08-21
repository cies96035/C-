#include<bits/stdc++.h>

using namespace std;
string str;
string usealpha;
set<string> ans;

int main(){
    cin >> usealpha >> str;
    for(int i = 0; i <= str.size(); i++){
        string tmp = str;
        tmp.insert(tmp.begin() + i, 'a');
        for(int j = 0; j < usealpha.size(); j++){
            tmp[i] = usealpha[j];
            ans.insert(tmp);
        }
    }
    ans.insert(str.substr(1, str.size() - 1));
    for(int i = 1; i < str.size(); i++){
        string tmp = str.substr(0, i) + str.substr(i + 1, str.size() - i);
        ans.insert(tmp);
    }

    for(int i = 0; i < str.size(); i++){
        string tmp = str;
        for(auto c : usealpha){
            tmp[i] = c;
            ans.insert(tmp);
        }
    }
    ans.erase(str);
    for(auto s : ans){
        cout << s << '\n';
    }
    return 0;
}