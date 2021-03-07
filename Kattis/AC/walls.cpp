#include<iostream>
#include<climits>
using namespace std;

int l, w, n, r;
int x, y;
bool wall[16];
int tmp;
int Min = INT_MAX;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> l >> w >> n >> r;
    r *= 2;
    for(int i = 0; i < n; i++){
        cin >> x >> y;
        x *= 2;
        y *= 2;
        tmp = 0;
        if((x + l) * (x + l) + y * y <= r * r){
            tmp += 8;
        }
        if((x - l) * (x - l) + y * y <= r * r){
            tmp += 4;
        }
        if(x * x + (y + w) * (y + w) <= r * r){
            tmp += 2;
        }
        if(x * x + (y - w) * (y - w) <= r * r){
            tmp += 1;
        }
        wall[tmp] = true;
    }
    
    for(int i = 0; i < 16; i++){
        if(!wall[i]){
            continue;
        }
        if((i == 15) && Min > 1){
            Min = 1;
        }
        for(int j = i + 1; j < 16; j++){
            if(!wall[j]){
                continue;
            }
            if((i | j) == 15 && Min > 2){
                Min = 2;
            }
            for(int k = j + 1; k < 16; k++){
                if(!wall[k]){
                    continue;
                }
                if((i | j | k) == 15 && Min > 3){
                    Min = 3;
                }
                for(int l = k + 1; l < 16; l++){
                    if(!wall[l]){
                        continue;
                    }
                    if((i | j | k | l) == 15 && Min > 4){
                        Min = 4;
                    }
                }
            }
        }
    }
    if(Min != INT_MAX){
        cout << Min << '\n';
    }else{
        cout << "Impossible\n";
    }
    return 0;
}