#include<iostream>
using namespace std;

#define maxN 100100

int A=0,B=0,N,p[maxN],win[3][2]={{0,2},{2,5},{5,0}};
int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	cin>>N;
	for(int i=0;i<N;i++)
		cin>>p[i];
	for(int i=0,tmp;i<N;i++)
	{
		cin>>tmp;
		if(p[i]==tmp)
			A+=1,B+=1;
		else if(
		(p[i]==0&&tmp==2)||
		(p[i]==2&&tmp==5)||
		(p[i]==5&&tmp==0))
			A+=3,B-=1;
		else
			A-=1,B+=3;
	}
	cout<<A<<' '<<B<<'\n'; 
	return 0;
}

