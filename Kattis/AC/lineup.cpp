#include<iostream>
using namespace std;

int N;
string str, lstr;
bool increase, decrease;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    increase = decrease = true;

    cin >> N;

    cin >> lstr;
    while(--N){
        cin >> str;
        if(str > lstr){
            decrease = false;
        }else{
            increase = false;
        }
        lstr = str;
    }
    if(increase){
        cout << "INCREASING\n";
    }else if(decrease){
        cout << "DECREASING\n";
    }else{
        cout << "NEITHER\n";
    }
    return 0;
}