#include<iostream>
using namespace std;

int main()
{
	//end:最後結果，>0王子勝，<0公主勝，=0平手 
    int a,b,n,end=0;
    cin>>n;
    while(n--)
    {
        cin>>a>>b;
        if((a==5&&b==0)||(a==2&&b==5)||(a==0&&b==2))
        end++;
        else if((a==0&&b==5)||(a==5&&b==2)||(a==2&&b==0))
        end--;
    }
    if(end==0)cout<<"The referee wins.\n";
    else if(end>0)cout<<"The prince wins.\n";
    else{cout<<"The princess wins.\n";}
    return 0;
}
