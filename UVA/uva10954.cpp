#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int T;
    while(cin>>T&&T)
    {
        int* arr=new int[T];
        for(int i=0;i<T;i++)
            cin>>arr[i];
        sort(arr,arr+T);
        for(int i=0;i<T;i++)
            cout<<arr[i]<<endl;
        int sum=arr[0]+arr[1];
        int allsum=sum;
        for(int i=2;i<T;i++)
        {
            sum+=arr[i];
            allsum+=sum;
        }
        cout<<allsum<<'\n';
        delete arr;
    }
    return 0;
}