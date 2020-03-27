#include<iostream>
#include<algorithm> 
using namespace std;

#define maxk 1000
#define maxM 500000

struct link
{
	//i��j��������w 
	int a,b,W;
}Link[maxM];

//�̷Ӧ����Ѥp�ƨ�j 
bool cmp(link x,link y){return x.W<y.W;}

int division[maxk];//�C���I������ 

//��l�ơA�C���I�ۤv�@�� 
inline void Init(int k){for(int i=0;i<k;i++)division[i]=i;} 
//�M��a���էO 
inline int find(int a){return division[a]==a ? a : division[a]=find(division[a]);}
//�Na,b���I���էO�X�֬�b�էO 
inline void Union(int a,int b){division[find(a)]=find(b);}
//�P�_��ӤH���էO�O�_�@�� 
inline bool same(int a,int b){return find(a)==find(b);}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    int k,R,ans=0;
    bool can=1;
    cin>>k>>R;
    Init(k);
    for(int i=0;i<R;i++)
    {
    	cin>>Link[i].a>>Link[i].b>>Link[i].W; 
	}
	sort(Link,Link+R,cmp);
    for(int i=0;i<R;i++)
    {
    	//�����ɤ����� 
    	if(same(Link[i].a,Link[i].b))continue;
    	//�L���ɨ֤@�� 
    	Union(Link[i].a,Link[i].b);
    	//�N������O�[�i�h 
    	ans+=Link[i].W;
    }
    
    for(int i=1;i<k;i++)
    {
    	if(same(division[i],division[i-1]))continue;
    	can=0;
    	break;
	}
	if(can)
    	cout<<ans<<endl;
    else
    	cout<<-1<<endl;
    
    return 0;
}
