#include<iostream>
#include<cstring>
using namespace std;

//�Ʀr����X�˦��A��������A�䤤����ؿ�X�覡 
/*
 -  ����A�A��X�覡:0 
| | ����B�A��X�覡:1
    ����C�A��X�覡:0
| | ����D�A��X�覡:1
 - 	����E�A��X�覡:0
�����C�@�ӼƦr����ABCDE�����A 

�A���O�̷Ӫ��A��X 
*/
int nums_to_cout[10][5]={
{1,1,0,1,1},
{0,0,0,0,0},
{1,0,1,2,1},
{1,0,1,0,1},
{0,1,1,0,0},
{1,2,1,0,1},
{1,2,1,1,1},
{1,0,0,0,0},
{1,1,1,1,1},
{1,1,1,0,1}};

string vertical_bar_part;//�h��B,D�����x�s�_�ӦA��X�A�٧P�_�ɶ� 
char End=' ';//�P�_�C�ӼƦr�����n��X�Ů��٬O����

//��J�s�������A�j�p/�Ʀr/���� 
void put_hyphen(int s,int n,int k)
{
	//���䳡��
	cout<<' ';
	
	//�������� 
	if(nums_to_cout[n][k])
		while(s--)cout<<'-';
	else
		while(s--)cout<<' ';
		
	//�k�䳡��+���j 
	cout<<' '<<End;
}

//��J�������A�Ʀr/���� 
void put_vertical_bar(int s,int n,int k)
{
	if(nums_to_cout[n][k])//���䳡�� 
		vertical_bar_part.append("|");
	else
		vertical_bar_part.append(" ");
		
	//�������� 
	vertical_bar_part.append(s,' ');
	
	//�k�䳡��+���j 
	if(nums_to_cout[n][k]<2)
		vertical_bar_part.append("|");
	else
		vertical_bar_part.append(" ");
	vertical_bar_part.append(1,End);
}

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	string N;
	int s;
	while(cin>>s>>N)
	{
		if(s==0&&N=="0")return 0;
		for(int i=0;i<5;i++)//����A�W��U 
		{
			for(unsigned long long j=0,Ns=N.size();j<Ns;j++)//�Ʀr�A����k 
			{
				if(j==Ns-1)End='\n';
				if(i%2)
					put_vertical_bar(s,N[j]-'0',i);
				else
					put_hyphen(s,N[j]-'0',i);
			}
			End=' ';
			for(int j=0;j<s;j++)cout<<vertical_bar_part;
			vertical_bar_part.clear();
		}
		cout<<'\n';
	}
	return 0;
}

