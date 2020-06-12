//钮弧璶ノheap 
//材Ωheap砰喷<3
#include<iostream>
#include<iomanip>
using namespace std;

#define Maxroot Maxh[1]
#define Minroot Minh[1]

typedef long double ld;
const int maxnum=100000;

int Max=0,Min=0;
ld Maxh[maxnum],Minh[maxnum],mid=0,num;
//ゑい计Maxheapはぇ 

void delMax(int root)//盢heap竊翴籔程竊翴ユ传甧秖-1 パユ传才砏玥 
{
    swap(Maxh[root],Maxh[Max--]);
    for(int r=root<<1,rr=root ; r<=Max ; rr=r,r<<=1)
    {
        if(r+1<=Max&&Maxh[r+1]>Maxh[r])r++;//蛤程竊翴ゑ耕
        if(Maxh[rr]<Maxh[r])//ゑ竊翴杠玥ユ传 
            swap(Maxh[rr],Maxh[r]);
        else break;
    }
}

void delMin(int root) 
{
    swap(Minh[root],Minh[Min--]);
    for(int r=root<<1,rr=root ; r<=Min ; rr=r,r<<=1)
    {
        if(r+1<=Min&&Minh[r+1]<Minh[r])r++;
        if(Minh[rr]>Minh[r])
            swap(Minh[rr],Minh[r]);
        else break;
    }
}

void addMax(int n)//眖程穝糤パ浪琩琌才ぃ才ユ传 
{
    Maxh[++Max]=n;
    for(int r=Max,rr=r>>1 ; rr&&Maxh[r]>Maxh[rr] ; r>>=1,rr>>=1)
        swap(Maxh[r],Maxh[rr]);
}

void addMin(int n)
{
    Minh[++Min]=n;
    for(int r=Min,rr=r>>1 ; rr&&Minh[r]<Minh[rr] ; r>>=1,rr>>=1)
        swap(Minh[r],Minh[rr]);
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cout<<fixed<<setprecision(6);
    
    int N;
    cin>>N;
    for(int i=0;i<N;i++)
    {
        cin>>num;
        if(num<mid)//ゑい计Maxheap 
            addMax(num);
        else //はぇ
            addMin(num);
        if(i%2)
        {
            if(Min>Max)//璝MaxMin计秖畉2рMin程簿Maxタ攫碞 
            {
                addMax(Minroot);
                delMin(1);
            }
            else if(Max>Min)
            {
                addMin(Maxroot);
                delMax(1);
            }
            mid=(Minroot+Maxroot)/2;
        }
        else
            mid=Min>Max?Minroot:Maxroot;
        cout<<mid<<'\n';
    }
    return 0;
}
