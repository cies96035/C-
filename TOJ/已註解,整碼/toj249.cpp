#include<iostream>
using namespace std;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n,num;
    cin>>n>>num;
    n--;
	long long sum=num,ans=num;
	//預設ans及sum為第一個數而非0
	//避免全負數而答案為0的狀況(題目至少要取一個) 
    while(n--)
    {
        cin>>num;
        sum+=num;
        if(sum>ans)ans=sum;
		//紀錄連續總和最大值 
        if(sum<0)sum=0;
        //如果連續總和<0，則前面就不取了
		//因為 -sum + num < num 必成立 
    }
    cout<<ans<<'\n';
    //輸出答案 
}
 
