#include<iostream>
using namespace std;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    char k;
    int ans=0;
    bool f=0;//判斷是否出現過數字 
    while(cin.get(k))
    {
        if(k==' ')
            if(f)//遇到空格時，判斷是否出現過數字，出現過的話答案增加 
                ans++,f=0;
        else if(k=='\n')
        {
            if(f)//與空格一樣，判斷是否出現過數字 
                ans++,f=0;
            cout<<ans<<'\n';//輸出答案 
            ans=0;//答案歸零 
        }
        else
            f=1;//出現過空格和換行以外的就紀錄為數字(本題只有數字的可能) 
    }
    return 0;
}
