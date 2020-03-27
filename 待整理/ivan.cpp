#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
string s;
#define maxn 10000001
int c[maxn][6],k,val[6][6];//c[i][j] i是在k字串的第幾個 j=1->a  j=2->b .....
int a=0,b=0,cc=0,d=0,e=0;
void print(){
    for(int i=1;i<=5;i++){
        cout<<(char)(i+'a'-1)<<": ";
        for(int j=0;j<k;j++){
            cout<<c[j][i]<<' ';
        }
        cout<<endl;
    }
}
int main(){//io;
    cin>>s>>k;
    memset(c,0,sizeof(c));
    for(int i=k-1;i<int(s.size()-k+1);i++){
        if(s[i]=='a')a++;
        if(s[i]=='b')b++;
        if(s[i]=='c')cc++;
        if(s[i]=='d')d++;
        if(s[i]=='e')e++;
    }
    for(int i=0;i<k;i++){
        c[i][1]=a;
        c[i][2]=b;
        c[i][3]=cc;
        c[i][4]=d;
        c[i][5]=e;
    }
    for(int i=0;i<k-1;i++){
        if(s[i]=='a'){
            for(int j=0;j<i+1;j++){
                c[j][1]++;
            }
        }
        if(s[i]=='b'){
            for(int j=0;j<i+1;j++){
                c[j][2]++;
            }
        }
        if(s[i]=='c'){
            for(int j=0;j<i+1;j++){
                c[j][3]++;
            }
        }
        if(s[i]=='d'){
            for(int j=0;j<i+1;j++){
                c[j][4]++;
            }
        }
        if(s[i]=='e'){
            for(int j=0;j<i+1;j++){
                c[j][5]++;
            }
        }
    }
    for(int i=int(s.size())-1;i>=int(s.size())-(k-1);i--){
        if(s[i]=='a'){
            for(int j=0;j<int(s.size())-i;j++){
                c[k-1-j][1]++;
            }
        }
        if(s[i]=='b'){
            for(int j=0;j<int(s.size())-i;j++){
                c[k-1-j][2]++;
            }
        }
        if(s[i]=='c'){
            for(int j=0;j<int(s.size())-i;j++){
                c[k-1-j][3]++;
            }
        }
        if(s[i]=='d'){
            for(int j=0;j<int(s.size())-i;j++){
                c[k-1-j][4]++;
            }
        }
        if(s[i]=='e'){
            for(int j=0;j<int(s.size())-i;j++){
                c[k-1-j][5]++;
            }
        }
    }
    print();
    for(int i=1;i<=5;i++){
        for(int j=1;j<=5;j++){
            cin>>val[i][j];
        }
    }
    for(int i=0;i<k;i++){//each char of string
        //cout<<"k index"<<i<<": ";
        long long mx=LONG_LONG_MIN;
        int f='a';
        for(int j=1;j<=5;j++){//choose color
            long long tmp=0;
            for(int s=1;s<=5;s++){//multi
                tmp+=(val[s][j]/*value*/*c[i][s]/*number*/);
            }
            if(tmp>mx){
                mx=tmp;
                f=j+'a'-1;
            }
        }
        cout<<(char)f;
    }
    cout<<endl;
    return 0;
}
