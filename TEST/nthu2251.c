#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>

#define MAXS 2020
/*
h : cursor left
l : cursor right
x : delete cur cursor
j : cursor down
k : cursor up

a : insert after cursor
A : insert end
i : insert before
I : insert begin
*/

/*
command -- aAiI -> insert mode
insert -- ESC -> command
command -- hjklx -> still command
j, k -> until !(j,k)
n(a,A,i,I) -> until ESC
:wq -> exit
line [1:1000]
*/
typedef struct CURSOR
{
    int line;
    int pos;
}cursor;
cursor Ccursor; //current cursor
//cursor        -> 0, 1, 2 ...
//command       -> 0, 1, 2 ...
//insert cursor -> 1, 1, 2 ...

typedef struct TEXT
{
    char c;
    text *next;
}text;

typedef struct LINE
{
    text *txt;
    int LineLength;
}line;

line L[1010];

int T;
bool mode;//0 => command, 1 => insert

text *new_txt(char c)
{
    text *tmp = malloc(sizeof(text));
    tmp->c = malloc(sizeof(char));
    return tmp;
}

void movedown(int k)
{
    Ccursor.line += k;
    if(Ccursor.line > 1000)
        Ccursor.line = 1000;
    return;
}
void moveup(int k)
{
    Ccursor.line -= k;
    if(Ccursor.line < 1)
        Ccursor.line = 1;
    return;
}
void moveleft(int k)
{
    Ccursor.pos -= k;
    if(Ccursor.pos < 1) //Warning
        Ccursor.pos = 1;
    return;
}
void moveright(int k)
{
    Ccursor.pos += k;
    if(Ccursor.pos > L[Ccursor.line].LineLength) //Warning
        Ccursor.pos = L[Ccursor.line].LineLength;
    return;
}

void insert_behind(int x, char c)//-1 => begin , -2 => end
{
    line *CL = &L[Ccursor.line];//current line
    if(x == -1)
    {
        text *t = CL->txt;
        CL->txt = new_txt(c);
        CL->txt->next = t;
    }
    //if(x == -2)
    //todo
}

void PAF(text* T)
{
    if(T == NULL)
        return;
    printf("%c", T->c);
    PAF(T->next);
    free(T);
    return;
}
void PrintAndFree()
{
    for(int i = 1; i <= 1000; i++)
    {
        if(L->LineLength > 0)
        {
            printf("%d: ", i);
            PAF(L->txt);
        }
    }
    return;
}
int main()
{
    scanf("%d\n", &T);
    for(int Case = 1; Case <= T; Case++)
    {
        mode = 0; //command mode
        char c;
        int number;
        char is_last_command_jk = 0;
        while(scanf("%c", &c) != EOF)
        {
            //printf("TestA\n");
            number = 1;
            if('0' <= c && c <= '9')//command repeat
            {
                number = c - '0';
                while(scanf("%c", &c) != EOF && ('0' <= c && c <= '9') )
                    number = 10 * number + c - '0';
            }

            if( c == 'i' || c == 'I' || c == 'a' || c == 'A')//insert
            {
                char tmp[MAXS];
                int tmpindex = 0;
                while( scanf("%c", &c) != EOF && c != 'E')
                    tmp[ tmpindex++ ] = c;
                scanf("%c%c",&c,&c);//SC
                for(int i = 0; i < number; i++)
                    for(int j = 0; j < tmpindex; j++)
                    {
                        
                    }
                //printf("insert node : %s %d %d\n",P->c,P->repeat,P->textlength);
            }
            else if( c == 'h' || c == 'l' )
            {

            }
            else if( c == 'j' || c == 'k' )
            {
                if(!is_last_command_jk)
                {
                    //if(Ccursor)
                    Ccursor.pos;
                }

                int l = Ccursor.line += (c == 'j' ? number : -number );
                if(l < 1)
                    l = 1;
                else if(l > 1000)
                    l = 1000;
                while(scanf("%c"));
                is_last_command_jk = true;
            }
            else if( c == ':')
            {
                scanf("%c%c", &c, &c);
                PrintAndFree();
            }
            

        }
        printf("Case #%d:\n", Case);
    }

    return 0;
}