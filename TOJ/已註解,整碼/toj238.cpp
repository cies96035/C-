#include<iostream>
#include<cstring>
#include<queue>
using namespace std;

int main() {
	
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    int N,Min,Max,a,b,l;
    cin>>N>>Min>>Max;
    int link[N][N],chicken[N];
    bool visited[N];
    queue<int> togo;
    memset(link,0,sizeof(link));
    memset(visited,0,sizeof(visited));
    memset(chicken,0,sizeof(chicken));
    
    for(int h=0;h<N-1;h++)
    {
        cin>>a>>b>>l;
        link[a][b]=link[b][a]=l;//a往b或b往a會有l隻小雞 
    }
    
    togo.push(0);
    visited[0]=1;
    while(!togo.empty())
    {
        int local=togo.front();
        togo.pop();
        for(int i=0;i<N;i++)
        {
        	//如果路上有小雞，且沒經過此點(不往回走，
			//且到達目的地後的小雞數量不超過Max(小雞沒有負的，超過後也沒辦法在達成條件了 
            if(link[local][i]>0&&!visited[i]&&chicken[local]+link[local][i]<=Max)
            {
                togo.push(i);
                visited[i]=1;
                chicken[i]=chicken[local]+link[local][i];
				//目的地的小雞數量=起點小雞數量+路上的小雞數量 
				
                if(chicken[i]>=Min)//如果超過最小值就可以吃 
                {
                    cout<<"Eat Eat Eat\n";
                    return 0;
                }
            }
        }
    }
    cout<<"Go find other chickens\n";
    return 0;
}
