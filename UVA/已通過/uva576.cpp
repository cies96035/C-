#include<iostream>
using namespace std;

#define isvowel(k) (k=='a'||k=='e'||k=='i'||k=='o'||k=='u'||k=='y')//母音 

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	string sentence;
	while(getline(cin,sentence))
	{
		if(sentence=="e/o/i")break;//終止條件
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
				if(sentence[index]=='/'||sentence[index]=='\0')//當結束一個子句時,判斷此子句有幾個音節 
				{
					if(which_sentence==1&&syllable!=5)//第一子句,非5音節
					{
						cout<<"1\n";
						break;
					} 
					else if(which_sentence==2&&syllable!=7)//第二子句,非7音節
					{
						cout<<"2\n";
						break;
					} 				
					else if(which_sentence==3&&syllable!=5)//第三子句,非5音節 
					{
						cout<<"3\n";
						break;
					}
					syllable=0;
					which_sentence++;
				}
			}
			if(sentence[index]=='\0')//如果都沒有break完整讀完句子,代表是完美句子 
			{
				cout<<"Y\n";
				break;
			} 
			index++;
		}while(true);
		
	}
	return 0;
}

