#include<iostream>
using namespace std;

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int t;
	string nums[3]={"one","two","three"};
	cin>>t;
	while(t--)
	{
		string num;
		cin>>num;
		for(int i=0;i<3;i++)
		{
			unsigned int correct=0;
			for(unsigned int j=0;j<nums[i].size();j++)
				if(num[j]==(nums[i])[j])correct++;
			if(correct>=nums[i].size()-1)
			{
				cout<<i+1<<endl;
				break;
			}
		}
	}
	return 0;
}

