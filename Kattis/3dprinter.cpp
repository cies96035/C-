#include<iostream>
using namespace std;

int day;
int n;
int print;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> n;
    print = 1;
    day = 1;
    while(print < n){
        print *= 2;
        day++;
    };
    cout << day << '\n';
    return 0;
}