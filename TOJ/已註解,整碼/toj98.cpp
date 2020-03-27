#include<iostream>
using namespace std;

int main() {
    long long a=299792458;
    cout<<"1 Light-second(LS) is "<< a <<" metres."<<endl;
    a*=60;
    cout<<"1 Light-minute(LM) is "<< a <<" metres."<<endl;
    a*=60;
    cout<<"1 Light-hour(LH) is "<< a <<" metres."<<endl;
    a*=24;
    cout<<"1 Light-day(LD) is "<< a <<" metres."<<endl;
    a*=7;
    cout<<"1 Light-week(LW) is "<< a <<" metres."<<endl;
    a/=7;
    a*=365;
    cout<<"1 Light-year(LY) is "<< a <<" metres."<<endl;
    return 0;
}
