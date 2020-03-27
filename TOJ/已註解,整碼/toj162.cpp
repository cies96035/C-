#include<iostream>
#include<cstring>
using namespace std;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
    int T;
    cin>>T;
    while(T--)
    {
        cin.ignore();//吃掉\n，不然讀不到名子 
        string PlayerX,PlayerO;//儲存名子 
        int OOXX[3][3];
		bool getscoreX=0,getscoreO=0;
        getline(cin,PlayerX);
        getline(cin,PlayerO);
        
        /* 輸入
        00 01 02
        10 11 12
        20 21 22
        */ 
        for(int i=0;i<3;i++)
            for(int j=0;j<3;j++)
                cin>>OOXX[i][j];
             
        //判斷直行是否相同，同時判斷誰得分 
        for(int x=0;x<3;x++)
            if(OOXX[0][x]==OOXX[1][x]&&OOXX[0][x]==OOXX[2][x]&&OOXX[0][x]!=2)
                OOXX[0][x]?getscoreX=1:getscoreO=1;//連線的是1，X得分,否則Y得分 
                
        //判斷橫行是否相同，相同時判斷誰得分
        for(int y=0;y<3;y++)
            if(OOXX[y][0]==OOXX[y][1]&&OOXX[y][0]==OOXX[y][2]&&OOXX[y][0]!=2)
                OOXX[y][0]?getscoreX=1:getscoreO=1;
        
        
        //判斷左上右下斜行是否相同，相同時判斷誰得分
        if(OOXX[0][0]==OOXX[1][1]&&OOXX[0][0]==OOXX[2][2]&&OOXX[0][0]!=2)
            OOXX[0][0]?getscoreX=1:getscoreO=1;
        
        //判斷右上左下斜行是否相同，相同時判斷誰得分
        if(OOXX[0][2]==OOXX[1][1]&&OOXX[0][2]==OOXX[2][0]&&OOXX[0][2]!=2)
            OOXX[0][2]?getscoreX=1:getscoreO=1;
        
        //判斷得分狀況 
        if(!getscoreX&&!getscoreO)cout<<"Not yet"<<endl;//如果都沒得過分 
        else if(getscoreO&&getscoreX)cout<<"Impossible"<<endl;//如果兩個都有得分 
        else if(getscoreX)cout<<PlayerX<<endl;//只有X得分 
        else cout<<PlayerO<<endl;//只有O得分 
    }
    return 0;
}
