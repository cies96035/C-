#include<iostream>
using namespace std;

int S;

bool Check(int x, int y){
    if(S % (x + y) == x || S % (x + y) == 0){
        return true;
    }
    return false;
}
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> S;
    cout << S << ":\n";
    for(int i = 2; i < S; i++){
        if(Check(i, i - 1)){
            cout << i << ',' << i - 1 << '\n';
        }
        if(Check(i, i)){
            cout << i << ',' << i << '\n';
        }
    }
    return 0;
}