#include<iostream>
using namespace std;

int A, B, score;
char a;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    while(cin >> a >> score){
        if(a == 'A'){
            A += score;
        }else{
            B += score;
        }
    }
    if(A > B){
        cout << "A\n";
    }else{
        cout << "B\n";
    }
    return 0;
}