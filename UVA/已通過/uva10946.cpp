#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

#define maxN 100
int n,m;
char table[maxN][maxN];

struct G
{
    G():W(0),amount(0){};
    G(char c,int i):W(c),amount(i){};
    char W;
    int amount;
};
class pos
{
    public:
        pos(int a,int b):x(a),y(b){}
        int x;
        int y;
        pos operator+(pos a)
        {
            return pos(this->x+a.x,this->y+a.y);
        }
        bool insideR(int a,int b)
        {
            return (0<=x&&x<a&&0<=y&&y<b);
        }
};
G BFS(int a,int b)
{
    pos mv[4]={{0,1},{0,-1},{1,0},{-1,0}};

    char c=table[a][b];
    int cnt=0;
    queue<pos> togo;
    togo.push(pos(a,b));
    table[a][b]='.';
    while(!togo.empty())
    {
        pos cur=togo.front();
        togo.pop();
        cnt++;
        for(int i=0;i<4;i++)
        {
            pos nx=mv[i]+cur;
            if(nx.insideR(n,m)&&table[nx.x][nx.y]==c)
            {
                togo.push(nx);
                table[nx.x][nx.y]='.';
            }
        }
    }
    return G(c,cnt);
}
bool cmp(G a,G b)
{
    return (a.amount==b.amount) ? (a.W<b.W) : (a.amount>b.amount);
}
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int Case=0;
    while(cin>>n>>m&&n&&m)
    {
        vector<G> g;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                cin>>table[i][j];

        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if(table[i][j]!='.')
                    g.emplace_back(BFS(i,j));
        sort(g.begin(),g.end(),cmp);

        cout<<"Problem "<<++Case<<":\n";
        for(int i=0;i<g.size();i++)
            cout<<g[i].W<<' '<<g[i].amount<<endl;
    }
    return 0;
}