#include<iostream>
#include<cstring>
using namespace std;

int main() {
    int Sx,Sy,Ex,Ey;
    //N,M�S�� 
    cin>>Sx>>Sx>>Sx>>Sy>>Ex>>Ey;
    //�u�੹�U���k�A�p�G�X�{�o�ت��p�N�줣�F 
    if(Sy>Ey||Sx>Ex)
    {
        cout<<0<<endl;
        return 0;
    }
    int x=Ex-Sx,y=Ey-Sy;//x,y���� 
    int migon[x+1][y+1];//�����q�_�I��Y�I���X�ب��k 
    memset(migon,0,sizeof(migon));
    for(int i=0;i<=x;i++)migon[i][0]=1;//�_�I���k���u���@�ب��k 
    for(int i=0;i<=y;i++)migon[0][i]=1;//�_�I���U�]���u���@�ب��k 
    for(int i=1;i<=x;i++)
    {
        for(int j=1;j<=y;j++)
        {
			//���樫�k�`�M=�q���W��+�q����+�q�W�� 
            migon[i][j]=migon[i-1][j-1]+migon[i-1][j]+migon[i][j-1];
        }
    }
    //��X�ؼЦ�m�����k�`�M 
    cout<<migon[x][y]<<endl;
    return 0;
}
