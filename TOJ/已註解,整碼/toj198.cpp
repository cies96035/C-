/*
�z�פW�D����
�t�פ�L�H�C�ܦh
���٬O��L 
*/ 

#include<iostream>
#include<cstring>
using namespace std;

//�N�^��H�~���h���A�ñN�^��Φ��p�g�H�Q�P�_ 
string strtouse(string k)
{
	string d;
	int klen=k.size();
    for(int h=0;h<klen;h++)
    {
        //�P�_�O�_���^��(�u���^��)
        if((k[h]>='A'&&k[h]<='Z')||(k[h]>='a'&&k[h]<='z'))
        {
            //�O���ܤ@�ߥΤp�g�s�id�r�� 
            d+=tolower(k[h]);
        }
    }
    return d;
}
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    string a,b;
    while(getline(cin,a))
    {
        getline(cin,b);
        a=strtouse(a);
        b=strtouse(b);
        /*
		a.find(b,num)�Acstring�̪���� 
		�qa�r�ꪺ��num���b�r��
		���^�Ǧ�m�A�䤣��^��-1 
		*/ 
        if(a.find(b,0)!=-1)cout<<"Yes\n";
        else cout<<"No\n";
    }
    return 0;
}
