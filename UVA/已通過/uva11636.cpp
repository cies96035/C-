#include<iostream>
#include<algorithm>
using namespace std;


#define Max 15
int twocarry[Max];
int N,Case=1;

void twoInit()
{
	twocarry[0]=1;
	for(int i=1;i<Max;i++)
		twocarry[i]=twocarry[i-1]<<1;
	return; 
}
int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	twoInit();
	
	while(cin>>N&&N>=0)
		cout<<"Case "<<Case++<<": "<<lower_bound(twocarry,twocarry+Max,N)-twocarry<<'\n';
	return 0;
}
