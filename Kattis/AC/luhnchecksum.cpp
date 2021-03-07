#include<iostream>
using namespace std;

const int trans[10] = {
    0, 2, 4, 6, 8, 1, 3, 5, 7, 9
};

int T;
string str;

bool check(){
    int num = 0;
    bool Double = true;
    for(int i = str.size() - 1; i >= 0; i--){
        if(Double){
            num += str[i] - '0';
        }else{
            num += trans[ (str[i] - '0') ];
        }
        Double = !Double;
    }
    return !(num % 10);
}
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> T;
    while(T--){
        cin >> str;
        if(check()){
            cout << "PASS\n";
        }else{
            cout << "FAIL\n";
        }
    }
    return 0;
}