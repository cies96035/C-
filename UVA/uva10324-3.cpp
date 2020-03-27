#include<iostream>
using namespace std;

/*
預處理:O(n)，每筆詢問O(1) 
另外這個方法，如果題目不只有0和1也適用，
前綴和基本上只能判斷只有0和1的字串 
*/

int main()
{
	//io優化 
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	string zero_and_one;
	int Case=1;
	while(cin>>zero_and_one)
	{
		
		int set[zero_and_one.size()]={0},set_value=0;
		
		
		//分組，連續的字同一組
		//掃過一次，遇到不連續的字則換組 
		for(int i=1;i<zero_and_one.size();i++)
		{
			if(zero_and_one[i]!=zero_and_one[i-1])
				set_value++;
			set[i]=set_value;
		}
		//*test*/ for(int i=0;i<zero_and_one.size();i++) cout<<set[i];
		//*test*/ cout<<endl; 
		
		cout<<"Case "<<Case++<<":\n";
		
		//詢問，若同一組則代表頭尾都在同一個連續的字裡，也就是範圍內所有數字都一樣 
		int n,i,j;
		cin>>n;
		while(n--)
		{
			cin>>i>>j;
			if(set[i]==set[j])cout<<"Yes\n";
			else cout<<"No\n";
		}
	}
	return 0;
}

