//¥~±¾= = 

#include<iostream>
#include<algorithm>
#include<iomanip>
using namespace std;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cout<<fixed<<setprecision(6);
    int n;
    cin>>n;
    int num[n];
    long double ans=0;
    for(int i=0,j=1;i<n;i++,j++)
    {
        cin>>num[i];
        
        if(i%2)
        {
        	nth_element(num,num+i/2,num+j);
        	ans=num[i/2];
        	nth_element(num,num+i/2+1,num+j);
        	ans+=num[i/2+1];
        	ans/=2;
		}
		else
		{
			nth_element(num,num+i/2,num+j);
			ans=num[i/2];
		}
        cout<<ans<<'\n';
    }
    return 0;
}
