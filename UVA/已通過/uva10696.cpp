#include<iostream>
using namespace std;

int f91(int N)
{
	if(N>=101)return N-10;
	return f91(f91(N+11));
}
int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	int N;
	while(cin>>N&&N)
		cout<<"f91("<<N<<") = "<<f91(N)<<'\n';
	return 0;
}

