#include<iostream>
using namespace std;

string Card;
int poker[256];
int Max = 0;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    while(cin >> Card){
        poker[Card[0]]++;
        if(Max < poker[Card[0]]){
            Max = poker[Card[0]];
        }
    }
    cout << Max << '\n';
    return 0;
}