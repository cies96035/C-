#include<iostream>
#include<algorithm>
using namespace std;

const int MAX_NM = 20200;
int dragon[MAX_NM];
int knight[MAX_NM];
int cost;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    int n, m;
    while(cin >> n >> m && n && m){

        cost = 0;
        for(int i = 0; i < n; i++){
            cin >> dragon[i];
        }
        for(int i = 0; i < m; i++){
            cin >> knight[i];
        }

        sort(dragon, dragon + n);
        sort(knight, knight + m);

        int i = 0, j = 0;
        while(i < n && j < m){
            while(j < m && dragon[i] > knight[j]){
                j++;
            }
            if(j < m){
                cost += knight[j];
                i++;
            }
            j++;
        }
        if(i == n){
            cout << cost << '\n';
        }else{
            cout << "Loowater is doomed!\n";
        }
    }
    return 0;
}