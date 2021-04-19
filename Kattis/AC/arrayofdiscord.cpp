#include<bits/stdc++.h>
using namespace std;
const int MAX_N = 110;

int n;
string str[MAX_N];
char tmpc;
bool successFlg;

int main(){

    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> str[i];
    }

    for(int i = 1; i < n; i++){
        if(successFlg){
            break;
        }
        string &a = str[i - 1], &b = str[i];
        if(a.size() == b.size() && a <= b){ //try
            for(int j = 0; j < a.size(); j++){
                tmpc = a[j];
                a[j] = '9';
                if(a > b){ //success
                    successFlg = true;
                    break;
                }
                a[j] = tmpc;

                tmpc = b[j];
                b[j] = ( j == 0 && b.size() != 1 ) ? '1' : '0';
                if(a > b){
                    successFlg = true;
                    break;
                }
                b[j] = tmpc;
            }
        }
    }
    if(successFlg){
        for(int i = 0; i < n; i++){
            cout << str[i] << ' ';
        }
        cout << '\n';
    }else{
        cout << "impossible\n";
    }
}