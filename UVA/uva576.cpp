#include<iostream>
using namespace std;

#define isvowel(k) (k=='a'||k=='e'||k=='i'||k=='o'||k=='u'||k=='y')//���� 

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	string sentence;
	while(getline(cin,sentence))
	{
		if(sentence=="e/o/i")break;//�פ����
		int index=0,syllable=0,which_sentence=1;
		bool issyllable=1;
		do
		{
			if(isvowel(sentence[index]))
			{
				if(issyllable)
				{
					syllable++;
					issyllable=0;	
				}
			}
			else
			{
				issyllable=1;
				if(sentence[index]=='/'||sentence[index]=='\0')//�����@�Ӥl�y��,�P�_���l�y���X�ӭ��` 
				{
					if(which_sentence==1&&syllable!=5)//�Ĥ@�l�y,�D5���`
					{
						cout<<"1\n";
						break;
					} 
					else if(which_sentence==2&&syllable!=7)//�ĤG�l�y,�D7���`
					{
						cout<<"2\n";
						break;
					} 				
					else if(which_sentence==3&&syllable!=5)//�ĤT�l�y,�D5���` 
					{
						cout<<"3\n";
						break;
					}
					syllable=0;
					which_sentence++;
				}
			}
			if(sentence[index]=='\0')//�p�G���S��break����Ū���y�l,�N��O�����y�l 
			{
				cout<<"Y\n";
				break;
			} 
			index++;
		}while(true);
		
	}
	return 0;
}

