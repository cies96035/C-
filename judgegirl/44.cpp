#include<iostream>
using namespace std;

struct Date {
    unsigned int year;
    unsigned int month;
    unsigned int day;
};

enum Type {NOVEL, COMICS, MANUAL, TEXTBOOK};
 
struct Book {
    char title[128];
    enum Type type;
    char ISBN[128];
    char authors[128];
    unsigned int importance;
};
unsigned int getvalue(struct Book book)
{
	int n=-1;
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

unsigned int library_fine(struct Book book, struct Date date_borrowed, struct Date date_returned)
{
	int value=getvalue(book);
	return value;
}
int main()
{
	Book b;
	b.importance=17;
	Date d,f;
	cout<<library_fine(b,d,f)<<endl;
	return 0;
}

