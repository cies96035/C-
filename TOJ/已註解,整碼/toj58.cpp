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
        cin>>S;//��J�X���ݩ� 
        char Attributes[S];
        for(int s=0;s<S;s++)cin>>Attributes[s];//��J�U���ݩ� 
        
        cin>>M>>N;//���M��,���CN�� 
        char k[M][N];
        for(int m=0;m<M;m++)//��J�L�� 
        {
            for(int n=0;n<N;n++)cin>>k[m][n];
        }
        
        //�ˬd��� 
        for(int m=0;m<M&&!goout;m++)//�ѲĤ@���ˬd��̫�@�� 
        {
            for(int n=0;n<N-2&!goout;n++)//��0�C�ˬd��n�C 
            {
                for(int s=0;s<S&&!goout;s++)
                {
                	//�T����۳s�B����X���ݩʡA���� 
                    if(k[m][n]==k[m][n+1]&&k[m][n]==k[m][n+2]&&k[m][n]==Attributes[s])
                    {
                    cout<<"Attack!"<<endl;
                    goout=1;
                    }
                }
            }
        }
        //�ˬd����
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
        //�p�G�S�����L�ALoser 
        if(!goout)cout<<"Loser!"<<endl;
    } 
return 0;
}
