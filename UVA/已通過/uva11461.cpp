#include<iostream>
#include<algorithm>
using namespace std;

#define Max 350
#define MaxN 100000
int square_number[Max],index=0;
int a,b;

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	for(int i=1,j=1;j<MaxN;i++,j=i*i)
		square_number[index++]=j;
		
	while(cin>>a>>b&&a)
		cout<<upper_bound(square_number,square_number+index,b)-lower_bound(square_number,square_number+index,a)<<'\n';
	return 0;
}

