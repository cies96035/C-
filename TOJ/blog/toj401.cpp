//�ݰ_�ӫܳ·ЦӤw�A����٦n
//�d�n�ƾǹ�{�]�u���ܭ��n... 
/*
f���ȷ|������ax^5+bx^4+cx^3+dx^2+ex+f���ϧΤW�U����
�ҥH�ڭ̭p��@���I(x,y),�Nx�a�i�h,
�x�s�@��b�ȭn�[�h�֤~�|����y
�N��K�p��b��X�N�O����...

��...��@�����A
���N�O...�ƾǹ�... 
*/ 
/*
�p�ޥ�(�٤@�b���k�ɶ� 
ax^5+bx^4+cx^3+dx^2+ex+d
==
(((((0*x+a)*x+b)*x+c)*x+d)*x+e)+d

�o�ӫܭ��n�A���O���A�@�Ӧr��S�A
a�aS[0]-'0'�Ab�aS[1]-'0'...�AX�a10�A
�N��N�r�껴�P�ഫ���Ʀr 
*/
#include<iostream>
#include<algorithm>
using namespace std;

struct water
{
    int x,y;
};

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0); 
    
    int K,a[5],N;
    cin>>K;
    for(int i=0;i<5;i++)cin>>a[i];
    cin>>N;
    water W[N];
    int b[N];
    for(int i=0;i<N;i++)
    {
        cin>>W[i].x>>W[i].y;
    }
    for(int i=0;i<N;i++)
    {
        int k=W[i].x,ans=0;
        for(int j=0;j<5;j++)
        {
            ans=ans*k+a[j];
        }
        ans*=k;
        b[i]=W[i].y-ans;
    }
    sort(b,b+N);
    cout<<b[N-K]<<endl;
    return 0;
}
