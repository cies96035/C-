#include<iostream>
#include<iomanip>
#include<algorithm> 
using namespace std;

struct Weapon
{
	long double X,W,D;
};

bool cmp(const Weapon &a,const Weapon &b)
{
	if(a.D>b.D)return 1;
	return 0;
}

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
    int N,V,w=0,x=0;
    cin>>N>>V;
    //�s��C�ӪZ�����K��,�ΨC�ӪZ�����̤j�i�έ��q 
    
    Weapon weapon[N];
    
    //�B�z�C�Ӹ�� 
    for(int i=0;i<N;i++)
    {
        long double X,W;
        cin>>X>>W;
        weapon[i].X=X;
        weapon[i].W=W;
        weapon[i].D=X/W; 
    }
    
    sort(weapon,weapon+N,cmp);
    
    //�C���j���̤j�K�ת���i�h�A���쭫�q�W�L�D�حn�D 
    int y=-1;//�̤j�Z�����ˤO�K�׽s�� 
    while(w<V)
    {
        y++;
        //�N�s��y�����q�����[�i�hw�B���ˤO�����[�i�hx 
        x+=weapon[y].X;
        w+=weapon[y].W;
    } 
    
    //���`���Ȧ����h�X�Ӫ����q*�K�סA��X 
    cout<<fixed<<setprecision(3)<<x-(w-V)*weapon[y].D<<endl;
    
    return 0;
}
