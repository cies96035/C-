#include<iostream>
using namespace std;

int gcd(int a,int b)
{
    while((a%=b)&&(b%=a));
    return a+b;
}

int main() {
	
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
    char k;
    //��@���l,��@����,���l�n,�����n 
    int kid=0,mom=0,kidsum=1,momsum=1;
    bool flag=1,flag2=0;
	//flag���}�N��������l�A���_�ӫh�O������ 
	//flag2�P�_�O�_�n����l���i�`�n�̡A�קK�h�ӪŮ檺���p�X�� 
    while(cin.get(k))
    {
        if(k>='0'&&k<='9'&&flag)//���l 
        {
            kid=kid*10+k-'0';
            flag2=1;
        }
        else if(k>='0'&&k<='9')//���� 
        {
            mom=mom*10+k-'0';
            flag2=1;
        }
        if(k=='/')
        {
            flag=0;
        }
        if((k==' '||k=='\n')&&flag2)
        {
            kidsum*=kid;
            if(mom!=0)//�p�Gmom�S�O����(�]�N�O�D���ơA�h���ά��� 
                momsum*=mom;
            kid=mom=0;//�k�s 
            flag2=0;
            flag=1;
        }
        if(k=='\n')
        {
        	//���� 
            int GCD=gcd(kidsum,momsum);
            kidsum=kidsum/GCD;
            momsum=momsum/GCD;
            if(momsum!=1)//�p�G������1�h���ο�X���� 
                cout<<kidsum<<'/'<<momsum<<endl;
            else
                cout<<kidsum<<endl;
            kidsum=momsum=1;//�٭� 
        }
    }
    return 0;
}

