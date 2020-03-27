#include<iostream>
using namespace std;

#define maxN 100001

struct Node 
{
	int l,r;
	bool happy;
}node[maxN*2];

int dcat[maxN];

void build(int root,int l,int r)
{
	if(l==r)
	{
		node[root].l=node[root].r=dcat[l];
		node[root].happy=1;
		return;
	}
	int mid=(l+r)/2,LC=root*2,RC=LC+1;
	build(LC,l,mid);
	build(RC,mid+1,r);
	node[root].l=node[LC].l;
	node[root].r=node[RC].r;
	node[root].happy= (node[LC].happy&&node[RC].happy)&&(node[RC].l-1==node[LC].r) ? 1 : 0 ;
	return;
}
int len;
void query(int root,int l,int r)
{
	
}
int main()
{
	int N;
	cin>>N;
	for(int i=0;i<N;i++)
		cin>>dcat[i];
	build(1,0,N-1);
	return 0;
}

