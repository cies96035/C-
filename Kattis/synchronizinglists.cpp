#include<iostream>
#include<algorithm>
using namespace std;

const int MAX_N = 5050;
int n;
int Flist[MAX_N], Slist[MAX_N], Flistcpy[MAX_N];
int *order;
bool blankLine;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    order = new int[20020] + 10010;

    while(cin >> n && n){
        if(blankLine){
            cout << '\n';
        }else{
            blankLine = true;
        }
        for(int i = 0; i < n; i++){
            cin >> Flist[i];
            Flistcpy[i] = Flist[i];
        }
        for(int i = 0; i < n; i++){
            cin >> Slist[i];
        }
        sort(Flist, Flist + n);
        sort(Slist, Slist + n);
        for(int i = 0; i < n; i++){
            order[Flist[i]] = Slist[i];
        }

        for(int i = 0; i < n; i++){
            cout << order[Flistcpy[i]] << '\n';
        }
    }
    return 0;
}