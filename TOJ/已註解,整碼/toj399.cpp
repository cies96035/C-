#include<iostream>
#include<cstring>
using namespace std;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
    string a,b;
    cin>>a>>b;
    if(a.size()>b.size())swap(a,b);//�w�]��b���������p 
    int flag=0,f,k=b.size()-a.size(),bs=b.size(),as=a.size();
    //flag:�D�n�קK��X�e�ɹs 
    
    for(int h=0;h<k;h++)//b��a���쪺����������X�N�n(�����^0=�����) 
        cout<<b[h];
    if(k!=0)flag=1;//�]��b��X�L�F�A�ҥH���᪺�s���n��X 
    
    
    for(int h=0;h<as;h++,k++)
    {
        if(a[h]<='9'&&a[h]>='0')
        {
            if(b[k]<='9'&&b[k]>='0')
            	f=(a[h]-'0')^(b[k]-'0');//�Ʀr^�Ʀr 
            else
            	f=(a[h]-'0')^(b[k]-'A'+10);//�Ʀr^�r�� 
        }
        else
        {
            if(b[k]<='9'&&b[k]>='0')
            	f=(a[h]-'A'+10)^(b[k]-'0');//�r��^�Ʀr 
            else
            	f=(a[h]-'A'+10)^(b[k]-'A'+10);//�Ʀr^�Ʀr 
        }
        
        //��X 
        if(flag||f!=0)//����X�{�Ĥ@�ӫD�s�H�~���Ƭ������X(����X�e�ɹs) 
        {
            if(f<=9)
            	cout<<f;//�p�Gf���Ʀr�A������X 
            else
            	cout<<(char)(f+'A'-10);//�_�h�ഫ���r��
			if(!flag)//�X�{�����D�s�H�~���ơA���᳣�i�H������X
            	flag=1; 
        }   
    }
    if(!flag)cout<<0;//�p�G�q�ӨS����X�L�A�h��X0 
	cout<<endl;//�̫ᴫ�� 
    
    return 0;
}
