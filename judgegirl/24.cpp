#include<iostream>
using namespace std;
 
const string Vwl="AEIOUaeiou";
int main() {
	char k;
	int digit=0,vowel=0,consonant=0;
	while(cin.get(k)&&k!='\n')
	{
		if((k>='a'&&k<='z')||(k>='A'&&k<='Z'))
		{
			bool isvowel=0;
			for(int i=0;i<Vwl.size();i++)
				if(k==Vwl[i])
				{
					isvowel=1;
					break;
				}
			if(isvowel)vowel++;
			else consonant++;
		}
		else if(k>='0'&&k<='9')
			digit++;
	}
	cout<<digit<<' '<<vowel+consonant<<' '<<vowel<<' '<<consonant<<endl;
	return 0;
}
