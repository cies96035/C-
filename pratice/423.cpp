//¯Âºéªº¼É¤O¡A¯ÂºéªºTLE 

#include<iostream>
using namespace std;
typedef long double ld;
const int ASCII=150,maxS=1000000;
string A,B;
int k,x,n,as,bs,num[maxS];
ld sum=0,add;

void Find()
{
	int index=k-bs,end=as-k+1;
	while(index<end)
	{
		for(int i=0,j=index,Num=1;i<bs;i++,j++)
		{
			if(j<0)continue;
			if(j>=as)break;
			if(B[i]==A[j])
				Num++;
			else
				Num=1;
			if(Num>k)
				num[i]++;
		}
		index++;
	}
	return ;
}

int main()
{
	cin>>A>>B>>k>>x;
	bs=B.size();
	as=A.size();
	add=1/ld(n=(bs-k+1));
	Find();
	for(int i=k-1;i<bs;i++)
		if(num[i]>x)sum+=add;
	/*
	for(int i=0;i<n;i++)
	{
		int t=0,o=0;
		do{	
			if(o>x)
			{
				sum+=add;
				break;
			}
			o++;
		}while(t=Find(B.substr(i,k),t)+1);
		
		if(sum>0.1)
			break;
	}*/ 
	if(sum>0.1)
		cout<<"copy dog!\n";
	else cout<<"innocent!\n";
	return 0;
}
