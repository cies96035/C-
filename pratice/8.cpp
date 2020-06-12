#include<iostream>
using namespace std;
int N;
string S,T;
int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	while(cin>>N)
	{
		cin.get();
		getline(cin,S);
		for(int i=0;i<N;i++)
			for(int j=i;j<S.size();j+=N)
				T.append(1,S[j]);
		cout<<T<<'\n';
		T.clear();
	}
	return 0;
}

