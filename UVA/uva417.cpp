#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


//�ۭq����(�p���ױƫe���A���۷Ӧr���) 
bool cmp(string a,string b)
{
	if(a.size()!=b.size())return a.size()<b.size();
	return a<b;
}

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	vector<string> words;
	string tosearch; 
	int start=0,end=26;
	
	/*
	�n��Ҧ��ŦX
	1.�C�Ӧr��u�]�t�p�g�r��
	2.�C�Ӧr�굴�ﻼ�W
	3.�r��̪���5�Ӧr��
	��i�hwords�̭� 
	*/
	
	//�@�}�l������פ@��a~z��i�h 
	for(string i="a";i<="z";i[0]++)
		words.push_back(i);
		
	/*
	�T�h�j��
	�Ĥ@�h�j��ت��n�B�z���״X(2~5)
	�ĤG�h�j��ت��n�N����n-1���r��ɤW�@�Ӧr���L�����ܬ�n 
	�ĤT�h�j��ت��n�W�[�Ҧ��q����n-1�ܦ�n���r�� 
	�Ҧp�� 
	i=1(���׬�3)
	j=28(ac���s��)
	k=e
	words�|push_back�@��"ac"+'e'���r��]�N�O"ace" 
	*/ 
	for(int i=0;i<4;i++)
	{
		for(int j=start;j<end;j++)
			for(char k=words[j][i]+1;k<='z';k++)
				words.push_back(words[j]+k);
		start=end;
		end=words.size();
	}
	
	//*Test*/for(int i=0;i<words.size();i++){cout<<i+1<<' '<<words[i]<<endl;}
	
	
	while(cin>>tosearch)
	{
		if(*lower_bound(words.begin(),words.end(),tosearch,cmp)!=tosearch)
			cout<<"0\n";
		else 
			cout<<lower_bound(words.begin(),words.end(),tosearch,cmp)-words.begin()+1<<endl;
		cout<<(tosearch[0]-'a'+1)*(26+26-(tosearch[0]-'a'))/2+tosearch[1]-tosearch[0]<<endl;
	}
	return 0;
}

