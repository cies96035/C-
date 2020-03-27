#include<iostream>
#include<bitset>
#include<algorithm>
using namespace std;

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	int T;
	cin>>T;
	for(int Case=0;Case<T;)
	{
		int N,L;
		cin>>N>>L;
		bitset<64> input;
		long long plug[N],device[N];
		
		for(int i=0;i<N;i++)
		{
			cin>>input;
			plug[i]=input.to_ullong();
		}
		for(int i=0;i<N;i++)
		{
			cin>>input;
			device[i]=input.to_ullong();
		}
		sort(plug,plug+N);
		sort(device,device+N);
		cout<<endl;for(int i=0;i<N;i++)cout<<plug[i]<<' ';cout<<endl;for(int i=0;i<N;i++)cout<<device[i]<<' ';cout<<endl;
		
		long long M=2*N,plug_div[M-1],device_div[N-1],ans=100;
		for(int i=0;i<N-1;i++)
			plug_div[i]=plug_div[i+N]=plug[i+1]-plug[i];
		plug_div[N-1]=(2<<(L-1))+plug[0]-plug[N-1];
		for(int i=0;i<N-1;i++)
			device_div[i]=device[i+1]-device[i];
		cout<<endl;for(int i=0;i<M-1;i++)cout<<plug_div[i]<<' ';cout<<endl;for(int i=0;i<N-1;i++)cout<<device_div[i]<<' ';cout<<endl;
		
		for(int i=0;i<M-1;i++)
		{
			for(int j=0;j<N-1;j++)
			{
				if(plug_div[i+j]!=device_div[j])break;
				if(j==N-2)
					ans=min(ans,(long long)((bitset<64>)i).count());
			}
		}
		cout<<"Case #"<<++Case<<": ";
		(ans==100 ? cout<<"IMPOSSIBLE\n" : cout<<ans<<'\n');
	}
	return 0;
}
