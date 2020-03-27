#include<iostream>
#include<vector>
using namespace std;


//���ۤU��,�Ȯɥb�z�� 
int LIS(vector<int> s)
{
    // ���o���P�_���S��
    if(s.size()==0)return 0;
 
    //����J�@�ӼƦr�A�K�o�y�� v.back() �X���C
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

