#include<iostream>
using namespace std;
int main()
{
	//分別判斷每個長度，好像不用開到long long 
    int pm;
    cin>>pm;
    if(pm<10)cout<<"Y"<<endl;
    else if(pm<1000)cout<<"X"<<endl;
    else if(pm<400000)cout<<"UV"<<endl;
    else if(pm<700000)cout<<"VIS"<<endl;
    else if(pm<1000000000)cout<<"IR"<<endl;
    else cout<<"R"<<endl;
    return 0;
}
