#include<iostream>
#include<vector> 
#include<algorithm>
#include<iomanip>
using namespace std;

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	cout<<fixed<<setprecision(6);
	int n,nums;
	vector<long double> num;
	cin>>n;
	num.push_back(-2147483647);
	num.push_back(2147483647);
	n+=2;
	for(int i=2;i<n;i++)
	{
		cin>>nums;
		num.insert(lower_bound(num.begin(),num.end(),nums),nums);
		if(i%2)cout<<(num[i/2]+num[i/2+1])/2<<endl;
		else cout<<num[i/2]<<endl;
	}
	return 0;
}

