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
        link[a][b]=link[b][a]=l;//a��b��b��a�|��l���p�� 
    }
    
    togo.push(0);
    visited[0]=1;
    while(!togo.empty())
    {
        int local=togo.front();
        togo.pop();
        for(int i=0;i<N;i++)
        {
        	//�p�G���W���p���A�B�S�g�L���I(�����^���A
			//�B��F�ت��a�᪺�p���ƶq���W�LMax(�p���S���t���A�W�L��]�S��k�b�F������F 
            if(link[local][i]>0&&!visited[i]&&chicken[local]+link[local][i]<=Max)
            {
                togo.push(i);
                visited[i]=1;
                chicken[i]=chicken[local]+link[local][i];
				//�ت��a���p���ƶq=�_�I�p���ƶq+���W���p���ƶq 
				
                if(chicken[i]>=Min)//�p�G�W�L�̤p�ȴN�i�H�Y 
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
