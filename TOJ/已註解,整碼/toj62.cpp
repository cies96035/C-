#include<iostream>
#include<cstring>
#include<queue>
using namespace std;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
    int T;
    cin>>T;
    while(T--)
    {
        int disk[5][6],combo=0,table[5][6];
		bool findcombo=1;
        memset(table,0,sizeof(table));
        
        for(int i=0;i<5;i++)//��J���� 
            for(int j=0;j<6;j++)
                cin>>disk[i][j];
        
        while(findcombo)//����S���combo�A�]�N�O�L���S���T�s�]���ɭ� 
        {
            findcombo=0;
            for(int i=0;i<5;i++)//��T�s�]�A�ç�۳s���ݩʬ����Atable 
                for(int j=0;j<6;j++)
                {
                    if(i<3&&disk[i][j]==disk[i+1][j]&&disk[i][j]==disk[i+2][j]&&disk[i][j]>0)//���ƤT�s 
                    {
                        table[i][j]=table[i+1][j]=table[i+2][j]=disk[i][j];
                        findcombo=1;
                    }
                    if(j<4&&disk[i][j]==disk[i][j+1]&&disk[i][j]==disk[i][j+2]&&disk[i][j]>0)//���3�s 
                    {
                        table[i][j]=table[i][j+1]=table[i][j+2]=disk[i][j];
                        findcombo=1;
                    }
                }
            
            //�p�G�o�Ӧa�観����A�h����쪺�a���ܦ�0(���i��)
            //�B��0���ܽL���̤W�h(�۹�ӻ��i�Ϊ��|�]��U�h 
            for(int i=0;i<5;i++)
                for(int j=0;j<6;j++)
                    if(table[i][j]>0)
                    {
                        disk[i][j]=0;
                        for(int ii=i;ii>0;ii--)swap(disk[ii][j],disk[ii-1][j]);
                    }
            
            for(int i=0;i<5;i++)
                for(int j=0;j<6;j++)
                    if(table[i][j]>0)//�N��combo 
                    {
                        queue<int> togox,togoy;
                        togox.push(i);
                        togoy.push(j);
                        int p=table[i][j];//�o��combo���ݩ� 
						//��BFS���o��combo�ۦP�ݫ����������A�קK�h�� 
                        while(!togox.empty())
                        {
                            int wx=togox.front(),wy=togoy.front();
                            table[wx][wy]=0;//�ݩ��k0(���i�� 
                            togox.pop();
                            togoy.pop();
                            if(wx<4&&table[wx+1][wy]==p)
                            {
                                togox.push(wx+1);
                                togoy.push(wy);
                            }
                            if(wx>0&&table[wx-1][wy]==p)
                            {
                                togox.push(wx-1);
                                togoy.push(wy);
                            }
                            if(wy<5&&table[wx][wy+1]==p)
                            {
                                togox.push(wx);
                                togoy.push(wy+1);
                            }
                            if(wy>0&&table[wx][wy-1]==p)
                            {
                                togox.push(wx);
                                togoy.push(wy-1);
                            }
                        }
                        combo++;
                    }
            memset(table,0,sizeof(table));//�O���L���m 
        }
        cout<<combo<<endl;
    }
    return 0;
}
