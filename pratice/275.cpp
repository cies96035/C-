//ť���n��heap 
//�Ĥ@����heap������<3
#include<iostream>
#include<iomanip>
using namespace std;

#define Maxroot Maxh[1]
#define Minroot Minh[1]

typedef long double ld;
const int maxnum=100000;

int Max=0,Min=0;
ld Maxh[maxnum],Minh[maxnum],mid=0,num;
//�񤤦�Ƥp����Maxheap�A�Ϥ� 

void delMax(int root)//�Nheap�@�`�I�P�̫�@�`�I�洫�B�e�q-1 �ѤW�ܤU�洫�ܲŦX�W�h 
{
    swap(Maxh[root],Maxh[Max--]);
    for(int r=root<<1,rr=root ; r<=Max ; rr=r,r<<=1)
    {
        if(r+1<=Max&&Maxh[r+1]>Maxh[r])r++;//��̤j���l�`�I���
        if(Maxh[rr]<Maxh[r])//��l�`�I�p���ܫh�洫 
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

void addMax(int n)//�q�̤U���s�W�@�ӡA�ѤU�ܤW�A�ˬd�O�_�ŦX�W�j��U�A���ŦX�洫 
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
        if(num<mid)//�񤤦�Ƥp�A��JMaxheap 
            addMax(num);
        else //�Ϥ�
            addMin(num);
        if(i%2)
        {
            if(Min>Max)//�YMaxMin�ƶq�ۮt2�A��Min�̤p����Max�Y�i�A�A�ץ���N�n 
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
