#include<iostream>
#include<algorithm> 
using namespace std;

#define maxk 1000001
#define maxM 3000001

struct link
{
    //�s���Ia�Ib��������w 
    int a,b,W;
}Link[maxM];

//�̷Ӧ����Ѥp�ƨ�j 
bool cmp(link x,link y){return x.W<y.W;}

int division[maxk];//�C���I������ 

//��l�ơA�C���I�ۤv�@�� 
void Init(int k){for(int i=1;i<=k;i++)division[i]=i;} 
//�M���Ia���էO 
int find(int a){return division[a]==a ? a : division[a]=find(division[a]);}
//�Na,b���I���էO�X�֬�b�էO 
void Union(int a,int b){division[find(a)]=find(b);}
//�P�_����I���էO�O�_�@�� 
bool same(int a,int b){return find(a)==find(b);}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    int T;
    cin>>T;
    while(T--)
    {
        int N,M,c,d,ans=0;
        cin>>N>>M;
        Init(N);
        for(int i=0;i<M;i++)
        {
            cin>>Link[i].a>>Link[i].b>>c>>d;
            Link[i].W=c-d; 
        }
        sort(Link,Link+M,cmp);
        for(int i=0;i<M;i++)
        {
            //�����ɤ����� 
			//���D�L�سy����Ȩ���N�سy�A�ϥ��ضV�h�����V�p 
            if(same(Link[i].a,Link[i].b)&&Link[i].W>0)continue;
            
            //�سy����:�X�ָӳs�����I 
            Union(Link[i].a,Link[i].b);
            
            //�N���䦨���[�i�h 
            ans+=Link[i].W;
        }
        cout<<ans<<'\n';
    }
    return 0;
}
