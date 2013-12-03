#define _CRT_SECURE_NO_DEPRECATE 
#include <string.h>
#include <stdio.h>
#include <conio.h>

struct Books
{
	char title[50];
	char author[50];
	char subject[100];
	int book_id;
};

void printBook( struct Books book );

int main()
{
	struct Books Book1;
	struct Books Book2;

	strcpy(Book1.title, "c programming");
	strcpy(Book1.author,"NUha ali");
	strcpy(Book1.subject,"c programming tutorial");
	Book1.book_id = 001;


	strcpy(Book2.title,"telecom Billing");
	strcpy(Book2.author,"NUha Ali");
	strcpy(Book2.subject,"telecom billing tutorial");
	Book2.book_id = 1002;
	printBook(Book1);
	printBook(Book2);


	_getch();

	return 0;
}

void printBook( struct Books book )
{
	printf("Book title : %s\n",book.title);
	printf("Book author : %s\n",book.author);
	printf("Book subject : %s\n",book.subject);
	printf("Book book_id : %d\n",book.book_id);
}
