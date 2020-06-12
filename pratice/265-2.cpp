#include<iostream>
#include<map>
using namespace std;

const int maxN=45100,maxangry=2000100;
int N,M,Q;
int a,b,c;
int num[maxangry];
int R(int a,int b)
{
	return a*maxN+b;
}
map<int,int> road;
/*

*/
int main()
{
	cin>>N>>M>>Q;
	for(int i=0;i<M;i++)
	{
		cin>>a>>b>>c;
		if(road.find(R(a,b))==road.end()) 
		road[R(a,b)]=c;
		road[R(b,a)]=c;
	}
	return 0;
}

