#include<iostream>
#include<vector>
using namespace std;

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int t;
	cin>>t;
	cin.ignore();
	while(t--)
	{
		int index=0;
		vector<char> words;
		char input,change;
		while(cin.get(input))
			if(input!='\n')
				words.push_back(input);
			else break;
		while(cin.get(change))
		{
			/*
			if(change=='\n'){
				cout<<index<<endl;
				for(int i=0;i<words.size();i++)
					cout<<words[i];
			cout<<'\n'<<flush;}*/
			if(change=='0')index=0;
			else if(change=='$')index=words.size();
			else if(change=='x'&&index<words.size())words.erase(words.begin()+index);
			else if(change=='s'&&index<words.size()-1)swap(words[index],words[index+1]);
			else if(change=='i')
			{
				char k;
				cin.get(change);
				words.insert(words.begin()+index,change);
				index++;
			}
			else if(change=='u'&&index<words.size())
			{
				if(words[index]>='a'&&words[index]<='z')words[index]+='A'-'a';
				index++;
			}
			else if(change=='+'&&index<words.size())index++;
			else if(change=='-'&&index>0)index--;
			else if(change=='\n')break;
		}
		for(int i=0;i<words.size();i++)
			cout<<words[i];
		cout<<'\n';
	}
	return 0;
}

