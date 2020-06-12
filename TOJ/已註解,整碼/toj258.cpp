//similar to toj234

#include<iostream>
#include<algorithm>
#include<cmath>
#include<iomanip>
using namespace std;

typedef long double ld;

#define maxN 1000100
#define Inf (ld) 2e8
#define M (L+R)/2

int N;
ld d=Inf;

struct Point
{
    int x,y;
}points[maxN],sp_points[maxN];

bool cmpx(Point a,Point b){return a.x<b.x;}
bool cmpy(Point a,Point b){return a.y<b.y;} 

//get two points' distance and square it
ld distance(Point a,Point b)
{
    ld dx=a.x-b.x,dy=a.y-b.y;
    return sqrt(dx*dx+dy*dy);
}

//points[L]~points[R] closet_point_pair 
ld min_distance(int L,int R)
{
    //if point_amounts less than 2 return infinite
    if(L>=R)return Inf;
    
    //return minest part,Lpart or Rpart
    ld d=min(min_distance(L,M),min_distance(M+1,R));
    
    int index=0;//sp record the points between M.x-d && (M+1).x+d
    for(int i=M , Lbound=points[M].x-d ; i>=L && Lbound<=points[i].x ; i--)
        sp_points[index++]=points[i];
    for(int i=M+1 , Rbound=points[M+1].x+d ; i<=R && points[i].x<=Rbound ; i++)
        sp_points[index++]=points[i];
        
    //sort sp by y
    sort(sp_points,sp_points+index,cmpy);
    
    //find if there a miner distance cross two part
    for(int i=0;i<index;i++)
        for(int j=i+1,k=0 ; k<3 && j<index ; j++,k++)
            d=min(d,distance(sp_points[i],sp_points[j]));
            
    return d;
}
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin>>N;
    for(int i=0;i<N;i++)
        cin>>points[i].x>>points[i].y;
        
    sort(points,points+N,cmpx);
    
    cout<<fixed<<setprecision(6)<<min_distance(0,N-1)<<'\n';
    return 0;
}

