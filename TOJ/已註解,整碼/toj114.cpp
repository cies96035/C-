#include<iostream>
using namespace std;

int main() {
    int disk[5][6];
    for(int i=0;i<5;i++)
        for(int j=0;j<6;j++)
            cin>>disk[i][j];
            
    for(int j=0;j<5;j++)//判斷直行 
        for(int i=0;i<3;i++)
            if(disk[i][j]==disk[i+1][j]&&disk[i][j]==disk[i+2][j])
            {
                cout<<"Yes"<<endl;
                return 0;
			}
                
                
    for(int i=0;i<5;i++)//判斷橫行 
        for(int j=0;j<4;j++)
            if(disk[i][j]==disk[i][j+1]&&disk[i][j]==disk[i][j+2])
            {
                cout<<"Yes"<<endl;
                return 0;
            }
            
    cout<<"No"<<endl;
    return 0;
}
