#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath> 
using namespace std;

typedef long long ll;
typedef __int128 gint;//���ŸյۧO��int128 
#define Max 1000000000000000018

vector<ll> useful;//pw����N!�Auseful�����Ҧ��i��pw 
ll value[20]={1};//����N!�A��19! 
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
	//���ŧ�3�]�S�P�A���ӷ|��� 
    for(int i=3;i<20;i++)//��s��i�Ӽƪ��Ҧ����ȩ�Juseful(2�S�P�A���M�|TLE�A�Ӧh�S�P�g�_�ӤS�ӳ·�)
    {
        gint num=value[i];
        for(int j=1,k=i+1;num<Max;j++,k++)
        {
        	if(twopassword((ll)num)!=num)//�p�G�P�ɬO�s��2�ӭ��ȡA�ᱼ���M�|�h��� 
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
	//�⭫�ƪ��ȥh�� 
    //�ۨ禡�A�C�C�z�� 
    
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
