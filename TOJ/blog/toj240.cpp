#include<iostream>
#include<cmath>
using namespace std;

//���Gmod 1000000007 
#define mod 1000000007

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	//�Ʀr�j�n��ull�x�s(�S���t��
	unsigned long long X,N,ans=0;
	cin>>X>>N;
	//��JĲ���q�A�ýվ�A�hĲ����Ĳ����
	unsigned long long A[N];
	/*
	�p�G��Ĳ�⪺CP�Ȥ�����A��s�hĲ�⪺��
	�g�k��ı�i�H��֡A�u�O�ϥ��Ʀr���j
	�C�C��N�n
	*/ 
	for(int i=0;i<N;i++)
	{
		cin>>A[i];
		for(int j=0;j<i;j++)
		{
			unsigned long long num=pow(2,i-j);
			//�p�G��Ĳ��CP�Ȱ��A�h��s�hĲ���
			if(A[j]*num<A[i])
				A[i]=A[j]*num;
		}
		A[i]%=mod;
	}
	
	//�u���ΦhĲ��A�A�C�C�Ψ��Ĳ�� 
	for(int i=N-1;i>=0;i--)
	{
		unsigned long long num=pow(2,i);
		if(X>=num)
		{
			unsigned long long p=X/num;
			X-=p*num;
			//**�`�N**
			//�S��p%mod�Aans�|���� 
			p%=mod;
			ans+=p*A[i];
			ans%=mod;
			if(X==0)break;
		}
	}
	cout<<ans<<endl;
	return 0;
}

