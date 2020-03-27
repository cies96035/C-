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
    t:代戈计
    N:璶块砆digit counting计 
    digits:魁–计瞷Ω计
    ten:魁10Ωよ耞碭计 
    front:魁N玡琿计,kê计ゎ(ぃk) 
    end:魁N琿计,kê计(ぃk)
    k:魁N琘计,パ计蔼计 
    */
    cin>>t;
    while(t--)
    {
        cin>>N;
        ten=1;
        front=N;
        memset(digits,0,sizeof(digits));
         
        //沧ゎ兵ン:耞计禬筁N计N=12345,ten=100000(耞材せ)
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
        
        //块 
        for(int i=0;i<9;i++)cout<<digits[i]<<' ';
        cout<<digits[9]<<endl;
    }
    return 0;
}
