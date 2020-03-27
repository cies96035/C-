#include<iostream>
using namespace std;
/*Code1
int main()
{
	string S;
	while(cin>>S)//問題->沒有換行
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
	while(cin.get(c))//一個一個字元讀 
	{
		if(c==' ')
		{
			cout<<S;
			S="";//清空字串 
		}
		else if(c=='\n')
		{
			cout<<S<<'\n';
			break;//結束迴圈 
		}
		else
		{
			S+=c; 
			if(S.size()==1)//只有頭，轉大寫
				S[0]+='A'-'a';
		}
	}
	return 0;
}*/

//Code3
int main()
{
	string S,output;
	getline(cin,S);//讀整行，直到'\n'結束，放進string
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
