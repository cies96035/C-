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
        
        if(A=="0"||B=="0") //�O�_���H�s���S�� 
        {
            cout<<"0"<<endl;
            continue;
        }
        
        bool nA=(A[0]=='-'),nB=(B[0]=='-');//�P�_�O�_���t�� 
        int As=A.size(),Bs=B.size(),ABs=As+Bs;
		
		/*
		string a.append(string b,int a,int b);
		�NA�᭱���JB��a��}�l���r���@b�� 
		(�binclude cstring�̭�) 
		*/
        if(nA&&nB) //�t+�t 
        {
	        B.append(A,2,As-2); //B��A���s�A�@As-2�ӹs 
	        ans.append(B,1,ABs-3); //�A�h��B�h�l�� "-" 
        }
        else if(!nA&&!nB) //��+�� 
        {
       		ans=B.append(A,1,As-1); //B�[�WAs�᭱��0 
        }
        else if(nA&&!nB) //�t+�� 
        {
        	cout<<"-"; //�ɭt�� 
        	ans=B.append(A,2,As-2); //B�[�WA�h�� "-1"���r�� 
        }
        else //��+�t
        {
        	ans=B.append(A,1,As-1); //B�[�WA�h�� "1"���r�� 
        }
            
        cout<<ans<<endl;
        
        //���m 
		ans="";
    }
    return 0;
}
