#include<iostream>
using namespace std;
int main()
{
    int T;
    while(cin>>T)
    {
        int n[T],ans=0,min=0;
        for(int m=0;m<T;m++)cin>>n[m];
        for(int m=0;m<T;m++)
        {
            int ans=0;
            for(int h=m-1;h>=0;h--)
            {
                if(n[h]<n[m])ans++;
                else break;
            }
            if(m!=T-1)cout<<ans<<" ";
            else cout<<ans<<endl;
        }
    }
    return 0;
}
