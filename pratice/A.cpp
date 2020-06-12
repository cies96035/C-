#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int maxN=10010;
int N,Max,t;
int arr[maxN],l[maxN],r[maxN];//¼Æ­È¡A¥ªLIS¡A¥kLIS 

void LISl()
{
	vector<int> v;
	v.push_back(arr[0]);
	l[0]=1;
	for(int i=1;i<N;i++)
	{
		if((t=arr[i])>v.back())
			v.push_back(t);
		else
			*lower_bound(v.begin(),v.end(),t)=t;
		l[i]=v.size();
	}
} 
void LISr()
{
	vector<int> v;
	v.push_back(arr[(t=N-1)]);
	r[t]=1;
	Max=1;
	for(int i=t;i>=0;i--)
	{
		if((t=arr[i])>v.back())
			v.push_back(t);
		else
			*lower_bound(v.begin(),v.end(),t)=t;	
		r[i]=v.size();
        if(min(l[i],r[i])>Max)Max=min(l[i],r[i]);
	}
} 

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    while(cin>>N)
    {
        for(int i=0;i<N;i++)
            cin>>arr[i];
        LISl();
        LISr();
        cout<<(Max<<1)-1<<'\n';
    }
    return 0;
}
