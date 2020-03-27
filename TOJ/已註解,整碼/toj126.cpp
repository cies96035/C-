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
    
    bool canbescore[(maxscore*2)+1][N+1];//���t��+�s 
    const int Zero=maxscore;//�}�C�������N��s 
    
    memset(canbescore,0,sizeof(canbescore));
    canbescore[Zero][0]=1; 
    
    for(int i=0;i<N;i++)//�B�z���i����� 
    {
    	//�C����Ʊ��L�@�� 
    	//��_�q�Y������A���p�u�����i��X�{1���d��N�n 
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
        //���Ĥ@��>=T��1 
        while(!canbescore[T+Zero][N])
            T++;
        cout<<T<<endl;
    }
    return 0;
}
