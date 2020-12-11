#include<iostream>
#include<cstring>
using namespace std;
#define MAXS 1100
int DP[MAXS][MAXS];
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    string first_string;
    string second_string;
    while( getline(cin,first_string) && getline(cin,second_string) )
    {
        for(int i = 0 ; i < first_string.size() ; i++)
        {
            for(int j = 0 ; j < second_string.size() ; j++)
            {
                if(first_string[i]==second_string[j])
                    DP[i+1][j+1]=DP[i][j]+1;
                else
                    DP[i+1][j+1]=max(DP[i+1][j], DP[i][j+1]);
            }
        }
        cout<<DP[first_string.size()][second_string.size()]<<'\n';
    }
    return 0;
}