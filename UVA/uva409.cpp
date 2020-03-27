#include<iostream>
#include<cstring>
#include<vector> 
using namespace std;


//�P�_�O�_���^��r�� 
#define isalpha(k) ((k>='A'&&k<='Z')||(k>='a'&&k<='z'))

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	int K,E,set=1,k;
	while(cin>>K>>E)
	{
		string keyword[K],excuse[E],word;
		int keyword_in_excuse=0,index=0,max=0;
		vector<int> worst_excuse_id;
		for(int i=0;i<K;i++)
			cin>>keyword[i];

		cin.get();//�Y������ 
		
		//�����ꪺ�����Ǥf 
		while(index<E)
		{
			/*
			�O�r��->��i�@�Ӧr��
			���O�r��->�P�_�r��O���O����r
			����BEOF->�P�_�̦h����r���Ǥf 
			*/
			k=cin.get();
			excuse[index]+=(char)k;
			if(isalpha(k))
				word+=(char)(k>='a'?k:k-'A'+'a');
			else
			{
				//�P�_word�O���O����r 
				for(int i=0;i<K;i++)
				{
					if(word==keyword[i])
					{
						keyword_in_excuse++;
						break;
					}
				}
				
				//�p�Gexcuse[index]�X�{������r�̦h,�O���U�� 
				if(k=='\n'||k==EOF)
				{
					//*test*/cout<<keyword_in_excuse<<endl;
					if(keyword_in_excuse==max)//�X�{�@�˦h���N��i�h
						worst_excuse_id.emplace_back(index);
					else if(keyword_in_excuse>max)//�X�{��h���N�M�����e�������A��s
					{
						worst_excuse_id.clear();
						worst_excuse_id.emplace_back(index);
						max=keyword_in_excuse;
					}
					keyword_in_excuse=0;
					index++;
				}
				word.clear();//word�M��,�ǳƬ����U�@��
			}
		}
		
		//��X 
		cout<<"Excuse Set #"<<set++<<'\n';
		for(unsigned int i=0;i<worst_excuse_id.size();i++)
			cout<<excuse[worst_excuse_id[i]];
		cout<<'\n';
	}
	return 0;
}

