#include<stdio.h>
#include<string.h>

void print_dungeon(int maze[8][8],int road[8][8]) {
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      if (maze[i][j] == -1)
        printf("*");
      else if (maze[i][j] == 100)
        printf("$");
      else if (maze[i][j] == 0 || road[i][j]==0)
        printf(" ");
      else
        printf("%d",maze[i][j]);
    }
    printf("\n");
  }
}

struct PII
{
    int x,y;
};

struct PII Pii(int a,int b)
{
    struct PII tmp;
    tmp.x=a;
    tmp.y=b;
    return tmp;
}

int inbound(struct PII o)
{
    return 0<=o.x && o.x<8 && 0<=o.y && o.y<8;
}

struct PII mv(struct PII o,int m)
{
    if(m==0)
        return Pii(o.x-1,o.y);
    if(m==1)
        return Pii(o.x+1,o.y);
    if(m==2)
        return Pii(o.x,o.y-1);
    if(m==3)
        return Pii(o.x,o.y+1);
}

struct Queue
{
    int s,e;
    struct PII arr[1000];
};

void push(struct Queue *a,struct PII x)
{
    a->arr[a->e++]=x;
}
struct PII front(struct Queue a)
{
    return a.arr[a.s];
}
void pop(struct Queue *a)
{
    a->s++;
}
int Empty(struct Queue a)
{
    return a.s==a.e;
}

int main()
{
    //initial place
    struct PII p;
    scanf("%d%d",&p.x,&p.y);

    //maze
    int maze[8][8];
    for(int i=0;i<8;i++)
        for(int j=0;j<8;j++)
            scanf("%d",&maze[i][j]);

    //v -> where it come from
    struct PII v[8][8];
    struct PII E;//end
    //BFS
    struct Queue q;
    q.s=q.e=0;
    push(&q,p);
    maze[p.x][p.y]=1;
    v[p.x][p.y]=Pii(-1,-1);

    while(!Empty(q))
    {
        struct PII T=front(q);
        pop(&q);
        if(maze[T.x][T.y]==100)
        {
            E=T;
            break;
        }
        for(int i=0;i<4;i++)
        {
            struct PII nx=mv(T,i);
            if(inbound(nx))
            {
                if(maze[nx.x][nx.y]==0)
                {
                    maze[nx.x][nx.y]=maze[T.x][T.y]+1;
                    v[nx.x][nx.y]=Pii(T.x,T.y);
                    push(&q,nx);
                }
                else if(maze[nx.x][nx.y]==100)
                {
                    v[nx.x][nx.y]=Pii(T.x,T.y);
                    push(&q,nx);
                }
            }
        }
    }
    int road[8][8];
    memset(road,0,sizeof(int)*8*8);
    while(v[E.x][E.y].x!=-1)
    {
        E=v[E.x][E.y];
        road[E.x][E.y]=1;
    }
    print_dungeon(maze,road);


    return 0;
}