#include<iostream>
#include<cstring>
using namespace std;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
    int N,Q;
    cin>>N>>Q;
    int score[N],maxscore=0,upscore=0;
    
    for(int i=0;i<N;i++)
    {
        cin>>score[i];
        maxscore+=score[i];
    }
    
    bool canbescore[(maxscore*2)+1][N+1];//正負數+零 
    const int Zero=maxscore;//陣列的中間代表零 
    
    memset(canbescore,0,sizeof(canbescore));
    canbescore[Zero][0]=1; 
    
    for(int i=0;i<N;i++)//處理到第i筆資料 
    {
    	//每筆資料掃過一次 
    	//比起從頭掃到尾，不如只掃有可能出現1的範圍就好 
        for(int j=Zero-upscore,end=Zero+upscore;j<=end;j++)
        {
            if(canbescore[j][i])
                canbescore[j+score[i]][i+1]=canbescore[j-score[i]][i+1]=1;
        }
        upscore+=score[i];
    }
    
    while(Q--)
    {
        int T;
        cin>>T;
        //找到第一個>=T的1 
        while(!canbescore[T+Zero][N])
            T++;
        cout<<T<<endl;
    }
    return 0;
}
