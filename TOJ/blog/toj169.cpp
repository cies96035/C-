#include<iostream>
using namespace std;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    int N;
    while(cin>>N)
    {
        //�w�]�Ĺs����Ƭ��L���j�Aleft_lower�����C�ڪ������ӮڧC���@���X��
        //tocmpid�A�n�����id
        int n[N+1]={2147483647},left_lower[N+1]={0},tocmpid;
        
        //��J
        for(int i=1;i<=N;i++)
			cin>>n[i];
        
        for(int i=1;i<=N;i++)
        {
            left_lower[i]=0;
        	tocmpid=i-1;
        	//�p�G�S�Q�צ�A��X��Ӯڤp�����X�� 
            while(n[i]>n[tocmpid])
            {
                //�p�G��n������δΤj�A�h�Y���L�����שM�L����
                left_lower[i]+=left_lower[tocmpid]+1;
                //�O�_��Y����e�����δ� 
            	tocmpid-=left_lower[tocmpid]+1;
            }
        }
        
        //��X 
        for(int i=1;i<N;i++)
        {
            cout<<left_lower[i];
            cout<<' ';
        }
        cout<<left_lower[N]<<endl;
    }
    return 0;
};
