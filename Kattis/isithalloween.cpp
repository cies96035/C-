#include<iostream>
using namespace std;

string Month;
int date;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> Month >> date;
    if(Month == "OCT" && date == 31 ||
    Month == "DEC" && date == 25){
        cout << "yup\n";
    }else{
        cout << "nope\n";
    }
    return 0;
}