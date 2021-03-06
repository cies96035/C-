#include<iostream>
using namespace std;

int X, Y, N;
bool flg;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> X >> Y >> N;
    for(int i = 1; i <= N; i++){
        flg = true;
        if((i % X) == 0){
            cout << "Fizz";
            flg = false;
        }
        if((i % Y) == 0){
            cout << "Buzz";
            flg = false;
        }
        if(flg){
            cout << i;
        }
        cout << '\n';
    }
    return 0;
}