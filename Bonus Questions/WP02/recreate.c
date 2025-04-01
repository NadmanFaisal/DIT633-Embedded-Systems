#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_DAY 7
#define MAX_WEEK 6

typedef enum{
    SUNDAY,
    MONDAY,
    TUESDAY,
    WEDNESDAY,
    THURSDAY,
    FRIDAY,
    SATURDAY
} Day;

void clearBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) { }
}

int main(int argc, char **argv) {
    int userDay;
    int userWeek;

    printf("Provide starting day: ");
    scanf("%d", &userDay);
    clearBuffer();

    printf("Provide starting week: ");
    scanf("%d", &userWeek);
    clearBuffer();

    Day day = userDay;

    while(userWeek < MAX_WEEK) {
        switch(day) {
            case 1:
                printf("Week %d, Monday\n", userWeek);
                break;
            case 2:
                printf("Week %d, Tuesday\n", userWeek);
                break;
            case 3:
                printf("Week %d, Wednesday\n", userWeek);
                break;
            case 4:
                printf("Week %d, Thursday\n", userWeek);
                break;
            case 5:
                printf("Week %d, Friday\n", userWeek);
                break;
            case 6:
                printf("Week %d, Saturday\n", userWeek);
                break;
                default:
                printf("Week %d, Sunday\n", userWeek);
                day = 1;
                userWeek++;
                break;
            }
        day++;
        sleep(1);
    }


    return 0;
}