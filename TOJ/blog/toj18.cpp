#include<iostream>
using namespace std;

//�P�_�O���O�^��r�� 
bool isletter(char achartojudge)
{
	return (achartojudge>='A'&&achartojudge<='Z')||(achartojudge>='a'&&achartojudge<='z');
}

int main()
{
    string Spell,ToJudge;//�x�s�G��ΧP�_�Ϊ��r�� 
    while(getline(cin,Spell))
    {    
        long long Ssize=Spell.size();
        
        //�N�G��s�@���P�_�Ϊ�(�u���^��+�p�g,�H�Q�P�_ 
        for(int i=0;i<Ssize;i++)
        {
            //�P�_�O�_���^��(�u���^��)
            if(isletter(Spell[i]))
            {
            	//�O�^�媺�ܥu���p�g 
                ToJudge+=(char)tolower(Spell[i]);
            }
        }
        
		bool notpalindrome=0;
        for(long long a=0,TJsize=ToJudge.size()-1;a<TJsize;TJsize--,a++)//�P�_�O�_���^��,�A�̷ӧP�_���G��X 
        {
            if(ToJudge[TJsize]!=ToJudge[a])
            {
                //�p�G�X�{�Y�����@�˪����p
                //����j��A�åB�аOout
                notpalindrome=1;
                break;
            }
        }
        
        //�p�Gout���аO��A�N��X�{�Y�����@�˪����p 
        //�Ϥ��A�N��j���ˬToJudge�᳣�@�ˡA�P�_���G��X 
        if(notpalindrome)cout<<Spell<<endl;
        else cout<<"SETUP! "<<Spell<<endl;
        //���mToJudge 
        ToJudge="";
    }
    return 0;
}

