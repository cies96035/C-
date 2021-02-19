#include<iostream>
using namespace std;

string ah;
string aah;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> ah >> aah;
    if(ah.size() >= aah.size()){
        cout << "go\n";
    }else{
        cout << "no\n";
    }
    return 0;
}