#include<iostream>
using namespace std;

const string simon = "Simon says";

string ipt;
int n;
bool simonSays(string s){
    if(s.size() <= simon.size()){
        return false;
    }
    for(int i = 0; i < simon.size(); i++){
        if(s[i] != simon[i]){
            return false;
        }
    }
    return true;
}
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> n;
    cin.ignore();
    while(n--){
        getline(cin, ipt);
        if(simonSays(ipt)){
            for(int i = simon.size() + 1; i < ipt.size(); i++){
                cout << ipt[i];
            }
            cout << '\n';
        }
    }
    return 0;
}