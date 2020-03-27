#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
    int T,M,N,S;
    cin>>T;
    for(int Case=1;Case<=T;Case++)
    {
    	//輸入幾個點，幾個連結，起點 
        cin>>N>>M>>S;
        
        /*
        //變數用途 
        High:各點高度
		far:紀錄原點到各點最近的距離(DP找出最低點最近距離
		walk:原點到最低點最近距離(無法到達則沒有值
		down:下坡車距離
		end:紀錄最低點高度(不用座標是因為可能有多個最低點 
		graph:雙向圖
		isgo:BFS紀錄已通過的點，避免走回頭路
		f1,f2:分別判斷走路和下坡車能不能到達 
		*/
		queue<int> togo;//BFS用到
        int High[N],far[N],walk,down=0,end=2e9;
        bool graph[N][N],isgo[N],f1=0,f2=1;
        //清空陣列 
        memset(graph,0,sizeof(graph));
        memset(isgo,0,sizeof(isgo));
        
        //輸入每個座標高度、雙向圖 
        for(int i=0;i<N;i++)
        {
            cin>>High[i];
            //紀錄最低點高度 
            if(end>High[i])
            {
                end=High[i];
            }
        }
        for(int i=0;i<M;i++)
        {
            int x,y;
            cin>>x>>y;
            graph[x][y]=graph[y][x]=1;
        }
        
        togo.push(S);//把起點放入搜尋佇列 
        isgo[S]=1;//把起點放入已探索名單 
        far[S]=0;//從起點到起點的距離為0 
        while(!togo.empty())//直到搜尋佇列空空為止 
        {
            int t=togo.front();
            togo.pop();
            //將搜尋佇列的第一個拿出來，開始搜尋相鄰的點 
            if(High[t]==end) 
            {
                //如果出現了第一個由起點連到最低點的路徑
                //則f1為1(走路可到達)，且距離為此最低點的far 
                f1=1;
                walk=far[t]*6;
                break;
            }
            for(int i=0;i<N;i++)
            {
                //把所有沒有走過並且相鄰的點，丟進搜尋佇列
                if(graph[t][i]&&!isgo[i])
                {
                    togo.push(i);
                    isgo[i]=1;
                    far[i]=far[t]+1;//紀錄起點到每個點的最短距離 
                    
                }
            }
        }
        
        //下坡車，用while直到高度到最低點才停止
        //理論上要用BFS(如果同時有兩個以上最低點，此程式只會到其中一個) 
        while(High[S]!=end)
        {
            /*
            min:紀錄最低點高度
            minid:記錄最低點id(下次從這裡出發)，初始值為-1(找不到跟出發點相連且比出發點低的點 
            */ 
            int min=High[S],minid=-1;
            
            //掃過每一個點，找出比出發點低最多的那個點，記錄下來 
            for(int i=0;i<N;i++)
            {
                if(graph[i][S]&&min>High[i])
                {
                    min=High[i];
                    minid=i;
                }
            }
            
            //如果與出發點相連的點都比較高，則跳開迴圈，並記錄下坡車無法到達 
            if(minid==-1)
            {
                f2=0;
                break;
            }
            
            //下次的出發點為這次的最低點 
            S=minid;
            //每下坡車一次，down就增加一次 
            down++;
        }
        
        
        //輸出部分 
        if(f1&&f2)
            cout<<"Case #"<<Case<<": "<<walk-down<<'\n';
        else if(f1)
            cout<<"Case #"<<Case<<": "<<walk<<'\n';
        else
            cout<<"Case #"<<Case<<": Call 119!\n";
    }
    return 0;
}
