#include<iostream>
using namespace std;
/*Code1
int main()
{
	string S;
	while(cin>>S)//���D->�S������
	{
		S[0]+='A'-'a';
		cout<<S; 
	}
	return 0;
}*/

/*Code2
int main()
{
	string S;
	char c;
	while(cin.get(c))//�@�Ӥ@�Ӧr��Ū 
	{
		if(c==' ')
		{
			cout<<S;
			S="";//�M�Ŧr�� 
		}
		else if(c=='\n')
		{
			cout<<S<<'\n';
			break;//�����j�� 
		}
		else
		{
			S+=c; 
			if(S.size()==1)//�u���Y�A��j�g
				S[0]+='A'-'a';
		}
	}
	return 0;
}*/

//Code3
int main()
{
	string S,output;
	getline(cin,S);//Ū���A����'\n'�����A��istring
	for(int i=0;i<S.size();i++)
	{
		if(S[i]>='a'&&S[i]<='z')
		{
			if((i==0||S[i-1]==' '))
				output+=S[i]+'A'-'a';
			else output+=S[i];
		}
	}
	cout<<output<<endl;
	return 0;
}
