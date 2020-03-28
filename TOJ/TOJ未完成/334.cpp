#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
 
typedef long long ll;
typedef pair<ll,ll> pll;

ll X1,Y1,X2,Y2,ans=0;
vector<ll> Edge,chocolate;
map<pll,ll> MCT;//memorychangetimes

ll LB(vector<ll> v,ll r)
{return lower_bound(v.begin(),v.end(),r)-v.begin();}
 
ll cake(ll r,ll d,ll edge)//�N��n�o�� 1,1��r,d�����J�O�� 
{
    if(r>d)swap(r,d);//�㦳��� 
    
    if(MCT.find(pll(r,d))!=MCT.end())//���ƪ��O���U�ӥi�H�[�ֳt�� 
        return MCT[pll(r,d)];
        
    ll num=0,m=edge/2;
    ll kr=LB(Edge,r),kd=LB(Edge,d); 
    
    //�פ���� 
    if(d==Edge[kd]&&r==d)//�G��������������� 
        return MCT[pll(r,d)]=chocolate[kd];
    else if(r==Edge[kr]&&d==edge)//�G����e,�����䪺������ 
        return MCT[pll(r,d)]=chocolate[kr]*(edge/(r));
    else if(d==Edge[kd]&&r==edge)
        return MCT[pll(r,d)]=chocolate[kd]*(edge/(d));
        
    //���j 
    if(r>m&&d>m)//���|��(�@���S�F��) 
    {
        num+=cake(m,m,m);//���W 
        num+=cake(r-m,m,m);//�k�W 
        num+=cake(m,d-m,m);//���U 
    }
    else if(r<=m&&d>m)//����� 
    {
        num+=cake(r,m,m);//���W 
        num+=cake(r,d-m,m);//���U 
    }
    else//���@�� 
        num+=cake(r,d,m);//���W 
    return MCT[pll(r,d)]=num;
}
 
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
 
    chocolate.push_back(1);
    Edge.push_back(1);
    cin>>X1>>Y1>>X2>>Y2;
    while(Edge.back()<max(X2,Y2))
    {
        Edge.push_back(Edge.back()*2);
        chocolate.push_back(chocolate.back()*3);
    }
    ans=cake(X2,Y2,Edge.back());
    
    
    if(X1>1)
    {
        ans-=cake(X1-1,Y2,Edge.back());
        if(Y1>1)
        	ans+=cake(X1-1,Y1-1,Edge.back())-cake(X2,Y1-1,Edge.back());
	}
    else if(Y1>1)
        ans-=cake(X2,Y1-1,Edge.back());
        
    cout<<ans<<'\n';
}
