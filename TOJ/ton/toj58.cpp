#include<iostream>
using namespace std;
int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
    int T;
    cin>>T;
    for(int t=0;t<T;t++)
    { 
        int S,M,N,goout=0; 
        cin>>S;//輸入幾種屬性 
        char Attributes[S];
        for(int s=0;s<S;s++)cin>>Attributes[s];//輸入各種屬性 
        
        cin>>M>>N;//橫排M個,直列N個 
        char k[M][N];
        for(int m=0;m<M;m++)//輸入盤面 
        {
            for(int n=0;n<N;n++)cin>>k[m][n];
        }
        
        //檢查橫排 
        for(int m=0;m<M&&!goout;m++)//由第一排檢查到最後一排 
        {
            for(int n=0;n<N-2&!goout;n++)//第0列檢查到n列 
            {
                for(int s=0;s<S&&!goout;s++)
                {
                	//三顆橫的相連且為輸出的屬性，攻擊 
                    if(k[m][n]==k[m][n+1]&&k[m][n]==k[m][n+2]&&k[m][n]==Attributes[s])
                    {
                    cout<<"Attack!"<<endl;
                    goout=1;
                    }
                }
            }
        }
        //檢查直排
        for(int n=0;n<N&&!goout;n++)
        {
            for(int m=0;m<M-2&!goout;m++)
            {
                for(int s=0;s<S&&!goout;s++)
                {
                    if(k[m][n]==k[m+1][n]&&k[m][n]==k[m+2][n]&&k[m][n]==Attributes[s])
                    {
                    cout<<"Attack!"<<endl;
                    goout=1;
                    }
                }
            }
        }
        //如果沒攻擊過，Loser 
        if(!goout)cout<<"Loser!"<<endl;
    } 
return 0;
}
