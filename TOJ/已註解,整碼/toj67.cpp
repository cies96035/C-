#include<iostream>
using namespace std;

#define N 1000000007

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
    char k;
    //num:癘魁–计,sum:魁–计羆㎝ 
    int num=0,sum=0,son;//son:魁だ 
    bool flag=0;//耞琌ぃ琌だ计 
    while(cin.get(k))
    {
    	if(k>='0'&&k<='9')
		{
			num=num*10+k-'0';
		}
		else if(k==' ')
		{
			if(!flag)//狦ぃ琌だ计 
				sum+=num;
			else if(num&&son%num==0)//狦琌だ计俱计 
				sum+=son/num,flag=0,son=0;
			num=0;
			sum%=N;
			flag=0;
		} 
		else if(k=='\n')
		{
			if(!flag)//狦ぃ琌だ计 
				sum+=num;
			else if(num&&son%num==0)//狦琌だ计俱计 
				sum+=son/num,son=0;
			cout<<sum%N<<endl;
			sum=num=0;
			flag=0;
		}
		else// 埃腹 
		{
			son=num;//だ 
			num=0;//计耴箂 
			flag=1;//Τだ计 
		}
    }
    return 0;
}
