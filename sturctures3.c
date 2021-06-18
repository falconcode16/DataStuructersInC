
#include<stdio.h>
#include<math.h>
struct zomatofooddelivery
{
    char starters[100];
    char maincourse[100];
    char desserts[100];
    int startersrate;
    int maincourserate;
    int dessertrate;
    int totalrate;

};
void display(struct zomatofooddelivery);
main()
{
    struct zomatofooddelivery p1={"crispy, gobi","malaikofta,paneer chole, Aloo Gobi, hyderabadi biriyani","rasmalai",140,300,180,100};
    display (p1);
}

void display(struct zomatofooddelivery p1)
{
    printf("%s,\n%s,\n%s,\n%d,\n%d,\n%d,\n%d,\n",p1.starters,p1.maincourse,p1.desserts,p1.startersrate,p1.maincourserate,p1.dessertrate,p1.totalrate);
}
