#include<iostream>
#include<fstream>
#include<sstream>
#include<vector>
#include<algorithm>
using namespace std;

#define IDSUM 54
string strinput;
string oneline;
vector<int> playerE;

int E[IDSUM][2];
string Ename[IDSUM];
int string_to_int(string a)
{
	int ans=0,i=0;
	for(int i=0;a[i]>='0'&&a[i]<='9';i++)
		ans=ans*10+a[i]-'0';
	return ans;
}
int main()
{
	ifstream equip("equip.csv");
	if(!equip.is_open())
	{
		cout<<"打不開檔案"<<endl;
		return 0; 
	} 
	for(int i=0;getline(equip,oneline);i++)
	{
		stringstream ss(oneline);
		getline(ss,strinput,',');
		int id=string_to_int(strinput);
		for(int j=0;j<2;j++)
		{
			getline(ss,strinput,',');
			E[id][j]=string_to_int(strinput);
		}
		getline(ss,strinput,',');
		Ename[id]=strinput;
	}
	equip.close();
	for(int i=0;i<54;i++)
	{
		cout<<E[i][0]<<E[i][1]<<endl;
	}
	
	for(int i=0;i<54;i++)
	{
		cout<<i<<':'<<Ename[i];
	}
	cout<<"輸入你現有裝備:\n";
	
	getline(cin,oneline);
	stringstream ss(oneline);
	while(getline(ss,strinput,' '))
		playerE.emplace_back(string_to_int(strinput));
	sort(playerE.begin(),playerE.end());
	for(int i=0;i<playerE.size();i++)
		cout<<playerE[i]<<endl;
	return 0;
}

