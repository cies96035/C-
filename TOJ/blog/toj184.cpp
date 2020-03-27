#include<iostream>
#include<cstring> 
using namespace std;
int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0); 
	
    string A,B,ans;
    while(cin>>A>>B)
    {
        
        if(A=="0"||B=="0") //是否乘以零的特例 
        {
            cout<<"0"<<endl;
            continue;
        }
        
        bool nA=(A[0]=='-'),nB=(B[0]=='-');//判斷是否為負數 
        int As=A.size(),Bs=B.size(),ABs=As+Bs;
		
		/*
		string a.append(string b,int a,int b);
		將A後面插入B第a位開始的字元共b位 
		(在include cstring裡面) 
		*/
        if(nA&&nB) //負+負 
        {
	        B.append(A,2,As-2); //B補A的零，共As-2個零 
	        ans.append(B,1,ABs-3); //再去掉B多餘的 "-" 
        }
        else if(!nA&&!nB) //正+正 
        {
       		ans=B.append(A,1,As-1); //B加上As後面的0 
        }
        else if(nA&&!nB) //負+正 
        {
        	cout<<"-"; //補負號 
        	ans=B.append(A,2,As-2); //B加上A去掉 "-1"的字串 
        }
        else //正+負
        {
        	ans=B.append(A,1,As-1); //B加上A去掉 "1"的字串 
        }
            
        cout<<ans<<endl;
        
        //重置 
		ans="";
    }
    return 0;
}
