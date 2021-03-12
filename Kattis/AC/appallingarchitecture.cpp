#include<iostream>
using namespace std;
using ld = long double;

const int MAX_W = 110;

char c;
int a, b;
int h, w;
int Sum;
ld cog;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    a = MAX_W;
    b = 0;

    cin >> h >> w;
    
    for(int i = h - 1; i >= 0; i--){
        for(int j = 0; j < w; j++){
            cin >> c;
            if(c != '.'){
                cog += ( (ld)j + 0.5 );
                if(!i){
                    if(a > j){
                        a = j;
                    }
                    if(b < j){
                        b = j;
                    }
                }
                Sum++;
            }
        }
    }

    cog /= Sum;

    if(a > (int)cog){
        cout << "left\n";
    }else if(b < (int)cog){
        cout << "right\n";
    }else{
        cout << "balanced\n";
    }

    return 0;
}