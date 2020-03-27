#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
    int T,M,N,S;
    cin>>T;
    for(int Case=1;Case<=T;Case++)
    {
    	//��J�X���I�A�X�ӳs���A�_�I 
        cin>>N>>M>>S;
        
        /*
        //�ܼƥγ~ 
        High:�U�I����
		far:�������I��U�I�̪񪺶Z��(DP��X�̧C�I�̪�Z��
		walk:���I��̧C�I�̪�Z��(�L�k��F�h�S����
		down:�U�Y���Z��
		end:�����̧C�I����(���ήy�ЬO�]���i�঳�h�ӳ̧C�I 
		graph:���V��
		isgo:BFS�����w�q�L���I�A�קK���^�Y��
		f1,f2:���O�P�_�����M�U�Y���ण���F 
		*/
		queue<int> togo;//BFS�Ψ�
        int High[N],far[N],walk,down=0,end=2e9;
        bool graph[N][N],isgo[N],f1=0,f2=1;
        //�M�Ű}�C 
        memset(graph,0,sizeof(graph));
        memset(isgo,0,sizeof(isgo));
        
        //��J�C�Ӯy�а��סB���V�� 
        for(int i=0;i<N;i++)
        {
            cin>>High[i];
            //�����̧C�I���� 
            if(end>High[i])
            {
                end=High[i];
            }
        }
        for(int i=0;i<M;i++)
        {
            int x,y;
            cin>>x>>y;
            graph[x][y]=graph[y][x]=1;
        }
        
        togo.push(S);//��_�I��J�j�M��C 
        isgo[S]=1;//��_�I��J�w�����W�� 
        far[S]=0;//�q�_�I��_�I���Z����0 
        while(!togo.empty())//����j�M��C�ŪŬ��� 
        {
            int t=togo.front();
            togo.pop();
            //�N�j�M��C���Ĥ@�Ӯ��X�ӡA�}�l�j�M�۾F���I 
            if(High[t]==end) 
            {
                //�p�G�X�{�F�Ĥ@�ӥѰ_�I�s��̧C�I�����|
                //�hf1��1(�����i��F)�A�B�Z�������̧C�I��far 
                f1=1;
                walk=far[t]*6;
                break;
            }
            for(int i=0;i<N;i++)
            {
                //��Ҧ��S�����L�åB�۾F���I�A��i�j�M��C
                if(graph[t][i]&&!isgo[i])
                {
                    togo.push(i);
                    isgo[i]=1;
                    far[i]=far[t]+1;//�����_�I��C���I���̵u�Z�� 
                    
                }
            }
        }
        
        //�U�Y���A��while���찪�ר�̧C�I�~����
        //�z�פW�n��BFS(�p�G�P�ɦ���ӥH�W�̧C�I�A���{���u�|��䤤�@��) 
        while(High[S]!=end)
        {
            /*
            min:�����̧C�I����
            minid:�O���̧C�Iid(�U���q�o�̥X�o)�A��l�Ȭ�-1(�䤣���X�o�I�۳s�B��X�o�I�C���I 
            */ 
            int min=High[S],minid=-1;
            
            //���L�C�@���I�A��X��X�o�I�C�̦h�������I�A�O���U�� 
            for(int i=0;i<N;i++)
            {
                if(graph[i][S]&&min>High[i])
                {
                    min=High[i];
                    minid=i;
                }
            }
            
            //�p�G�P�X�o�I�۳s���I��������A�h���}�j��A�ðO���U�Y���L�k��F 
            if(minid==-1)
            {
                f2=0;
                break;
            }
            
            //�U�����X�o�I���o�����̧C�I 
            S=minid;
            //�C�U�Y���@���Adown�N�W�[�@�� 
            down++;
        }
        
        
        //��X���� 
        if(f1&&f2)
            cout<<"Case #"<<Case<<": "<<walk-down<<'\n';
        else if(f1)
            cout<<"Case #"<<Case<<": "<<walk<<'\n';
        else
            cout<<"Case #"<<Case<<": Call 119!\n";
    }
    return 0;
}
