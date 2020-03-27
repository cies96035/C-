#include<iostream>
#include<vector>
using namespace std;


//先抄下來,暫時半理解 
int LIS(vector<int> s)
{
    // 不得不判斷的特例
    if(s.size()==0)return 0;
 
    //先放入一個數字，免得稍後 v.back() 出錯。
    vector<int> v;
    v.push_back(s[0]);
 
    for(int i=1;i<s.size();i++)
    {
        int n = s[i];
 
        if (n > v.back())
            v.push_back(n);
        else
            *lower_bound(v.begin(), v.end(), n) = n;
    }
 
    return v.size();
}

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	int n;
	while(cin>>n)
	{
		int arr[n],num;
		vector<int> toLIS;
		for(int i=0;i<n;i++)
		{
			cin>>num;
			arr[num]=i;
		}
		for(int i=0;i<n;i++)
		{
			cin>>num;
			toLIS.push_back(arr[num]);
			//cout<<arr[num]<<' ';
		}
		cout<<LIS(toLIS)<<endl;
	}
	return 0;
}

