#include<iostream>
using namespace std;

string op;
int L, x, p;
int notAllow;
int terrace;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> L >> x;
    for(int i = 0; i < x; i++){
        cin >> op >> p;
        if(op == "enter"){
            if(terrace + p > L){
                notAllow++;
            }else{
                terrace += p;
            }
        }else{
            terrace -= p;
        }
    }
    cout << notAllow << '\n';
    return 0;
}