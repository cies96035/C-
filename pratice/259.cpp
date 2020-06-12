#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
const int maxN=10010;
int N,tmp;
int arr[maxN],l[maxN],r[maxN];//數值，左LIS，右LIS 

void LIS()//把0~i的LIS存到l[i],i~N的逆LIS存到r[i]
{
	vector<int> v1,v2;
	
	v1.push_back(arr[0]);
	v2.push_back(arr[(tmp=N-1)]);
	l[0]=r[tmp]=1;
	
	for(int i=1,j=tmp-1;i<N;i++,j--)
	{
		//取得l[i] 
		if((tmp=arr[i])>v1.back())
			v1.push_back(tmp);
		else
			*lower_bound(v1.begin(),v1.end(),tmp)=tmp;
		l[i]=v1.size();
		
		//取得r[i] 
		if((tmp=arr[j])>v2.back())
			v2.push_back(tmp);
		else
			*lower_bound(v2.begin(),v2.end(),tmp)=tmp;	
		r[j]=v2.size();
	}
}

int getans()//ans為0~i的LIS和i~N的逆LIS，其中最大的i 
{
	int ans=1;
	for(int i=0;i<N;i++)
		if(min(l[i],r[i])>ans)ans=min(l[i],r[i]);
	return (ans<<1)-1;
} 

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    while(cin>>N)
    {
        for(int i=0;i<N;i++)
            cin>>arr[i];
        LIS();
        cout<<getans()<<'\n';
    }
    return 0;
}
