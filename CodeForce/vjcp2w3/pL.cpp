//
//  main.cpp
//  kattis
//
//  Created by ray on 2021/1/28.
//  Copyright © 2021年 ray. All rights reserved.
//
 
#include <iostream>
#include<stdio.h>
#include <deque>
#include<iomanip>
#include<queue>
#include<memory.h>
#include<algorithm>
#include<string>
#include<math.h>
#include<stack>
#include<set>
#include<map>
#include<vector>
using namespace std;
#define mod 1000000007
long long mat[75][5][5]={0},ans[5]={0};
 
int main(int argc, const char * argv[])
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    long long t;
    cin>>t;
    mat[0][4][0]=2;
    mat[0][4][1]=2;
    mat[0][4][2]=5;
    mat[0][4][3]=2;
    mat[0][4][4]=1;
    for(int i=1;i<4;i++)
    {
        mat[0][i][i+1]=1;
    }
    ans[0]=1;
    for(int i=1;i<5;i++)
    {
        ans[i]+=mat[0][4][4-i];
        for(int j=0;j<i;j++)ans[i]+=ans[j]*mat[0][4][5-(i-j)];
    }
    for(int i=1;i<70;i++)
    {
        for(int j=0;j<5;j++)
        {
            for(int k=0;k<=5;k++)
            {
                for(int l=0;l<5;l++)
                {
                    mat[i][j][k]=(mat[i][j][k]+(mat[i-1][j][l]*mat[i-1][l][k]%mod))%mod;
                }
            }
        }
    }
    while(t--)
    {
        long long n;
        cin>>n;
        if(n<=5)
        {
            cout<<ans[n-1]<<endl;
        }
        else
        {
            long long rel[5],sa[5]={0};
            for(int i=0;i<5;i++)rel[i]=ans[i];
            n-=5;
            int poi=0;
            while(n>0)
            {
                if(n%2!=0)
                {
                    memset(sa,0,sizeof(sa));
                    for(int i=0;i<5;i++)
                    {
                        for(int j=0;j<5;j++)
                        {
                            sa[i]=(sa[i]+(rel[j]*mat[poi][i][j]%mod))%mod;
                        }
                    }
                    for(int i=0;i<5;i++)rel[i]=sa[i];
                }
                n/=2;
                poi++;
            }
            cout<<rel[4]<<endl;
        }
    }
    return 0;
}