#include<bits/stdc++.h>
using namespace std;

const int MAX_N = 15;
struct POINT{
    int x, y, z;
    bool operator <(const POINT & a)const {
        return 
        x == a.x ? t
        (y == a.y ? z < a.z : y < a.y) : 
        z < a.x;
    }
};
map<POINT, int> DP[MAX_N];
int Re(int depth){
    
}
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    return 0;
}