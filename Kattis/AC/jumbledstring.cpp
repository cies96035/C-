#include<iostream>
using namespace std;

int a, b, c, d;
int Zero, One;
bool Error;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> a >> b >> c >> d;

    //Step 1 : check zero's and one's amount
    for(int i = 1; true; i++){
        if(i * (i - 1) == 2 * a){
            Zero = i;
            break;
        }else if(i * i - 1 > 2 * a){
            Error = true;
            break;
        }
    }
    for(int i = 1; true; i++){
        if(i * (i - 1) == 2 * d){
            One = i;
            break;
        }else if(i * i - 1 > 2 * d){
            Error = true;
            break;
        }
    }
    if(One == 1 && b + c == 0){
        One--;
    }
    if(Zero == 1 && b + c == 0){
        Zero--;
    }

    if(Error || One * Zero != b + c){//impossible case
        cout << "impossible\n";
    }else if(One + Zero == 0){//special case
        cout << "1\n";
    }else{//other case
        for(int i = 0, e = One + Zero; i < e; i++){
            if(One <= b){
                cout << '0';
                b -= One;
            }else{
                cout << '1';
                One--;
            }
        }
        cout << '\n';
    }
    return 0;
}