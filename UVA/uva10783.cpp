#include<iostream>
using namespace std;

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	int T;
	cin>>T;
	for(int Case=0;Case<T;)
	{
		int a,b;
		cin>>a>>b;
		a%2?a:a++;
		b%2?b:b--;
		cout<<"Case "<<++Case<<": "<<(a+b)*(b-a+2)/4<<'\n';
	}
	return 0;
}

