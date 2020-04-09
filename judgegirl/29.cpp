#include<iostream>
using namespace std;
 
int main() {
	int r,c,ans=1;
	cin>>r>>c;
	c--;
	for(int i=1;i<=c;i++,r++)
	{
		ans*=r;
		ans/=i;
	}
	cout<<ans<<endl;
	return 0;
}
