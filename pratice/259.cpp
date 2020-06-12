#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
const int maxN=10010;
int N,tmp;
int arr[maxN],l[maxN],r[maxN];//�ƭȡA��LIS�A�kLIS 

void LIS()//��0~i��LIS�s��l[i],i~N���fLIS�s��r[i]
{
	vector<int> v1,v2;
	
	v1.push_back(arr[0]);
	v2.push_back(arr[(tmp=N-1)]);
	l[0]=r[tmp]=1;
	
	for(int i=1,j=tmp-1;i<N;i++,j--)
	{
		//���ol[i] 
		if((tmp=arr[i])>v1.back())
			v1.push_back(tmp);
		else
			*lower_bound(v1.begin(),v1.end(),tmp)=tmp;
		l[i]=v1.size();
		
		//���or[i] 
		if((tmp=arr[j])>v2.back())
			v2.push_back(tmp);
		else
			*lower_bound(v2.begin(),v2.end(),tmp)=tmp;	
		r[j]=v2.size();
	}
}

int getans()//ans��0~i��LIS�Mi~N���fLIS�A�䤤�̤j��i 
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
