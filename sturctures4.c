
#include<stdio.h>
#include<string.h>
struct player
{
    char name[20];
    int highscore;
    float avg;
};
void disp(struct player p[100],int i)
{


        printf("name of the player is=%s\n",p[i].name);
        printf("highest run scored is=%d\n",p[i].highscore);
        printf("average run scored is=%f\n\n",p[i].avg);

}
int high(struct player p[100],int n)
{
    int i,h=0,index;
    for(i=0;i<n;i++)
    {
        if(p[i].highscore>h)
        {
            index=i;
            h=p[i].highscore;
        }
    }
    return index;

}
int low(struct player p[100],int n)
{
    int i,h=500,index;
    for(i=0;i<n;i++)
    {
        if(p[i].highscore<h)
        {
            h=p[i].highscore;
            index=i;
        }
    }
    return index;
}
int name(struct player p[100],int n)
{
    int i,index,value;
    char str2[]="rajath";
    for(i=0;i<n;i++)
    {
        value=strcmp(p[i].name,str2);
        if(value==0)
        {
            return i;
        }
    }

}
void main()
{
    struct player p[100];
    int i,n,k,l,m;
    printf("enter the number of participants\n");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
       printf("enter the name of the player\n");
       scanf("%s",p[i].name);
       printf("enter the high score of the player\n");
       scanf("%d",&p[i].highscore);
       printf("enter the average of the player");
       scanf("%f",&p[i].avg);

    }
    k=high(p,n);
    l=low(p,n);
    m=name(p,n);
    printf("the selected players are\n");
    disp(p,k);
    disp(p,l);
    disp(p,m);
}
