#include<iostream>
#include<queue>
using namespace std;

//22�إi�ೣ���ݡA��̤j�� 

typedef pair<int,int> pii;

#define in_range nxg[0]>=0&&nxg[0]<Lh&&nxg[1]>=0&&nxg[1]<Lw //�ɭ��P�w 

const int Lh=14,Lw=6,m[4][2]={{0,1},{1,0},{-1,0},{0,-1}};

char a,b,SC;//a��Ab��ASameColor 
string R_puyo[Lh],C_puyo[Lh];//Real/Copy
int vis[Lh][Lw],visid=0,Cvisid=0,maxCmb=0,ComboCnt;
bool haveclear;

bool FindFour(int x,int y)//��S�w�I�O�_���|�۳s 
{
    queue<pii> tg;
    tg.push(pii(x,y));//�_�I 
    SC=C_puyo[x][y];
    vis[x][y]=visid;
    
    int cnt=4;
    
    while(!tg.empty())
    {
        cnt--;
        if(!cnt)return true;//�ŦX��������A�^�� 
        for(int i=0;i<4;i++)
        {
            int nxg[2]={tg.front().first+m[i][0],tg.front().second+m[i][1]};
            if(in_range)
            {
                if(C_puyo[nxg[0]][nxg[1]]==SC&&vis[nxg[0]][nxg[1]]<visid)//�p�G�P���I�P��A�ӥB���h�S�i�L�h 
                {
                    tg.push(pii(nxg[0],nxg[1]));
                    vis[nxg[0]][nxg[1]]=visid;//�аO�i�L���h 
                }
            }
        }
        tg.pop();
    }
    return false;
}

void clear_puyo(int x,int y)//�����P�S�w�I�P�⪺���� 
{
    queue<pii> tg;
    tg.push(pii(x,y));//�_�I 
    vis[x][y]=Cvisid;//���L���аO
    
    while(!tg.empty())
    {
        C_puyo[tg.front().first][tg.front().second]='0';//����
        for(int i=0;i<4;i++)
        {
            int nxg[2]={tg.front().first+m[i][0],tg.front().second+m[i][1]};
            if(in_range)
            {
                if(C_puyo[nxg[0]][nxg[1]]==SC&&vis[nxg[0]][nxg[1]]!=Cvisid)//�p�G�P��A��J�ݮ����W�� 
                {
                    tg.push(pii(nxg[0],nxg[1]));
                    vis[nxg[0]][nxg[1]]=Cvisid;//�קK���^�Y�� 
                }
            }
        }
        tg.pop();
    }
}

void Cmb(int ay,int ax,int by,int bx)//�N���Puyo���ƻs�᪺�����A�åB�B��ݵ��G���Xcombo 
{
    for(int i=0;i<Lh;i++)//�NR�ƻs��C�A�åB�[�J����w��m 
        C_puyo[i]=R_puyo[i];
    C_puyo[ay][ax]=a;
    C_puyo[by][bx]=b;
    
    ComboCnt=0;//�p�⦹���ժ�Combo�� 
    haveclear=true;//�P�_�٦��S���i�H������
    while(haveclear)
    { 
        visid++;
        Cvisid--;
        haveclear=false;//�����]���h�S�������L 
        
        //1.����Ҧ��B�b�Ť����A���̩ܳ�
        for(int i=0;i<Lw;i++)
            for(int j=Lh-1,k=j-1;k>=0;j--,k--)
                if(C_puyo[j][i]=='0')//�p�G�O�Ū��A��̤U�����C�̤U����puyo��U�� 
                {
                    while(C_puyo[k][i]=='0'&&k>0)k--;
                    swap(C_puyo[k][i],C_puyo[j][i]);
                }
                
        
        //2.�j�M�O�_���|�s�]�A��->flg=1(�~��j��),�åBbfs�ĤG��->�����A������0 
        for(int i=Lh-1;i>0;i--)
            for(int j=0;j<Lw;j++)
                if(C_puyo[i][j]!='0'&&vis[i][j]<visid)//�p�G�o�榳puyo�A�ӥB�b�o�h�S���QBFS�L 
                {
                    if(FindFour(i,j))
                    {
                        haveclear=true;
                        clear_puyo(i,j);//�F��4�۳s�A�����Ӳ�puyo 
                    }
                }
        if(haveclear)                
            ComboCnt++;//�p�G���h������ 
    } 
    maxCmb=max(maxCmb,ComboCnt);//��s�̤jcombo�� 
    return;
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin>>a>>b;
    R_puyo[0]=R_puyo[1]="000000";//�w�d��� 
    for(int i=2;i<Lh;i++)
        cin>>R_puyo[i];
    
    //�C�Ӧ�m��puyo�����լݬ�
    for(int i=0;i<5;i++) 
    {
        Cmb(0,i,0,i+1);
        Cmb(0,i+1,0,i);
        Cmb(1,i,0,i);
        Cmb(0,i,1,i);
    }
    Cmb(0,5,1,5);
    Cmb(1,5,0,5);
    
    cout<<maxCmb<<'\n';
    return 0;
}
