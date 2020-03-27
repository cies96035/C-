#include<iostream>
using namespace std;
int main()
{
    int a,b,c,sum=0;
    cin>>a>>b>>c;
    for(int x=0;x<b;x++)
    {
    	int gash,num;
        cin>>gash>>num;
        sum+=gash*num;
    } 
    cout<<(sum+a-c)/4<<endl;
    return 0;
}
