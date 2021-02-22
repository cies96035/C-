#include<iostream>
using namespace std;

int G, S, C;
int cost;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> G >> S >> C;
    cost = G * 3 + S * 2 + C;
    if(cost >= 8){
        cout << "Province or ";
    }else if(cost >= 5){
        cout << "Duchy or ";
    }else if(cost >= 2){
        cout <<"Estate or ";
    }

    if(cost >= 6){
        cout << "Gold\n";
    }else if(cost >= 3){
        cout << "Silver\n";
    }else{
        cout << "Copper\n";
    }
    return 0;
}