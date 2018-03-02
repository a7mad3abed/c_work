#include <stdio.h>

typedef struct {
    char *name ;
    unsigned int noOfPages;
    unsigned int currPage;
    
}Book;

void printBook(Book);

int main()
{
    Book b, c, d; 
    b.name = "Bukhary";
    b.noOfPages = 403;
    b.currPage = 202;
    c.name = "Muslim";
    c.noOfPages = 903;
    c.currPage = 103;
    d.name = "Mowataa";
    d.noOfPages = 734;
    d.currPage = 89;
    
    
    printBook(b);
    printBook(c);
    printBook(d);
}

void printBook(Book book)
{
    printf("The Name of the book is: %s\nTotal number of pages is: %d\nCurrent page is: %d\n\n", book.name, book.noOfPages, book.currPage);
}
