#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

#define isword(k) (k>='a'&&k<='z')||(k>='A'&&k<='Z') 
#define isnum(k) (k>='0'&&k<='9') 

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	string sentence,word;
	vector<string> words;
	vector<int> skip;
	int sum=0;
	char k;
	while(cin.get(k))
	{
		if(k=='0'&&sum==0)break;
		while(isnum(k))
		{
			sum=sum*10+k-'0';
			cin.get(k);
		}
		while(isword(k))
		{
			word+=k;
			cin.get(k);
		}
		if(!word.empty())
		{
			skip.push_back(sum);
			sentence.append(word);
			words.push_back(word);
			word.clear();
		}
		if(sum>0)
		{
			skip.push_back(sum);
			int skip_size=skip.size()-1,head=skip_size-sum,num=0;
			while(skip_size>=head)
			{
				skip_size--;
				if(skip[skip_size]>0&&head<=skip_size-skip[skip_size])
				{
					num++;
					head--;
				}
			}
			sentence.append(words[words.size()-sum-num]);
			words.push_back(words[words.size()-sum-num]);
			sum=0;
		}
		sentence+=k;
	} 
	cout<<sentence;
	return 0;
}

