#include<iostream>
using namespace std;

int ans[1000002]={0,3};//紀錄每個答案 

inline int getans(int n)//紀錄1~n-1跟n互質的有幾個，加進去陣列 
{
	int a,b,Ans=0;
	bool two=!n%2;
	for(int num=n-1;num>0;num--)
	{
		a=num,b=n;
		if(two&&!num%2)continue;
		while((a%=b)&&(b%=a));
		if(a+b==1)Ans++;
	}
	return Ans;
}
int main()
{
	/*
	如果a,b看得到，則b,a看得到，所以只要計算一半即可(*2) 
	0,1 1,0 1,1，都看得到，特例 
	1,2 1,3 2,3 2,5...這些互質，看得到
	2,4 2,6 3,6...這些不互質，都看不到 
	*/
	for(int i=2;i<10000;i++)
	{
		//ans[i]=ans[i-1]+getans(i)*2;
	}
	int N;
	while(cin>>N)
	{
		cout<<getans(N)<<endl;
	}
	return 0;
}

