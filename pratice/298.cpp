//完全暴力解就好...搞很久 
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int findroot(string str,int num)//找到字串根 
{
	for(int i=0;i<str.size();i++)
		num+=str[i]-'0';
	while(num>=10)
	{
		int tmp=0;
		do{	tmp+=num%10;
		}while(num/=10);
		num=tmp;
	}
	return num;
}

int main()
{
	int n,R;
	string ps;
	
	while(cin>>n>>R)
	{
		vector<string> ans;
		vector<int> key;
		
		cin>>ps;
		for(int i=0;i<10;i++)//找到key，十種可能各試一遍 
			if(findroot(ps,i)==R)key.push_back(i); 
		
		for(int i=0,index=0;i<key.size();i++)//把key丟進去嘗試 
		{
			ans.push_back(ps+char('0'+key[i]));
			index++;
			for(int j=1;j<n;j++,index++)
	        {
	            ans.push_back(ans[index-1]);
	            swap(ans[index][n-j-1],ans[index][n-j]);
	        }
		}
			
		sort(ans.begin(),ans.end());//排序後去丟掉重複，再去頭去尾 
		n=unique(ans.begin(),ans.end())-ans.begin();
		for(int i=1;i<n-1;i++)
			cout<<ans[i]<<'\n';
	}
	
	return 0;
}

