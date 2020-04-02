#include<iostream>
#include<cstring>
using namespace std;

const int N=65565;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    /*
	因為陣列的引數不可小於零
	將num[N]視為num[0]
	num[0]視為num[-N]
	*/
    int T,t,x,num[2*N+1],min=N*2,max=0;
    memset(num,0,sizeof(num));
    cin>>T;
    while(T--)
    {
        cin>>t;
        while(t--)
        {
            cin>>x;
            num[N+x]++;
            if(x+N>max)max=N+x;
            if(x+N<min)min=N+x;
        }
        cout<<max-min<<'\n';          
        num[max]--;//用掉一次
        num[min]--;//用掉一次
		//暴力更新最大及最小值
        while(!num[max])max--; 
        while(!num[min])min++;
    }
    return 0;
}

