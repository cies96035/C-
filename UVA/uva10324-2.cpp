#include<iostream>
using namespace std;


/*
透過前綴和預處理，可以得到序列[0,n]有幾個1出現
如果[0,i)和[0,j]的差剛好等於j-i+1個，就代表此範圍全部都是1
另外如果差為0，就代表此範圍全為0
其他狀況就是0,1混雜的狀態
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
		cout<<"Case "<<Case++<<":\n";
		
		int prefix[zero_and_one.size()]={zero_and_one[0]-'0'};
		//第零個數直接取 
		
		for(int i=1;i<zero_and_one.size();i++)//接著取得每個前綴和(0~i共有幾個1出現) 
			prefix[i]=prefix[i-1]+zero_and_one[i]-'0';
			
		//*test*/ for(int i=0;i<zero_and_one.size();i++)cout<<prefix[i];
		//*test*/ cout<<endl;
		
		//查詢 
		int n,l,r;
		cin>>n;
		while(n--)
		{
			cin>>l>>r;
			if(l>r)swap(l,r);
			
			//當中間都是0時，兩數字的前綴和相減為0
			//當中間都是1時，兩數字的前綴和相減為兩數字的差
			//其他的話就是混雜著0和1 
			if((prefix[r]-prefix[l-1])==0||prefix[r]-prefix[l-1]==(r>l?r-l:l-r)+1)cout<<"Yes\n";
			else cout<<"No\n";
		}
	}
	return 0;
}

