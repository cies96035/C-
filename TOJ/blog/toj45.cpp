#include<iostream>
#include<cstring>
using namespace std;

const int N=65565;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    /*
	num纗–计瞷Ω计
	皚ぃノ璽计┮﹚竡num[N]0 
	min玥琌+65565,max琌-65565 
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
        num[max]--;
        num[min]--;
        //讽程┪程ノЧт程程 
        while(!num[max])max--; 
        while(!num[min])min++;
    }
    return 0;
}

