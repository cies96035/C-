#include<iostream>
using namespace std;

int main()
{
    int X,Y,count=1,num=1;
    cin>>X>>Y;
    while(num%X!=0)//直到num值為X的倍數 
    {
    	//加乘輪替 
        if(count%2)num++;
        else num*=2;
        count++;
    }
    if(num%Y==0)cout<<"right"<<endl;
    else cout<<"left"<<endl;
    return 0;
}

