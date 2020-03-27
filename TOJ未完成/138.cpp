#include<iostream>
#include<vector>
using namespace std;

int main()
{
	
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	//b=ak/a-k* //a>k
	
	int k;
	while(cin>>k)
	{
		vector<int> ans;
		for(int a=k+1,maxa=2*k;a<=maxa;a++)
			if(!((a*k)%(a-k)))
				ans.push_back(a);
		cout<<ans.size()<<'\n';
		for(int i=0;i<ans.size();i++)
			cout<<"1/"<<k<<" = 1/"<<(ans[i]*k)/(ans[i]-k)<<" + 1/"<<ans[i]<<'\n';
	}
	
	
	return 0;
}

