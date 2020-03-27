#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath> 
using namespace std;

typedef long long ll;
typedef __int128 gint;//有空試著別用int128 
#define Max 1000000000000000018

vector<ll> useful;//pw紀錄N!，useful紀錄所有可行pw 
ll value[20]={1};//紀錄N!，到19! 
void getvalue()
{
	for(int i=1;i<20;i++)value[i]=value[i-1]*i;
}

inline ll twopassword(ll k)
{
	ll i=sqrtl(k);
	return i*(i+1);
}

void getpassword()
{
	//有空把3也特判，應該會更快 
    for(int i=3;i<20;i++)//把連續i個數的所有乘值放入useful(2特判，不然會TLE，太多特判寫起來又太麻煩)
    {
        gint num=value[i];
        for(int j=1,k=i+1;num<Max;j++,k++)
        {
        	if(twopassword((ll)num)!=num)//如果同時是連續2個乘值，丟掉不然會多算到 
        		useful.push_back(num);
        	num*=k;
        	num/=j;
        }
    }
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
	getvalue();
    getpassword();
    
    sort(useful.begin(),useful.end());
    useful.resize(distance(useful.begin(),unique(useful.begin(),useful.end())));
	//把重複的值去掉 
    //抄函式，慢慢理解 
    
	int T;
    cin>>T;
    while(T--)
    {
        ll l,r;
        int ans;
        cin>>l>>r;
        ans=1+(ll)sqrtl(r)-(ll)sqrtl(l)+(upper_bound(useful.begin(),useful.end(),r)-useful.begin())-(lower_bound(useful.begin(),useful.end(),l)-useful.begin());
		if(twopassword(l)<l)ans--;
		if(twopassword(r)>r)ans--;
        cout<<ans<<'\n';
    }
    
    return 0;
}
