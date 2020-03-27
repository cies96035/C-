//�ɤOver�A�S��}�L�A����|TLE
//���T�w�Q�k�S���A���ŦA�u�� 

#include<iostream>
#include<vector> 
using namespace std;

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	int T;
	cin>>T;
	while(T--)
	{
		int N,E;
		cin>>N>>E;
		vector<int> link[N];
		int neighbor[N]={0};//�Ia�i�H�s�����Ib a,b<N
		int ans1=0,ans2=0; 
		for(int i=0;i<E;i++)
		{
			int a,b;
			cin>>a>>b;
			neighbor[a]++;
			neighbor[b]++;
			link[a].push_back(b);
			link[b].push_back(a);
		}
		
		//�Dans1 
		for(int i=0;i<N;i++)
		{
			int k=0;
			for(int j=0;j<link[i].size();j++)
				if(link[i][j]>i)k++;
			if(k>ans1)ans1=k;
		}
		
		
		//�Dans2 
		bool visited[N]={0};
		for(int i=0;i<N;i++)
		{
			pair<int,int> min={1e9,0};
			for(int j=0;j<N;j++)
			{
				if(visited[j])continue;
				if(min.first>neighbor[j])
				{
					min.first=neighbor[j];
					min.second=j;
				}
			}
			
			visited[min.second]=1;
			int num=0;
			for(int j=0;j<link[min.second].size();j++)
			{
				if(visited[link[min.second][j]])continue;
				neighbor[link[min.second][j]]--;
				num++;
			}
			if(ans2<num)ans2=num;
		}
		cout<<ans1<<' '<<ans2<<endl; 
	}
	return 0;
}
