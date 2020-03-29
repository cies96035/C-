#include<iostream>
using namespace std;

#define LUC(i) (i*4-2)//���W 
#define RUC(i) (i*4-1)//�k�W 
#define LDC(i) (i*4)  //���U 
#define RDC(i) (i*4+1)//�k�U 
#define midx (lx+rx)/2//������������ 
#define midy (uy+dy)/2//������������ 

int n,m,q,num[3100][3100];
int x1,x2,y1,y2;
long long Ans;
int xx,yy,k;

//�x�s�M�A�Ŷ�:(log2���)^4 
unsigned int sum[223696213];

//�ت�:(�{�b�y��,�����,�k���,�W���,�U���) 
void build(int ID,int lx,int rx,int uy,int dy)
{
	//�p�G�W�U��ɡA���k��ɬ۵��A�ѤU�@��A�����U�ӡA���A���j 
    if(lx==rx&&uy==dy)
    {
        sum[ID]=num[lx][uy];
        return; 
    }
    //�p�G���k��ɬ۵�(����������)->���j�q����������� 
    else if(lx==rx)
    {
        build(LUC(ID),lx,rx,uy,midy);
        build(LDC(ID),lx,rx,midy+1,dy);
    }
    //�p�G�W�U��ɬ۵�(����������)->���j�q����������b 
    else if(uy==dy)
    {
        build(LUC(ID),lx,midx,uy,dy);
        build(RUC(ID),midx+1,rx,uy,dy);
    }
    //�p�G�����۵��A�����|�����U���j 
    else
    {
        build(LUC(ID),lx,midx,uy,midy);
        build(LDC(ID),lx,midx,midy+1,dy);
        build(RUC(ID),midx+1,rx,uy,midy);
        build(RDC(ID),midx+1,rx,midy+1,dy);
    }
    //�������j��A�o��|�Ө������`�M�A�A�ۥ[�N�����d���`�M 
    sum[ID]=sum[LUC(ID)]+sum[LDC(ID)]+sum[RUC(ID)]+sum[RDC(ID)];
}

//�{�b��m,�����,�k���,�W���,�U��� 
void query(int ID,int lx,int rx,int uy,int dy)
{
	//��ID�P�j���d��S���涰�A���}�j�� 
    if(x2<lx||rx<x1||y2<uy||dy<y1)return;
    if((x1<=lx&&rx<=x2)&&(y1<=uy&&dy<=y2))//��ID�����b�j���d�򤺡A�i��[�` 
    {
        Ans+=sum[ID];
        return;
    }
    //�p�G���涰�A�����|�����U���j�A����->�����S�涰or�����]�t 
    query(LUC(ID),lx,midx,uy,midy);
    query(RUC(ID),midx+1,rx,uy,midy);
    query(LDC(ID),lx,midx,midy+1,dy);
    query(RDC(ID),midx+1,rx,midy+1,dy);
}

//�N�Ҧ��]�t�n���ܦ�m��ID���ק�A�é��U���j 
void change(int ID,int lx,int rx,int uy,int dy)
{
	//��s�� 
	sum[ID]+=k-num[xx][yy];
	
    if(lx==rx&&uy==dy)//�쩳���F�A�������j 
        return;
        
    else if(xx<=midx&&yy<=midy)
        change(LUC(ID),lx,midx,uy,midy);
    else if(xx>midx&&yy<=midy)
        change(RUC(ID),midx+1,rx,uy,midy);
    else if(xx<=midx&&yy>midy)
        change(LDC(ID),lx,midx,midy+1,dy);
    else if(xx>midx&&yy>midy)
        change(RDC(ID),midx+1,rx,midy+1,dy);
    return;
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin>>n>>m;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin>>num[i][j];
    
    //�ت� 
    build(1,0,n-1,0,m-1);
    
    cin>>q;
    while(q--)
    {
        char ask;
        cin>>ask;
        if(ask=='Q')
        {
            cin>>x1>>y1>>x2>>y2;
            x1--,x2--,y1--,y2--,Ans=0;//�C���^�����n��l��Ans 
            query(1,0,n-1,0,m-1);
            cout<<Ans<<'\n';
        }
        else if(ask=='C')
        {
            cin>>xx>>yy>>k;
            xx--,yy--;
            change(1,0,n-1,0,m-1);
            num[xx][yy]=k;
        }
    }
    return 0;
}
