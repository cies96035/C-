#include<iostream>
#include<cmath>
using namespace std;

int T;
string text;
int n;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> T;
    while(T--){
        cin >> text;
        n = sqrt(text.size());
        for(int i = 0 ,t = n - 1; i < text.size(); i++){
            cout << text[t];
            t += n;
            if(t > text.size()){
                t -= text.size();
                t--;
            }
        }
        cout << '\n';
    }
    return 0;
}