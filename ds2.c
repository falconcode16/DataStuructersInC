
#include <stdio.h>
#include <string.h>

struct Books {
   char  title[50];
   char  author[50];
   char  subject[100];
   int   book_id;
};
int main( ) {

   struct Books Book1;        /* Declare Book1 of type Book */

   printf("Book 1 title\n");
   scanf("%s", &Book1.title);
   printf("Enter Author\n");
   scanf("%s", &Book1.author);
   printf("Enter subject\n");
    scanf("%s", &Book1.subject);
    printf("Enter book_id\n");
    scanf("%d", &Book1.book_id);


        printf("The details of the book are:\n");
        printf("%s\n%s\n%s\n%d",Book1.title,Book1.author,Book1.subject,Book1.book_id);

}
