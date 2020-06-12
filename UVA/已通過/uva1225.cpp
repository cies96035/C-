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
    t:測資數
    N:要輸入被digit counting的數 
    digits:紀錄每個數字的出現次數
    ten:紀錄10的次方，同時代表判斷到幾位數 
    front:紀錄N前面的一段數字,到k那個位數為止(不包含k) 
    end:紀錄N後面的一段數字,k那個位數以後(不包含k)
    k:紀錄N的某個位數,由低位數到高位數 
    */
    cin>>t;
    while(t--)
    {
        cin>>N;
        ten=1;
        front=N;
        memset(digits,0,sizeof(digits));
         
        //終止條件:直到判斷的位數超過N的位數，如N=12345,ten=100000(判斷到第六位)
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
        
        //輸出 
        for(int i=0;i<9;i++)cout<<digits[i]<<' ';
        cout<<digits[9]<<endl;
    }
    return 0;
}