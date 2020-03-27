#include<iostream>
#include<cstring>
using namespace std;

int main() {
    int Sx,Sy,Ex,Ey;
    //N,M沒用 
    cin>>Sx>>Sx>>Sx>>Sy>>Ex>>Ey;
    //只能往下往右，如果出現這種狀況就到不了 
    if(Sy>Ey||Sx>Ex)
    {
        cout<<0<<endl;
        return 0;
    }
    int x=Ex-Sx,y=Ey-Sy;//x,y長度 
    int migon[x+1][y+1];//紀錄從起點到某點有幾種走法 
    memset(migon,0,sizeof(migon));
    for(int i=0;i<=x;i++)migon[i][0]=1;//起點往右都只有一種走法 
    for(int i=0;i<=y;i++)migon[0][i]=1;//起點往下也都只有一種走法 
    for(int i=1;i<=x;i++)
    {
        for(int j=1;j<=y;j++)
        {
			//此格走法總和=從左上來+從左來+從上來 
            migon[i][j]=migon[i-1][j-1]+migon[i-1][j]+migon[i][j-1];
        }
    }
    //輸出目標位置的走法總和 
    cout<<migon[x][y]<<endl;
    return 0;
}
