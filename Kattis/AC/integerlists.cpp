#include<bits/stdc++.h>
using namespace std;

const int MAX_N = 100100;

int T;
string p;
char c;
int n, x[MAX_N];
int lx, rx;
bool R;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> T;
    while(T--){
        R = false;
        x[0] = 0;

        cin >> p;
        cin >> n;
        cin.ignore();
        for(int i = 0; cin.get(c) && c != '\n' ;){
            if(c == '['){
                continue;
            }else if(c == ',' || c == ']'){
                i++;
                x[i] = 0;
            }else if('0' <= c && c <= '9'){
                x[i] = 10 * x[i] + c - '0';
            }
        }
        lx = 0;
        rx = n - 1;

        for(auto c : p){
            if(c == 'R'){
                R = !R;
            }else{
                if(R){
                    rx--;
                }else{
                    lx++;
                }
            }
        }

        if(lx > rx + 1){
            cout << "error\n";
        }else{
            cout << '[';
            if(R){
                while(lx < rx){
                    cout << x[rx] << ',';
                    rx--;
                }
            }else{
                while(lx < rx){
                    cout << x[lx] << ',';
                    lx++;
                }
            }
            if(lx != rx + 1){
                cout << x[lx];
            }
            cout << "]\n";
        }
    }
    return 0;
}