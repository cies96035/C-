#include<iostream>
using namespace std;

int w, l;
int n;
char op;
int t;
int x, y;
int robotX, robotY;
bool blank;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    while(cin >> w >> l && w && l){
        x = y = robotX = robotY = 0;
        cin >> t;
        while(t--){
            cin >> op >> n;
            if(op == 'u'){
                y += n;
                robotY += n;
                if(y >= l){
                    y = l - 1;
                }
            }else if(op == 'd'){
                y -= n;
                robotY -= n;
                if(y < 0){
                    y = 0;
                }
            }else if(op == 'r'){
                x += n;
                robotX += n;
                if(x >= w){
                    x = w - 1;
                }
            }else{
                x -= n;
                robotX -= n;
                if(x < 0){
                    x = 0;
                }
            }
        }
        if(blank){
            cout << '\n';
        }else{
            blank = true;
        }
        cout << "Robot thinks " << robotX << ' ' << robotY << '\n';
        cout << "Actually at " << x << ' ' << y << '\n';
    }

    return 0;
}