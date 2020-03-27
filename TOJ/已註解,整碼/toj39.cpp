/*
code1,七個月前寫的，有夠亂 
至少給我好好縮排阿 
#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
int main()
{
    char a[1000000];
    unsigned long long sum=1;
    while(cin>>a)
    {
        if(sum>=479001599)sum%=479001599;
             if((int)a[0]==37)
             {
                 cout<<sum<<endl;
                 sum=1;
             }
             else
             {
                 int h=0,b=0;
                for(int f=0;a[f]>='0'&&a[f]<='9';f++)h++;
                for(int f=h-1,t=0;f>=0;f--,t++)
                {
                    b+=((int)a[t]-48)*pow(10,f);
                }
                sum*=b;
            }
    }
    return 0;
}
*/
#include<iostream>
using namespace std;

#define N 479001599 

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
    char a;
    unsigned long long sum=1,num=0;
    bool f=0;//避免多空格，sum重複乘的狀況 
    while(cin.get(a))
    {
        if(a=='%')
        {
        	if(f)
        		sum*=num,sum%=N,f=0;
        	cout<<sum<<endl;
            sum=1;
        }
        else
        {
            if(a>='0'&&a<='9')
				num=num*10+a-'0',f=1;
            else 
			{
				if(f)
					sum*=num,sum%=N,f=0;
				num=0;
			}
        }
    }
    return 0;
}
