#include<iostream>
using namespace std;

#define N 1000000007

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
    char k;
    //num:�O���C�@�ӼƦr,sum:�����C�ӼƦr�`�M 
    int num=0,sum=0,son;//son:�������l 
    bool flag=0;//�P�_�O���O���� 
    while(cin.get(k))
    {
    	if(k>='0'&&k<='9')
		{
			num=num*10+k-'0';
		}
		else if(k==' ')
		{
			if(!flag)//�p�G���O���� 
				sum+=num;
			else if(num&&son%num==0)//�p�G�O���ƥB����� 
				sum+=son/num,flag=0,son=0;
			num=0;
			sum%=N;
			flag=0;
		} 
		else if(k=='\n')
		{
			if(!flag)//�p�G���O���� 
				sum+=num;
			else if(num&&son%num==0)//�p�G�O���ƥB����� 
				sum+=son/num,son=0;
			cout<<sum%N<<endl;
			sum=num=0;
			flag=0;
		}
		else// ���� 
		{
			son=num;//���l 
			num=0;//�Ʀr�k�s 
			flag=1;//�N������ 
		}
    }
    return 0;
}
