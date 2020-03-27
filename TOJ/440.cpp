#include<iostream>
#include<cstring>
using namespace std;

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	string S,ans;
	int K,fit[5][5];
	cin>>S>>K;
	int T=S.size()-K+1,word[T]={0},alpha[K][5];//K個字元位置，各有幾個a~e，word[T]可以想辦法省略 
	memset(alpha,0,sizeof(alpha));
	for(int i=0;i<S.size();i++)
		for(int j=max(0,i-K+1);j<=i&&j<T;j++)
			alpha[word[j]++][S[i]-'a']++;
	for(int i=0;i<5;i++)
		for(int j=0;j<5;j++)
			cin>>fit[i][j];
	for(int i=0;i<K;i++)
	{
		int max=-2e9;
		char correct;
		for(int j=0;j<5;j++)
		{
			int value=fit[0][j]*alpha[i][0]+fit[1][j]*alpha[i][1]+fit[2][j]*alpha[i][2]+fit[3][j]*alpha[i][3]+fit[4][j]*alpha[i][4];
			if(value>max)
			{
				max=value;
				correct='a'+j;
			}
		}
		ans.append(1,correct);
	}
	cout<<ans<<'\n';
	return 0;
}

