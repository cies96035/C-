#include<iostream>
using namespace std;

int code=-1,sound[26]=
//code of every sound
//A B C D E F G H I J K L M N O P Q R S T U V W X Y Z
 {0,1,2,3,0,1,2,0,0,2,2,4,5,5,0,1,2,6,2,3,0,1,0,2,0,2};
char c;//storage input
string s;//output

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	while(cin.get(c))
	{
		if(c=='\n')
		{
			cout<<s<<'\n';
			//Init
			s.clear();
			code=-1;
		}
		else
		{
			if(sound[c-'A']!=0&&code!=sound[c-'A'])
				s+=sound[c-'A']+'0';
			code=sound[c-'A'];
		}
	} 
	return 0;
}

