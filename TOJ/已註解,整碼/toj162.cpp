#include<iostream>
#include<cstring>
using namespace std;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
    int T;
    cin>>T;
    while(T--)
    {
        cin.ignore();//�Y��\n�A���MŪ����W�l 
        string PlayerX,PlayerO;//�x�s�W�l 
        int OOXX[3][3];
		bool getscoreX=0,getscoreO=0;
        getline(cin,PlayerX);
        getline(cin,PlayerO);
        
        /* ��J
        00 01 02
        10 11 12
        20 21 22
        */ 
        for(int i=0;i<3;i++)
            for(int j=0;j<3;j++)
                cin>>OOXX[i][j];
             
        //�P�_����O�_�ۦP�A�P�ɧP�_�ֱo�� 
        for(int x=0;x<3;x++)
            if(OOXX[0][x]==OOXX[1][x]&&OOXX[0][x]==OOXX[2][x]&&OOXX[0][x]!=2)
                OOXX[0][x]?getscoreX=1:getscoreO=1;//�s�u���O1�AX�o��,�_�hY�o�� 
                
        //�P�_���O�_�ۦP�A�ۦP�ɧP�_�ֱo��
        for(int y=0;y<3;y++)
            if(OOXX[y][0]==OOXX[y][1]&&OOXX[y][0]==OOXX[y][2]&&OOXX[y][0]!=2)
                OOXX[y][0]?getscoreX=1:getscoreO=1;
        
        
        //�P�_���W�k�U�צ�O�_�ۦP�A�ۦP�ɧP�_�ֱo��
        if(OOXX[0][0]==OOXX[1][1]&&OOXX[0][0]==OOXX[2][2]&&OOXX[0][0]!=2)
            OOXX[0][0]?getscoreX=1:getscoreO=1;
        
        //�P�_�k�W���U�צ�O�_�ۦP�A�ۦP�ɧP�_�ֱo��
        if(OOXX[0][2]==OOXX[1][1]&&OOXX[0][2]==OOXX[2][0]&&OOXX[0][2]!=2)
            OOXX[0][2]?getscoreX=1:getscoreO=1;
        
        //�P�_�o�����p 
        if(!getscoreX&&!getscoreO)cout<<"Not yet"<<endl;//�p�G���S�o�L�� 
        else if(getscoreO&&getscoreX)cout<<"Impossible"<<endl;//�p�G��ӳ����o�� 
        else if(getscoreX)cout<<PlayerX<<endl;//�u��X�o�� 
        else cout<<PlayerO<<endl;//�u��O�o�� 
    }
    return 0;
}
