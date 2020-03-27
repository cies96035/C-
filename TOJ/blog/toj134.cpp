#include<iostream>
#include<cstring>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    /*
	Code1，照題目做 
    long double n,數字太大，爆掉 
    a=1.6180339887498948482045868343656,
    b=-0.61803398874989484820458683436564,
    c=0.44721359549995793928183473374626;
    cin>>n;
    cout<<c*(pow(a,n)-pow(b,n))<<endl;
	*/
    
    
    /*
    Code2發現規律:
	#費氏數列 1 1 2 3 5 8 13
	long long n,a[500]={1,1};  數字還是太大 
    for(int k=2;k<500;k++)
    {
        a[k]=a[k-2]+a[k-1];
    }
    cin>>n;
    cout<<a[n-1]<<endl;
	*/
    
    //Code3，大數版費式數列
    int n,a[500][110],flag=0,flag2=0;  
	//a[第幾個值][第幾位數],flag:判斷進位用,flag2:避免輸出前綴零
	//利用題目給的公式可得出大概要開100多位 
    memset(a,0,sizeof(a));
    a[0][0]=1;
    a[1][0]=1;
    cin>>n;
    for(int k=2;k<n;k++)
    {
        for(int h=0;h<110;h++)
        {
            int t=a[k-2][h]+a[k-1][h];
            if(flag)
            {
                t++;
				flag=0;
            }
            if(t<10)
            	a[k][h]=t;
            else 
            {
            	a[k][h]=t-10;
                flag=1;
            }
        }
    }
    for(int h=110;h>=0;h--)
        if(a[n-1][h]>0||flag2)
        {
            cout<<a[n-1][h];
            flag2=1;
        }
    cout<<endl;
}

