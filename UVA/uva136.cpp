//設x是醜數，2x,3x,5x是醜數 

#include<iostream>
#include<queue> 
#include<vector>
#include<map>
using namespace std;

typedef long long ll;
const int k[3]={2,3,5};
int main()
{
	priority_queue<ll,vector<ll>,greater<ll> > uglynum;
	map<ll,bool>isfind;
	uglynum.push(1);
	isfind[1]=1;
	for(int i=1;i<1500;i++)
	{
		ll ugly=uglynum.top();
		uglynum.pop();
		for(int j=0;j<3;j++)
		{
			if(isfind.find(k[j]*ugly)==isfind.end())
			{
				isfind[k[j]*ugly]=1;
				uglynum.push(k[j]*ugly);
			}
		}
	}
	cout<<"The 1500'th ugly number is "<<uglynum.top()<<"."<<endl;
	 
	return 0;
}

