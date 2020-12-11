#include<iostream>
#include<cstring>
#include<set>
using namespace std;

#define maxS 1000


/*
  (0,0) - > j
    |
    v
    i
*/

struct DP
{
    bool fromLeft;
    bool fromUpLeft;
    bool fromUp;
    int LCSLength;
};

set<string> setLCS;
DP dp[maxS][maxS];
string A, B;

void findLCS(int i, int j, string str)
{
    //cout<<i<<j<<endl;
    //cout<<S.fromLeft<<S.fromUp<<S.fromUpLeft<<endl;
    //cout<<s<<endl;
    DP S=dp[i + 1][j + 1];

    if(S.LCSLength==0)
    {
        setLCS.insert(str);
        return;
    }

    if(S.fromUp)
        findLCS(i - 1, j, str);

    if(S.fromLeft)
        findLCS(i, j - 1, str);
        
    if(S.fromUpLeft)
        findLCS(i - 1, j - 1, A[i - 1] + str);
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    //memset(N, 0, sizeof(S) * maxS * maxS);

    cin >> A >> B;
    for(int i = 0 ; i < A.size() ; i++)
        for(int j = 0 ; j < B.size() ; j++)
        {
            if(A[i] == B[j])
            {
                dp[i + 1][j + 1].fromUpLeft = true;
                dp[i + 1][j + 1].LCSLength = dp[i][j].LCSLength + 1;
            }
            else
            {
                const int 
                UL = dp[i][j].LCSLength,
                U  = dp[i][j+1].LCSLength,
                L  = dp[i+1][j].LCSLength;

                const int Max=max(max(U , L) , UL);
                if(UL == Max && !(U == Max || L == Max) )
                    dp[i+1][j+1].fromUpLeft = true;
                if(U == Max)
                    dp[i+1][j+1].fromUp = true;
                if(L == Max)
                    dp[i+1][j+1].fromLeft = true;
                
                dp[i+1][j+1].LCSLength = Max;
            }
        }
        cout << "Max Length: " << dp[ A.size() ][ B.size() ].LCSLength << '\n';

        findLCS(A.size(), B.size(), "");

        cout << "LCS amounts: " << setLCS.size() << '\n';

        for(set<string>::iterator i = setLCS.begin() ; i != setLCS.end() ; i++)
            cout << *i << '\n';
        return 0;
}