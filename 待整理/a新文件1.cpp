#include<iostream>
using namespace std;
/* overload 有空再試 
template<typename T, size_t N>
ostream& operator <<(ostream& output,const T (&arr)[N])
{
	if(arr[N])output<<arr[N];
	for(int i=N-1;i>=0;i--)
		output<<arr[i];
	return output;
}
*/
int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	int n,a;
	cin>>n>>a;
	int num[n+1];
	num[n]=0;
	for(int i=0;i<n;i++)
		num[i]=(n-i)*a;
	for(int i=0;i<n;i++)
	{
		if(num[i]>9)
		{
			num[i+1]+=num[i]/10;
			num[i]%=10;
		} 
	}
	if(num[n])cout<<num[n];
	for(int i=n-1;i>=0;i--)
		cout<<num[i];
	cout<<'\n';
	return 0;
}
