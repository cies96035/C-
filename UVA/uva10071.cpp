#include<iostream>
using namespace std;
/*
題目求:2t 秒後所"經過的距離"是多少 
v0可設0
 
v0+at=v1
v0+a2t=v2
d=v2*2t/2=(2*v1)*2t/2
d=2*v1*t
*/
int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int v,t;
	while(cin>>v>>t)
		cout<<2*v*t<<'\n';
	return 0;
}

