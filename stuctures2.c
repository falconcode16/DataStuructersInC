
#include<stdio.h>


struct time{
    int hour, minute, second;
};

int main(){
    struct time t1, t2, t3;
    int seconds1, seconds2, totalSeconds;

    printf("Enter first time in HH:MM:SS : ");
    scanf("%d:%d:%d",&t1.hour, &t1.minute, &t1.second);

    printf("Enter second time in HH:MM:SS: ");
    scanf("%d:%d:%d",&t2.hour, &t2.minute, &t2.second);


    seconds1 = t1.hour*60*60 + t1.minute*60 + t1.second;
    seconds2 = t2.hour*60*60 + t2.minute*60 + t2.second;

    totalSeconds = seconds1-seconds2;


    t3.minute = totalSeconds/60;
    t3.hour = t3.minute/60;
    t3.minute = t3.minute%60;
    t3.second = totalSeconds%60;

    printf("Time difference is: %02d:%02d:%02d\n", t3.hour, t3.minute, t3.second);
}
