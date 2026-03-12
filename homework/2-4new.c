#include <stdio.h>
#include <stdbool.h>

#define DAYS_PER_WEEK 7
enum WEEKDAY {SUN, MON, TUE, WED, THR, FRI, SAT};

const char* monthName[13] = { "", "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };
const char* WEEKDAY[7] = { "SUN", "MON", "TUE", "WED", "THR", "FRI", "SAT" };

bool leap_year(int year) {
    return (year%4==0 && year%100 !=0) || (year%400==0) ;
}

int Cul_day(int year, int month, int day){
    int ret = 0;

    for(int i = 1; i < year; i++) {
        ret = leap_year(i) ? ret + 366 : ret + 365;
    }

    int arr_day[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
    if(leap_year(year)) arr_day[2] = 29;

    switch(month){
        case 12: ret += arr_day[11];
        case 11: ret += arr_day[10];
        case 10: ret += arr_day[9];
        case 9: ret += arr_day[8];
        case 8: ret += arr_day[7];
        case 7: ret += arr_day[6];
        case 6: ret += arr_day[5];
        case 5: ret += arr_day[4];
        case 4: ret += arr_day[3];
        case 3: ret += arr_day[2];
        case 2: ret += arr_day[1];
        case 1: ret += arr_day[0];
    }
    ret += day;

    return ret;
}

void printBirthStone(int month)
{
    const char* birthStone[13] = { "", "Garnet", "Amethyst", "Aquamarine", "Diamond", "Emerald", "Pearl", "Ruby", "Peridot", "Sapphire", "Opal", "Topaz", "Turquoise" };
    printf("birth stone = %s\n",birthStone[month]);
}

void printCalendar(int year, int month, int day){
    int arr_day[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
    if(leap_year(year)) arr_day[2] = 29;
    
    int weekday = Cul_day(year, month, 1) % DAYS_PER_WEEK;

    printf(">>>>>>>> %s of %d <<<<<<<<\n", monthName[month], year);
    printf("=====================================\n");
    for(int i = 0; i < 7; i++) {
        printf("%5s", WEEKDAY[i]);
    }
    printf("\n-------------------------------------\n");
    for(int i = 0; i < weekday; i++){
        printf("     ");
    }
    for(int day = 1; day < arr_day[month]; day++) {
        if(weekday % DAYS_PER_WEEK == 0){
            printf("\n");
            weekday = 0;
        }
        printf("%5d", day);
        weekday++;
    }
    printf("\n-------------------------------------\n");

}

int main() {
    int year, month, day;

    while(1)
    {
        printf("Input year month day (0 0 0 to quit) : ");
        scanf("%d %d %d", &year, &month, &day);
        
        if(year == 0 && month == 0 && day == 0)
            break;
        
        printf("date(%s %d, %d) ",monthName[month],day,year);
        printf("(%s) ", WEEKDAY[Cul_day(year, month, day) % DAYS_PER_WEEK]);
        printf("%d-th day from Jan 1, 1.\n",Cul_day(year,month,day));
        
        printBirthStone(month);

        printf("\n");
        printCalendar(year,month,day);
        
    }
}