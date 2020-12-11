#include<iostream>
#include<cstring>
#include<set>
using namespace std;

#define maxS 1000


#define Test //comment if you want to test

/*
  (0,0) - > j strB
    |
    v
  i strA
*/


struct DP
{
    bool fromLeft;   //Is the LCSLength come from Left
    bool fromUpLeft; //Is the LCSLength come from UpLeft
    bool fromUp;     //Is the LCSLength come from Up
    int LCSLength;   //The LCSLength
};
DP dp[maxS][maxS];

string A, B; //two input string
set<string> setLCS; //recording LCS

void findLCS(int i, int j, string str)
{
    DP S=dp[i][j];

    #ifdef Test
    cout << "findLCS(" << i << ',' << j << ",\"" << str << "\")" << endl;
    cout << S.fromLeft << " , " << S.fromUp << " , " << S.fromUpLeft << endl;
    #endif

    if(S.LCSLength==0)
    {
        setLCS.insert(str);
        //return;
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

    //memset(dp, 0, sizeof(DP) * maxS * maxS);

    cin >> A >> B;
    for(int i = 0 ; i < A.size() ; i++)
        for(int j = 0 ; j < B.size() ; j++)
        {
            if(A[i] == B[j])
            {
                #if defined(Test)
                    cout << "A[" << i << "] == " << "B[" << j << "]"<<endl;
                #endif
                dp[i + 1][j + 1].fromUpLeft = true;
                dp[i + 1][j + 1].LCSLength = dp[i][j].LCSLength + 1;
            }
            else
            {
                #if defined(Test)
                    cout << "A[" << i << "] != " << "B[" << j << "]"<<endl;
                #endif

                const int 
                UL = dp[i][j].LCSLength,
                U  = dp[i][j + 1].LCSLength,
                L  = dp[i + 1][j].LCSLength;

                const int Max=max(max(U , L) , UL);
                
                if(UL == Max && !(U == Max || L == Max) )
                    dp[i + 1][j + 1].fromUpLeft = true;
                if(U == Max)
                    dp[i + 1][j + 1].fromUp = true;
                if(L == Max)
                    dp[i + 1][j + 1].fromLeft = true;
                
                dp[i + 1][j + 1].LCSLength = Max;
            }
            #if defined(Test)
                cout << "dp[" << i + 1 << "][" << j + 1 << "] from:"<<endl;
                if(dp[i][j].fromLeft)
                    cout << "Left ";
                if(dp[i][j].fromUp)
                    cout << "Up ";
                if(dp[i][j].fromUpLeft)
                    cout << "UpLeft ";
                cout << endl;
            #endif
        }
        cout << "LCS Length: " << dp[A.size()][B.size()].LCSLength << '\n';

        findLCS(A.size(), B.size(), "");

        cout << "LCS amounts: " << setLCS.size() << '\n';

        int id = 0;
        for(set<string>::iterator i = setLCS.begin() ; i != setLCS.end() ; i++)
            cout << id++ << " : " << *i << '\n';
        return 0;
}