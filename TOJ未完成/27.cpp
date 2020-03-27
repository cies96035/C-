#include<iostream>
using namespace std;

#define int_min -2147483648

const int maxN=2000001;
int num[maxN],A,B,Max;

struct Node
{
    int max;
}node[maxN*2];

void build(int root,int l,int r)
{
    if(l==r)
    {
        cin>>node[root].max;
        return;
    }
    int mid=(l+r)/2,LC=root*2,RC=LC+1;
    build(LC,l,mid);
    build(RC,mid+1,r);
    node[root].max=max(node[LC].max,node[RC].max);
    return;
}

void change(int root,int l,int r)
{
    if(l==r)
    {
        node[root].max=B;
        return;
    }
    int mid=(l+r)/2,LC=root*2,RC=LC+1;
    if(A<=mid)change(LC,l,mid);
    if(mid<A)change(RC,mid+1,r);
    node[root].max=max(node[LC].max,node[RC].max);
    return;
}

void query(int root,int l,int r)
{
    if(A<=l&&r<=B)
    {
    	if(node[root].max>Max)Max=node[root].max;
        return;
    }
    int mid=(l+r)/2,LC=root*2,RC=LC+1;
    if(A<=mid)query(LC,l,mid);
    if(mid<B)query(RC,mid+1,r);
    return;
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    int N,T;
    cin>>N;
    build(1,1,N);
    cin>>T;
    while(T--)
    {
        char X;
        cin>>X>>A>>B;
        if(X=='Q')
        {
            Max=int_min;
            query(1,1,N);
            cout<<Max/2<<'\n';
        }
        else if(X=='C')
            change(1,1,N);
    }
    return 0;
}
