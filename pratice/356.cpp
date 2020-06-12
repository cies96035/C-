#include<iostream>
#include<queue>
using namespace std;

const int maxN=13;
int arr[1<<maxN][1<<maxN];
int N,num=1;
//DFS
void down(int depth,int l,int r,int u,int d)
{
	//cout<<depth<<endl;
	if(depth==0)
	{
		arr[l][u]=num++;
		return;
	}
	int D=1<<(depth-1);
	//選此層左上
	down(depth-1,l,r-D,u,d-D);
	//選此層右下
	down(depth-1,l+D,r,u+D,d);
	//選此層右上
	down(depth-1,l,r-D,u+D,d);
	//選此層左下 
	down(depth-1,l+D,r,u,d-D);
	return;
}
/*
struct S
{
	int l,r,u,d,depth;
	S(int e,int a,int b,int c,int dd)
	{
		l=a;
		r=b;
		u=c;
		d=dd;
		depth=e;
	}
};
void up()
{
	queue<S> s;
	s.push(S(N,0,1<<N-1,0,1<<N-1));
	while(!s.empty())
	{
		S cur=s.front();
		s.pop();
		if(cur.depth==0)
			arr[cur.l][cur.u]=num++;
		else
		{
			int D=1<<(cur.depth-1);
			//選此層左上
			s.push(S(cur.depth-1,cur.l,cur.r-D,cur.u,cur.d-D));
			//選此層右下
			s.push(S(cur.depth-1,cur.l+D,cur.r,cur.u+D,cur.d));
			//選此層右上
			s.push(S(cur.depth-1,cur.l,cur.r-D,cur.u+D,cur.d));
			//選此層左下 
			s.push(S(cur.depth-1,cur.l+D,cur.r,cur.u,cur.d-D));
		}
	}
}*/
/*
1

1
2
3
4

11
21
31
41
12
22
32
42
...

111
211
311
411
121

*/ 
int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	cin>>N;
	down(N,0,1<<N-1,0,1<<N-1);
	cout<<"end\n";
	int n=1<<N;
	//up();
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
			cout<<arr[i][j]<<' ';
		cout<<'\n';
	}
	return 0;
}

