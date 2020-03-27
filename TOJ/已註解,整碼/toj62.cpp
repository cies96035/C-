#include<iostream>
#include<cstring>
#include<queue>
using namespace std;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
    int T;
    cin>>T;
    while(T--)
    {
        int disk[5][6],combo=0,table[5][6];
		bool findcombo=1;
        memset(table,0,sizeof(table));
        
        for(int i=0;i<5;i++)//輸入版面 
            for(int j=0;j<6;j++)
                cin>>disk[i][j];
        
        while(findcombo)//直到沒找到combo，也就是盤面沒有三連珠的時候 
        {
            findcombo=0;
            for(int i=0;i<5;i++)//找三連珠，並把相連的屬性紀錄再table 
                for(int j=0;j<6;j++)
                {
                    if(i<3&&disk[i][j]==disk[i+1][j]&&disk[i][j]==disk[i+2][j]&&disk[i][j]>0)//直排三連 
                    {
                        table[i][j]=table[i+1][j]=table[i+2][j]=disk[i][j];
                        findcombo=1;
                    }
                    if(j<4&&disk[i][j]==disk[i][j+1]&&disk[i][j]==disk[i][j+2]&&disk[i][j]>0)//橫排3連 
                    {
                        table[i][j]=table[i][j+1]=table[i][j+2]=disk[i][j];
                        findcombo=1;
                    }
                }
            
            //如果這個地方有消到，則把消到的地方變成0(不可用)
            //且把0移至盤面最上層(相對來說可用的會跑到下層 
            for(int i=0;i<5;i++)
                for(int j=0;j<6;j++)
                    if(table[i][j]>0)
                    {
                        disk[i][j]=0;
                        for(int ii=i;ii>0;ii--)swap(disk[ii][j],disk[ii-1][j]);
                    }
            
            for(int i=0;i<5;i++)
                for(int j=0;j<6;j++)
                    if(table[i][j]>0)//代表有combo 
                    {
                        queue<int> togox,togoy;
                        togox.push(i);
                        togoy.push(j);
                        int p=table[i][j];//這個combo的屬性 
						//用BFS把跟這個combo相同屬型的都移除，避免多算 
                        while(!togox.empty())
                        {
                            int wx=togox.front(),wy=togoy.front();
                            table[wx][wy]=0;//屬性歸0(不可用 
                            togox.pop();
                            togoy.pop();
                            if(wx<4&&table[wx+1][wy]==p)
                            {
                                togox.push(wx+1);
                                togoy.push(wy);
                            }
                            if(wx>0&&table[wx-1][wy]==p)
                            {
                                togox.push(wx-1);
                                togoy.push(wy);
                            }
                            if(wy<5&&table[wx][wy+1]==p)
                            {
                                togox.push(wx);
                                togoy.push(wy+1);
                            }
                            if(wy>0&&table[wx][wy-1]==p)
                            {
                                togox.push(wx);
                                togoy.push(wy-1);
                            }
                        }
                        combo++;
                    }
            memset(table,0,sizeof(table));//記錄盤重置 
        }
        cout<<combo<<endl;
    }
    return 0;
}
