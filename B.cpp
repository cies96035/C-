#include<iostream>
#include<algorithm>
using namespace std;

#define nonum 3

int N,L;

inline int fit(string a,string b)
{
	bool flag=0;
	for(int i=0;i<L;i++)
		if(a[i]!=b[i])
			if(flag++)return 2;
	return flag;
}
int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	int T;
	cin>>T;
	for(int Case=0;Case<T;)
	{
		int count=0;
		cin>>N>>L;
		string plug[N],device[N];
		int form[N][N]; 
		
		//輸入
		
		for(int i=0;i<N;i++)
			cin>>plug[i];
		for(int i=0;i<N;i++)
			cin>>device[i];
		
		
		//得到表格 
		for(int i=0;i<N;i++)
			for(int j=0;j<N;j++)
				form[i][j]=fit(plug[i],device[j]);
		
		cout<<"form\n  ";for(int b=0;b<N;b++){for(int v=0;v<N;v++)cout<<form[b][v]<<' ';cout<<endl<<"  ";		}
		
				
		cout<<"Case #"<<++Case<<": ";
		(N!=0 ? cout<<count<<'\n' : cout<<"IMPOSSIBLE\n");
	}
	return 0;
}

