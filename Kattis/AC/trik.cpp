#include<iostream>
using namespace std;

char op;
bool ball[4];
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    ball[1] = true;
    while(cin >> op){
        if(op == 'A'){
            swap(ball[1], ball[2]);
        }else if(op == 'B'){
            swap(ball[2], ball[3]);
        }else{
            swap(ball[1], ball[3]);
        }
    }
    for(int i = 1; i < 4; i++){
        if(ball[i]){
            cout << i << '\n';
        }
    }
    return 0;
}