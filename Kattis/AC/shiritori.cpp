#include<iostream>
#include<set>
using namespace std;

int n;
int loser;
string s, ls;
set<string> dic;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> n;
    cin >> ls;
    dic.insert(ls);
    for(int i = 1; i < n; i++){
        cin >> s;
        if(ls.back() != s.front() || dic.find(s) != dic.end()){
            if(!loser){
                loser = (i % 2) + 1;
            }
        }
        ls = s;
        dic.insert(s);
    }
    if(loser == 1){
        cout << "Player 1 lost\n";
    }else if(loser == 2){
        cout << "Player 2 lost\n";
    }else{
        cout << "Fair Game\n";
    }
    return 0;
}