#include<iostream>
using namespace std;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    string S;
    int T;
    cin >> T;
    while(T--)
    {
        cin >> S;
        int Ss=S.size();
        //Case 1
        if(S=="1" || S=="4" || S=="78")
            cout<<"+\n";
        //Case 2
        else if(S[Ss-2]=='3' && S[Ss-1]=='5')
            cout<<"-\n";
        //Case 3
        else if(S[0]=='9' && S[Ss-1]=='4')
            cout<<"*\n";
        //Case 4
        else if(S[0]=='1' && S[1]=='9' && S[2]=='0')
            cout<<"?\n";
    }
    return 0;
}