#include<iostream>
#include<cstring>
using namespace std;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    int N,P,C,t,u;
    cin>>N>>P>>C;
    bool k[14],flag=0;
    int tree[P];
    memset(tree,0,sizeof(tree));
    memset(k,0,sizeof(k));
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<P;j++)
        {
            cin>>t;
            tree[j]+=t;
        }
    }
    for(int i=0;i<P;i++)
    {
    	//�Ni����������ର�G�i��t
    	//��G�i��t����u��A�p�Gk[u]�O1�A�ܬ�0�A�O0�A��1 
        t=tree[i],u=0;
        while(t)
        {
            if(t%2)
            {
                k[u]=!k[u];
            }
            t/=2;
            u++;
        }
    }
    //�P�_�{���q�O�w���ݧ��A�Ϊ̤��O 
    for(int i=0;i<14;i++)if(k[i]==1)flag=1;
    
    //�p�G�O���O�w���ݧ��M�������Y 
    if((flag==1&&C==0)||(flag==0&&C==1))
        cout<<"Holly Win!"<<endl;
    else
        cout<<"Ivy Win!"<<endl;
        
    
    return 0;
}
