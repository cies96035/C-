#include<iostream>
using namespace std;


/*
�z�L�e��M�w�B�z�A�i�H�o��ǦC[0,n]���X��1�X�{
�p�G[0,i)�M[0,j]���t��n����j-i+1�ӡA�N�N���d��������O1
�t�~�p�G�t��0�A�N�N���d�����0
��L���p�N�O0,1�V�������A
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
		cout<<"Case "<<Case++<<":\n";
		
		int prefix[zero_and_one.size()]={zero_and_one[0]-'0'};
		//�Ĺs�Ӽƪ����� 
		
		for(int i=1;i<zero_and_one.size();i++)//���ۨ��o�C�ӫe��M(0~i�@���X��1�X�{) 
			prefix[i]=prefix[i-1]+zero_and_one[i]-'0';
			
		//*test*/ for(int i=0;i<zero_and_one.size();i++)cout<<prefix[i];
		//*test*/ cout<<endl;
		
		//�d�� 
		int n,l,r;
		cin>>n;
		while(n--)
		{
			cin>>l>>r;
			if(l>r)swap(l,r);
			
			//�������O0�ɡA��Ʀr���e��M�۴0
			//�������O1�ɡA��Ʀr���e��M�۴��Ʀr���t
			//��L���ܴN�O�V����0�M1 
			if((prefix[r]-prefix[l-1])==0||prefix[r]-prefix[l-1]==(r>l?r-l:l-r)+1)cout<<"Yes\n";
			else cout<<"No\n";
		}
	}
	return 0;
}

