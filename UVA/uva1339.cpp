#include<iostream>
#include<algorithm>
using namespace std;

#define letter_to_id(word) (word-'A')
#define wordsize 26

string origin,after;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    while(cin>>origin>>after)
    {
        //the amount of each letters
        int Origin[wordsize]={0},After[wordsize]={0};
        bool Y=1;
        for(unsigned int i=0;i<origin.size();i++)
        {
            Origin[letter_to_id(origin[i])]++;
            After[letter_to_id(after[i])]++;
        }

        //sort
        sort(Origin,Origin+wordsize);
        sort(After,After+wordsize);

        //if it cant one to one , Y(the flag)=0
        for(int i=0;i<wordsize;i++)
            if(Origin[i]!=After[i])
                Y=0;

        if(Y)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
