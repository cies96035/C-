#include<iostream>
using namespace std;
#define Mn 1000000
typedef long long ll;
ll arr[Mn],arr2[Mn];
void Print(int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<' ';
    }
    cout<<endl;
}
void Print2(int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<arr2[i]<<' ';
    }
    cout<<endl;
}
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    int t,n;
    cin>>t;
    while(t--)
    {
        bool F=0;
        bool flg=1;
        cin>>n;
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
            arr2[i]=arr[i];
        }
        for(int i=1;i<n;i++)
        {
            if(arr[i-1]>arr[i] && !F)
            {
                swap(arr[i-1],arr[i]);
                F=1;
            }
            arr[i]-=arr[i-1];
            arr[i-1]=0;
            //Print(n);
        }
        F=0;
        for(int i=n-1;i>0;i--)
        {
            if(arr2[i]>arr2[i-1] && !F)
            {
                F=1;
                swap(arr2[i-1],arr2[i]);
            }
            //Print2(n);
            arr2[i-1]-=arr2[i];
            arr2[i]=0;
            //Print2(n);
        }
        if(arr[n-1]==0 || arr2[0] == 0)
        {
            cout<<"YES\n";
        }
        else
        {
            cout<<"NO\n";
        }
        
    }
    return 0;
}