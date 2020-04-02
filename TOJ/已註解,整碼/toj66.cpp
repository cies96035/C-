#include<iostream>
using namespace std;

#define N 1000000007

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	 
    char k;
    //num:記錄每一個數字,sum:紀錄每個數字總和 
    int num=0,sum=0;
    bool add=0,minus=0;//判斷是否要加進sum裡面 
    while(cin.get(k))
    {
    	if(k>='0'&&k<='9')
		{
			num=num*10+k-'0';
			add=1;
		}
		else if(k==' ')
		{
			if(add)
				sum+=num,add=0;
			if(minus)
				sum-=num,minus=0;
			num=0;
			sum%=N;
		} 
		else if(k=='\n')
		{
			if(add)
				sum+=num,add=0;
			if(minus)
				sum-=num,minus=0;
			cout<<sum%N<<endl;
			sum=num=0;
		}
		else// 除號 
		{
			num=0;//分子歸零 
			minus=1;//減掉分母 
		}
    }
    return 0;
}
