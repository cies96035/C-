#include<iostream>
using namespace std;


enum Type {NOVEL, COMICS, MANUAL, TEXTBOOK};
 
struct Book {
    char title[128];
    enum Type type;
    char ISBN[128];
    char authors[128];
    unsigned int importance;
};

struct Date {
    unsigned int year;
    unsigned int month;
    unsigned int day;
};


int monthday[13]={0,31,59,90,120,151,181,212,243,273,304,334,365};
int overd[4]={90,10,100,5};

bool isleap(int y)
{return ((y%4)==0&&(y%100))!=0||(y%400)==0;}
int dayamount(int year,int month,int day)
{return (isleap(year)&&month>2)+monthday[month-1]+day;}

int getvalue(struct Book book)
{
	int n=0;
	while(!(book.importance%2))
		book.importance/=2;
	book.importance/=2;
	while(!(book.importance%2))
	{
		book.importance/=2;
		n++;
	}
	return n;
}

int getday(struct Date date_borrowed, struct Date date_returned)
{
	int dby=date_borrowed.year
	,dbm=date_borrowed.month
	,dbd=date_borrowed.day
	,dry=date_returned.year
	,drm=date_returned.month
	,drd=date_returned.day;
	
	int num=dayamount(dry,drm,drd);
	for(int i=dby;i<dry;i++)
		num+=dayamount(i,12,31);
	num-=dayamount(dby,dbm,dbd-1);//day=0 doesnt change the answer 
	return num;
}

unsigned int library_fine(struct Book book, struct Date date_borrowed, struct Date date_returned)
{
	int value=getvalue(book);
	int overdue=getday(date_borrowed,date_returned)-overd[book.type];
	if(overdue<0)overdue=0;
	return value*overdue;
}

int main()
{
	//
	struct Book book = {
        "Neon Genesis Evangelion",
        COMICS,
        "978-159-116-400-5",
        "Yoshiyuki Sadamoto",
        17
    };
    struct Date date_borrowed, date_returned;
    date_borrowed.year  = 1999;
    date_borrowed.month = 12;
    date_borrowed.day   = 25;
    date_returned.year  = 2000;
    date_returned.month = 4;
    date_returned.day   = 3;
    //
	cout<<library_fine(book,date_borrowed,date_returned)<<endl;
	return 0;
}

