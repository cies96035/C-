#include<iostream>
#include<vector>
using namespace std;

int num_times[400000050];//¬ö¿ý¦¸¼Æ 
int main()
{
	vector<int> num_turn;//¬ö¿ý¶¶§Ç 
	int num;
	while(cin>>num)
	{
		num+=200000000;
		if(!num_times[num]++)num_turn.push_back(num);
	}
	for(int i=0;i<num_turn.size();i++)
		cout<<num_turn[i]-200000000<<' '<<num_times[num_turn[i]]<<'\n';
	return 0;
}

