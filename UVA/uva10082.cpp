#include<iostream>
using namespace std;

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	//建表,及例外 :  ; ' = 
	char alpha[29]={ // A ~ Z [ \ ]
	'*','V','X','S','W',
	'D','F','G','U','H',
	'J','K','N','B','I',
	'O','*','E','A','R',
	'Y','C','Q','Z','T',
	'*','P',']','['},
	num[14]={  // , - . / 0 ~ 9 
	'M','0',',','.','9',
	'`','1','2','3','4',
	'5','6','7','8'},
	k;
	while(cin.get(k))
	{
		if(k>='A'&&k<=']')cout<<alpha[k-'A'];
		else if(k>=','&&k<='9')cout<<num[k-','];
		else if(k==';')cout<<'L';
		else if(k=='\'')cout<<';';
		else if(k=='=')cout<<'-';
		else cout<<k;
	}
	return 0;
}

