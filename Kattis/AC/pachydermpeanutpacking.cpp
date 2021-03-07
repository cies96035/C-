#include<iostream>
using namespace std;
using ld = long double;

const int MAX_N = 40;

int n, m;
ld x, y;
string Type;
bool blank;

struct BOX{
    ld x1;
    ld y1;
    ld x2;
    ld y2;
    string type;
}box[MAX_N], domain;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    domain.x1 = domain.y1 = -1000;
    domain.x2 = domain.y2 = 1000;
    domain.type = "floor";

    while(cin >> n && n){
        if(blank){
            cout << '\n';
        }else{
            blank = 1;
        }

        for(int i = 0; i < n; i++){
            cin >> box[i].x1 >> box[i].y1 >> box[i].x2 >> box[i].y2 >> box[i].type;
        }
        box[n] = domain;

        cin >> m;
        while(m--){
            cin >> x >> y >> Type;
            for(int i = 0; i <= n; i++){
                if(box[i].x1 <= x && x <= box[i].x2 &&
                box[i].y1 <= y && y <= box[i].y2 ){
                    if(Type == box[i].type){
                        cout << Type << " correct\n";
                    }else{
                        cout << Type << ' ' << box[i].type << '\n';
                    }
                    break;
                }
            }
        }
    }
    return 0;
}