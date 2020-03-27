#include<iostream>
using namespace std;

short num[3100][3100];

struct Node
{	
	int sum;
	Node *LUC,*RUC,*LDC,*RDC;
};
//空間:1.333*(邊長)^2 

void build(Node* &root,int lx,int rx,int uy,int dy)
{
	root = new Node;
	if(lx==rx&&uy==dy)//切到剩一個為止 
	{
		root->sum=num[lx][uy];
		return; 
	}
	int midx=(lx+rx)/2,midy=(uy+dy)/2;
	if(lx==rx)
	{
		build(root->LUC,lx,rx,uy,midy);
		build(root->LDC,lx,rx,midy+1,dy);
		root->sum=root->LUC->sum+root->LDC->sum;
	}
	else if(uy==dy)
	{
		build(root->LUC,lx,midx,uy,dy);
		build(root->RUC,midx+1,rx,uy,dy);
		root->sum=root->RUC->sum+root->RUC->sum;
	}
	else
	{
		build(root->LUC,lx,midx,uy,midy);
		build(root->RUC,midx+1,rx,uy,midy);
		build(root->LDC,lx,midx,midy+1,dy);
		build(root->RDC,midx+1,rx,midy+1,dy);
		root->sum=root->LUC->sum+root->LDC->sum+root->RUC->sum+root->RDC->sum;
	}
	return;
}
long long sum,x1,x2,y1,y2;
void query(Node* root,int lx,int rx,int uy,int dy)
{
	if(x2<lx||rx<x1||y2<uy||dy<y1)return;//範圍外，離開搜索 
	if((x1<=lx&&rx<=x2)&&(y1<=uy&&dy<=y2))//範圍內，納入計算 
	{
		sum+=root->sum;
		return;
	}
	int midx=(lx+rx)/2,midy=(uy+dy)/2;
	query(root->LUC,lx,midx,uy,midy);
	query(root->RUC,midx+1,rx,uy,midy);
	query(root->LDC,lx,midx,midy+1,dy);
	query(root->RDC,midx+1,rx,midy+1,dy);
}

int ii,jj,k;
void change(Node* root,int lx,int rx,int uy,int dy)
{
	if(lx==rx&&uy==dy)
	{
		root->sum=k;
		return;
	}
	int midx=(lx+rx)/2,midy=(uy+dy)/2;
	if(ii<=midx&&jj<=midy)
		change(root->LUC,lx,midx,uy,midy);
	if(ii>midx&&jj<=midy)
		change(root->RUC,midx+1,rx,uy,midy);
	if(ii<=midx&&jj>midy)
		change(root->LDC,lx,midx,midy+1,dy);
	if(ii>midx&&jj>midy)
		change(root->RDC,midx+1,rx,midy+1,dy);
	root->sum=root->LUC->sum+root->LDC->sum+root->RUC->sum+root->RDC->sum;
}

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	Node* root;
	int n,m,q;
	cin>>n>>m;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			cin>>num[i][j];
	build(root,0,n-1,0,m-1);
	cin>>q;
	while(q--)
	{
		char ask;
		cin>>ask;
		if(ask=='Q')
		{
			cin>>x1>>y1>>x2>>y2;
			x1--,x2--,y1--,y2--,sum=0;
			query(root,0,n-1,0,m-1);
			cout<<sum<<endl;
		}
		else if(ask=='C')
		{
			cin>>ii>>jj>>k;
			ii--,jj--;
			change(root,0,n-1,0,m-1);
		}
	}
	return 0;
}

