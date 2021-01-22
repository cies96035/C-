#include<iostream>
#include<cstring>
using namespace std;
#define Mn 1000000
int arr[Mn];

bool SwapAndTest(int x, int y, int n)
{
    int tmp[n];
    bool isswap = 0;
    memcpy(tmp, arr, sizeof(int) * n);
    swap(tmp[x], tmp[y]);
    
    for(int i = 1; i < n; i++)
        tmp[i] -= tmp[i - 1];

    if(tmp[n - 1] != 0)
        return false;
    return true;
}

bool BeginRemove(int n)
{
    int tmp[n];
    memcpy(tmp, arr, sizeof(int) * n);
    for(int i = 1; i < n; i++)
    {
        if( tmp[i - 1] > tmp[i])
            return SwapAndTest(i - 1, i, n);
        tmp[i] -= tmp[i - 1];
    }
    return false;
}
bool EndRemove(int n)
{
    int tmp[n];
    memcpy(tmp, arr, sizeof(int) * n);
    for(int i = n - 2; i >= 0; i--)
    {
        if( tmp[i + 1] > tmp[i])
            return SwapAndTest(i + 1, i, n);
        tmp[i] -= tmp[i + 1];
    }
    return false;
}
void submin(int n)
{
    int min = 2e9;
    for(int i = 0; i < n; i++)
        if(min > arr[i])
            min = arr[i];
    for(int i = 0; i < n; i++)
        arr[i] -= min - (n % 2);
}
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    int T, n;
    cin>>T;
    while(T--)
    {
        cin>>n;
        for(int i=0;i<n;i++)
            cin>>arr[i];
        submin(n);
        if(BeginRemove(n) || EndRemove(n) || SwapAndTest(0, 0, n))
        {
            cout<<"YES\n";
        }
        else
        {
            cout<<"NO\n";
        }
        cout<<flush;
    }
    return 0;
}