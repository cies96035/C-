#include<iostream>
#include<queue>
#include<cstring>
using namespace std;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    int N,M,x,y; 
    queue<int> togox,togoy;//�ݫe����x,y��C 
    
    cin>>N>>M;//�g�c�j�p 
    
    bool migon[N][M];//�����g�c�O�_�i�� 
    int ans[N][M];//������F�g�c���Y�Ӧ�m�ɡA�L�����I���̪�Z�� 
    memset(ans,0,sizeof(ans)); 
    
    for(int i=0;i<N;i++)
        for(int j=0;j<M;j++)
            cin>>migon[i][j];

    cin>>x>>y;
    togox.push(x);//��_�I��i�n�e������C 
    togoy.push(y);
    cin>>x>>y;//�������I��m 
    while(!togox.empty())//����S���a���h���� 
    {
        //�{�b���I x,y�y�� 
        int wx=togox.front(),wy=togoy.front();
        togox.pop();
        togoy.pop();
        if(wx==x&&wy==y)//�p�G��F���I�A��X���I���̨θ��| 
        {
            cout<<ans[wx][wy]<<"\n";
            return 0;//�����{�� 
        }
        
        //�p�G���U���I�S�W�X�g�c�d��A�åB�i�H�� 
        if(wx+1<N&&migon[wx+1][wy]==0)//�U 
        {
            togox.push(wx+1);//��o�Ӧ�m��i�h�n�h����C 
            togoy.push(wy);
            migon[wx+1][wy]=1;//��o���I�аO��1(�]�N�O���|�A�i�ӤF) 
            ans[wx+1][wy]=ans[wx][wy]+1;//���I�̨θ��|���W�I�̨θ��|+1 
        } 
        if(wx-1>-1&&migon[wx-1][wy]==0)//�W 
        {
            togox.push(wx-1);
            togoy.push(wy);
            migon[wx-1][wy]=1;
            ans[wx-1][wy]=ans[wx][wy]+1;
        } 
        if(wy-1>-1&&migon[wx][wy-1]==0)//�� 
        {
            togox.push(wx);
            togoy.push(wy-1);
            migon[wx][wy-1]=1;
            ans[wx][wy-1]=ans[wx][wy]+1;
        } 
        if(wy+1<M&&migon[wx][wy+1]==0)//�k 
        {
            togox.push(wx);
            togoy.push(wy+1);
            migon[wx][wy+1]=1;
            ans[wx][wy+1]=ans[wx][wy]+1;
        }
    }
    cout<<"-1\n";//�L�k��F���I 
    return 0;
}
