#include<iostream>
#include<algorithm> 
using namespace std;

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	int n;
	cin>>n;
	string str[n];
	
	for(int i=0;i<n;i++)
		cin>>str[i];
		
	sort(str,str+n);
	
	for(int i=0;i<n;i++)
		cout<<str[i]<<'\n';
	return 0;
}

