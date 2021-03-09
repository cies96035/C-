#include<iostream>
using namespace std;

string s;
int gotAway;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    gotAway = true;
    for(int i = 1; i <= 5; i++){
        cin >> s;
        if(s.find("FBI") != -1){
            cout << i << '\n';
            gotAway = false;
        }
    }
    if(gotAway){
        cout << "HE GOT AWAY!\n";
    }
    return 0;
}