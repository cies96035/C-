#include<iostream>
using namespace std;

/*
芠诡–程计 
材N程计ゑN-1(2N-1)2
计材计计材计琌
材N计计㎝穦ゑ材N-1(2N-1)2*3
肈ヘ琌倒材N计计秖2N-1=肈ヘ倒
*/
int main()
{
	long long N;
	while(cin>>N)
		cout<<(3*N*N+6*N+3)/2-9<<endl;
	return 0;
}

