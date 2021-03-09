#include<iostream>
#include<set>
using namespace std;

string ipt;
bool dup;
set<string> dic;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    while(cin >> ipt){
        if(dic.find(ipt) != dic.end()){
            dup = true;
        }
        dic.insert(ipt);
    }
    if(dup){
        cout << "no\n";
    }else{
        cout << "yes\n";
    }
    return 0;
}