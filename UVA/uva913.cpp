#include<iostream>
using namespace std;

/*
�[��C�C�̫�@�Ӽ� 
��N�C���̫�@�ӼƤ�N-1�h�F(2N-1)2
�˼ƲĤG�ӼơB�˼ƲĤT�ӼƤ]�O
�]����N�C�˼ƤT�ƪ��M�|���N-1�C�h�X(2N-1)2*3
�D�جO����N�C���Ʀr�ƶq�A2N-1=�D�ص�����
*/
int main()
{
	long long N;
	while(cin>>N)
		cout<<(3*N*N+6*N+3)/2-9<<endl;
	return 0;
}

