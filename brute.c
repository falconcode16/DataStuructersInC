#include<stdio.h>
#include<stdlib.h>
     
int main(){

    int size,i, pattern;
     printf("enter the size of string");
     scanf("%d",&size);

     char chararray[size];
     printf("enter the string ");
     for(i=0;i<size;i++)
     {
         scanf("%s", chararray[i]);

     }
       printf("enter the size of pattern");
     scanf("%d",&pattern);

     char patterarray[pattern];
     printf("enter the searching pattern ");
     for(i=0;i<size;i++)
     {
         scanf("%s", patterarray[i]);
         
     }
         
          
return 0;
   
}