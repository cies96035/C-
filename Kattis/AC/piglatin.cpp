#include<iostream>
#include<sstream>
using namespace std;
using sstr = stringstream;

bool Vowel[256];
string str;
string Latin(string s){
    if(Vowel[ s.front() ]){
        return s + "yay";
    }
    for(int i = 1; i < s.size() - 1; i++){
        if(Vowel[s[i]]){
            return s.substr(i, s.size() - i) + s.substr(0, i) + "ay";
        }
    }
    return s.back() + s.substr(0, s.size() - 1) + "ay";
}
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    Vowel['a'] = Vowel['e'] = Vowel['i'] = Vowel['o'] = Vowel['u'] = Vowel['y'] = true;
    while(getline(cin, str)){
        sstr ss(str);
        ss >> str;
        cout << Latin(str);
        while(ss >> str){
            cout << ' ' << Latin(str);
        }
        cout << '\n';
    }
    return 0;
}