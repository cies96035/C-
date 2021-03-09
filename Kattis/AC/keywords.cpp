#include<iostream>
#include<set>
using namespace std;

string str, ipt;
set<string> words;
int n;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> n;
    cin.ignore();
    for(int i = 0; i < n; i++){
        getline(cin, ipt);
        for(auto c : ipt){
            if('A' <= c && c <= 'Z'){
                str += c - 'A' + 'a';
            }else if(c == ' '){
                str += '-';
            }else{
                str += c;
            }
        }
        words.insert(str);
        str.clear();
    }
    cout << words.size() << '\n';
    return 0;
}