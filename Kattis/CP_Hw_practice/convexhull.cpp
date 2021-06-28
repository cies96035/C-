#include<bits/stdc++.h>
using namespace std;

const int MAX_N = 10000;
int n;
struct POINT{
    int x;
    int y;
    int dx;
    int dy;
    void Setdxy(const POINT &a){
        dx = a.x - x;
        dy = a.y - y;
    }
    bool operator <(const POINT &b)const{
        return x == b.x ? y < b.y : x < b.x;
    }
    bool operator !=(const POINT &b)const{
        return x != b.x || y != b.y;
    }
}points[MAX_N];

bool cmp(const POINT &a, const POINT &b){
    if(a.dx == 0)
        return 0;
    else if(b.dx == 0)
        return 1;
    int t = a.dy * b.dx - b.dy * a.dx;
    return t == 0 ? a.dx > b.dx : t < 0;
}

bool checkdir(const POINT &a, const POINT &b, const POINT &c){
    // ||ba x bc||
    // > 0 counterclock
    int t = (a.x - b.x) * (c.y - b.y) - (c.x - b.x) * (a.y - b.y);
    return t >= 0;
}
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    while(cin >> n && n){
        //input
        for(int i = 0; i < n; i++){
            cin >> points[i].x >> points[i].y;
            if(points[i] < points[0]){
                swap(points[0], points[i]);
            }
        }

        //set angle and sort
        for(int i = 1; i < n; i++){
            points[i].Setdxy(points[0]);
        }
        sort(points + 1, points + n, cmp);
        points[n] = points[0];

        stack<POINT> convexhull;
        
        convexhull.push(points[0]);
        convexhull.push(points[1]);
        for(int i = 0; i < n; i++){
            cout << "sorttest" << points[i].x << ' ' << points[i].y << endl;
        }
        POINT a, b;
        for(int i = 2; i <= n; i++){
            b = convexhull.top(); convexhull.pop();
            a = convexhull.top(); convexhull.pop();
            while(checkdir(a, b, points[i])){
                b = a;
                if(convexhull.empty()){
                    break;
                }else{
                    a = convexhull.top(); convexhull.pop();
                }
            }
            convexhull.push(a);
            convexhull.push(b);
            convexhull.push(points[i]);
        }
        convexhull.pop();

        stack<POINT> ans;
        ans.push(convexhull.top());
        convexhull.pop();
        while(!convexhull.empty()){
            if(ans.top() != convexhull.top()){
                ans.push(convexhull.top());
            }
            convexhull.pop();
        }

        cout << ans.size() << '\n';
        while(!ans.empty()){
            cout << ans.top().x << ' ' << ans.top().y << '\n';
            ans.pop();
        }
    }

    return 0;
}

/*
8
0 0 
2 1
4 2
4 3
4 4
3 4
2 4
1 2
0
*/