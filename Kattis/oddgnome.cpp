#include<iostream>
using namespace std;

const int MAX_G = 1010;

int n;
int g;
int king;
int gnome[MAX_G];

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> g;
        king = -1;
        for(int j = 1; j <= g; j++){
            cin >> gnome[j];
        }
        for(int j = 2; j < g; j++){
            if(gnome[j - 1] < gnome[j + 1] && ( gnome[j - 1] > gnome[j] || gnome[j + 1] < gnome[j] )){
                king = j;
            }
        }
        if(king == -1){
            if(gnome[1] > gnome[2]){
                king = 1;
            }else if(gnome[g - 1] > gnome[g]){
                king = g;
            }
        }
        cout << king << '\n';
    }
    return 0;
}