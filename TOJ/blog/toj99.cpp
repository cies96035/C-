#include<iostream>
using namespace std;
int main()
{
    long double a,b,c,d,x;
    cin>>a>>b>>c>>d;
    x=a*d-b*c;
    //¤â°Ê§PÂ_¤p»~®t 
    if(x>0.0000001||x<-0.0000001)cout<<"1"<<endl;
    else cout<<"0"<<endl;
    return 0;
}
