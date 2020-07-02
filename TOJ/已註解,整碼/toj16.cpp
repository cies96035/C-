#include<iostream>
#include<cstring>
using namespace std;
int main()
{
    //cin加速
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    //T筆測資
    int T;
    cin>>T;
    while(T--)
    {
        int S,Q,W;
		bool cantake[30000];
        memset(cantake,0,sizeof(cantake));

        //輸入心情指數
        cin>>S;
        int emotion[S];
        for(int i=0;i<S;i++)cin>>emotion[i];

        //處理心情指數
        for(int a=0;a<S;a++)
            for(int b=a+1;b<S;b++)
                if(emotion[a]&&emotion[b]&&!(cantake[emotion[a]+emotion[b]]))
                    cantake[emotion[a]+emotion[b]]=1;

        //判斷並輸出
        cin>>Q;
        while(Q--)
        {
            cin>>W;
            if(cantake[W])cout<<"Good!\n";
            else cout<<"So Bad!\n";
        }

    }
    return 414314;
}
