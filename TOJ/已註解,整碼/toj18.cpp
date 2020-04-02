#include<iostream>
using namespace std;

//判斷是不是英文字母 
bool isletter(char achartojudge)
{
	return (achartojudge>='A'&&achartojudge<='Z')||(achartojudge>='a'&&achartojudge<='z');
}

int main()
{
    string Spell,ToJudge;//儲存咒文及判斷用的字串 
    while(getline(cin,Spell))
    {    
        long long Ssize=Spell.size();
        
        //將咒文製作成判斷用的(只取英文+小寫,以利判斷 
        for(int i=0;i<Ssize;i++)
        {
            //判斷是否為英文(只取英文)
            if(isletter(Spell[i]))
            {
            	//是英文的話只取小寫 
                ToJudge+=(char)tolower(Spell[i]);
            }
        }
        
		bool notpalindrome=0;
        for(long long a=0,TJsize=ToJudge.size()-1;a<TJsize;TJsize--,a++)//判斷是否為回文,再依照判斷結果輸出 
        {
            if(ToJudge[TJsize]!=ToJudge[a])
            {
                //如果出現頭尾不一樣的狀況
                //跳脫迴圈，並且標記out
                notpalindrome=1;
                break;
            }
        }
        
        //如果out有標記到，代表出現頭尾不一樣的狀況 
        //反之，代表迴圈檢曷oJudge後都一樣，判斷結果輸出 
        if(notpalindrome)cout<<Spell<<endl;
        else cout<<"SETUP! "<<Spell<<endl;
        //重置ToJudge 
        ToJudge="";
    }
    return 0;
}

