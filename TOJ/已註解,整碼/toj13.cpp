#include<iostream>
#include<cstring>
using namespace std;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    int V,n;
    while(cin>>V>>n)
    {
        int w[n],p[n],maxvalue[V+1];
        
        //maxvalue紀錄體積為i的時候，最大價值為多少，預設為0 
        memset(maxvalue,0,sizeof(maxvalue));
        
        //輸入每個物品的體積價值 
        for(int h=0;h<n;h++)
			cin>>w[h]>>p[h];
        
		for(int i=0;i<n;i++)//每個物品跑一次 
            for(int j=w[i];j<=V;j++)//小於該物體體積的都不更新 
            	if(maxvalue[j-w[i]]+p[i]>maxvalue[j])//如果更新後比較高價值，更新 
            		maxvalue[j]=maxvalue[j-w[i]]+p[i];
            		
        cout<<maxvalue[V]<<'\n';
    }
    return 0;
}
