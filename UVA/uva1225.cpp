#include<iostream>
#include<cstring> 
using namespace std;


int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    int t,N,front,end,k;
    long long digits[10],ten;
    /*
    t:�����
    N:�n��J�Qdigit counting���� 
    digits:�����C�ӼƦr���X�{����
    ten:����10������A�P�ɥN��P�_��X��� 
    front:����N�e�����@�q�Ʀr,��k���Ӧ�Ƭ���(���]�tk) 
    end:����N�᭱���@�q�Ʀr,k���Ӧ�ƥH��(���]�tk)
    k:����N���Y�Ӧ��,�ѧC��ƨ찪��� 
    */
    cin>>t;
    while(t--)
    {
        cin>>N;
        ten=1;
        front=N;
        memset(digits,0,sizeof(digits));
         
        //�פ����:����P�_����ƶW�LN����ơA�pN=12345,ten=100000(�P�_��Ĥ���)
        while(ten<=N)
        {
            k=front%10;
            front/=10;
            end=N%ten;
            //*test*/cout<<"k:"<<k<<" ten:"<<ten<<" front:"<<front<<" end:"<<end<<endl; 
            for(int i=0;i<10;i++)
            {
                //*test*/int p=digits[i];
                if(i<k)
                    digits[i]+=(front+1)*ten;
                else
                    digits[i]+=(front)*ten;
                if(i==0)digits[0]-=ten;
                if(i==k)digits[i]+=end+1;
                //*test*/cout<<digits[i]-p<<' ';
            }
            ten*=10;
            //*test*/cout<<endl;
        }
        
        //��X 
        for(int i=0;i<9;i++)cout<<digits[i]<<' ';
        cout<<digits[9]<<endl;
    }
    return 0;
}
