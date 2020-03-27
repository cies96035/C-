#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int LIS(queue<int> s)
{
 
    vector<int> v;
    v.push_back(s.front());
    s.pop();
    while(!s.empty())//關鍵!! 
    {
        if (s.front() > v.back())
            v.push_back(s.front());
        else
            *lower_bound(v.begin(), v.end(), s.front()) = s.front();//替換較有淺力的值
        s.pop();
    }
 
    return v.size();
}

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
	
	int N,K,num;
	cin>>N>>K;
    int arr[N+1];
    for(int i=0;i<N;i++)
    {
        cin>>num;
        arr[num]=i;
    }
    while(K--)
    {
        queue<int> toLIS;
        for(int i=0;i<N;i++)
        {
            cin>>num;
            toLIS.push(arr[num]);
        }
        cout<<LIS(toLIS)<<'\n';
    }
    return 0;
}
