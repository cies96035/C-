#include<iomanip>
#include<iostream>
using namespace std;
int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
    long double
    max_x1=-2e9,min_x2=2e9,
    max_y1=-2e9,min_y2=2e9,
    x1[3],x2[3],y1[3],y2[3],
    ans[3]={0,0,0},sum=0;
    //sum:���n�`�M�Aans�x�s���סA��L���O�x�s�y��
    
    //��J�y�ШðO�����n�`�M 
    for(int h=0;h<3;h++)
    {
        cin>>x1[h]>>y1[h]>>x2[h]>>y2[h];
        max_x1=max(max_x1,x1[h]);
        min_x2=min(min_x2,x2[h]);
        max_y1=max(max_y1,y1[h]);
        min_y2=min(min_y2,y2[h]);
        sum+=(x2[h]-x1[h])*(y2[h]-y1[h]);
    }
    
    //ans[1]�����C����x�Ϊ��|�X���n 
    for(int h=0;h<3;h++)
    { 
        long double
        k=(min(x2[h],x2[(h+1)%3])-max(x1[h],x1[(h+1)%3])),
        kk=(min(y2[h],y2[(h+1)%3])-max(y1[h],y1[(h+1)%3]));
        if(k>0&kk>0)
            ans[1]+=k*kk;
    }
    
    if(min_x2>=max_x1&&min_y2>=max_y1)//�p�G�T���x�Φ��|�X�b�@�_�A�h�����|�X���n 
        ans[0]=(min_x2-max_x1)*(min_y2-max_y1);
    ans[1]-=ans[0]*3;//����x�Ϊ��|�X���n���ƺ�� �T���x���|�X���n�T���A�n���� 
    ans[2]=sum-ans[1]*2-ans[0]*3;//����x�Ϊ����n�]�����ƺ��A��h����������
	
	//��X 
    cout<<fixed<<setprecision(2)<<ans[0]<<" "<<ans[1]<<" "<<ans[2]<<endl;
    return 0;
}
