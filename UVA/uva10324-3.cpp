#include<iostream>
using namespace std;

/*
�w�B�z:O(n)�A�C���߰�O(1) 
�t�~�o�Ӥ�k�A�p�G�D�ؤ��u��0�M1�]�A�ΡA
�e��M�򥻤W�u��P�_�u��0�M1���r�� 
*/

int main()
{
	//io�u�� 
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	string zero_and_one;
	int Case=1;
	while(cin>>zero_and_one)
	{
		
		int set[zero_and_one.size()]={0},set_value=0;
		
		
		//���աA�s�򪺦r�P�@��
		//���L�@���A�J�줣�s�򪺦r�h���� 
		for(int i=1;i<zero_and_one.size();i++)
		{
			if(zero_and_one[i]!=zero_and_one[i-1])
				set_value++;
			set[i]=set_value;
		}
		//*test*/ for(int i=0;i<zero_and_one.size();i++) cout<<set[i];
		//*test*/ cout<<endl; 
		
		cout<<"Case "<<Case++<<":\n";
		
		//�߰ݡA�Y�P�@�իh�N���Y�����b�P�@�ӳs�򪺦r�̡A�]�N�O�d�򤺩Ҧ��Ʀr���@�� 
		int n,i,j;
		cin>>n;
		while(n--)
		{
			cin>>i>>j;
			if(set[i]==set[j])cout<<"Yes\n";
			else cout<<"No\n";
		}
	}
	return 0;
}

