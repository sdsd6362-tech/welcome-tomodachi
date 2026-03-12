#include <stdio.h>
#include <stdbool.h>
#define DAYS_PER_WEEK 7
enum WEEKDAY { SUN, MON, TUE, WED, THR, FRI, SAT };

//유년 계산 함수
bool leap_year(int year){
    // if((year%4==0 && year%100 !=0)||(year%400==0))
    //     return true;   //윤년일시 1 반환
    // else
    //     return false;  //윤년이 아니면 0 반환

    return (year%4==0 && year%100 !=0) || (year%400==0) ;
}

//1년 1월 1일 부터 입력한 날짜까지 총 일수 계산 함수
int Cul_day(int year, int month, int day){
    int daysFromAD01Jan01 = 0;
    int dayslnyear;
    int arr_day[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
    for(int y = 1; y<year ; y++){
        dayslnyear = (leap_year(y)?366:365);
        daysFromAD01Jan01 += dayslnyear;
    }

    if(leap_year(year))
        arr_day[2] = 29;
    
    for(int m = 1; m<month ; m++){
        daysFromAD01Jan01 += arr_day[m];
    }
    daysFromAD01Jan01 += day;
    return daysFromAD01Jan01;
}
// 탄생석 출력 함수
void printBirthStone(int month)
{
    const char* monthName[13] = { "", "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };
    const char* birthStone[13] = { "", "Garnet", "Amethyst", "Aquamarine", "Diamond", "Emerald", "Pearl", "Ruby", "Peridot", "Sapphire", "Opal", "Topaz", "Turquoise" };
    printf("birth stone = %s",birthStone[month]);
}

//1월 무슨 요일 인지 구하기
int Find1day(int year, int month, int day)
{
    int daylyner = (leap_year(year)?366:365);
}



//달력 제작 함수
void printCalendar(int year, int month, int day)
{
    const char* monthName[13] = { "", "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };
    const char* WEEKDAY[7] = { "SUN", "MON", "TUE", "WED", "THR", "FRI", "SAT" };
    int What_day;
    int arr_day[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
    if(leap_year(year))
        arr_day[2] = 29;

    printf(">>>>>>>> %s of %d <<<<<<<<\n", monthName[month], year);
    printf("==================================\n");
    for(int i=0;i<DAYS_PER_WEEK;i++)
    {
        printf("%4s ",WEEKDAY[i]);
    }
    printf("\n----------------------------------\n");



}





//메인 함수 시작
int main(){
    int year, month, day;
    const char* monthName[13] = { "", "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };

    while(1)
    {
        printf("Input year month day (0 0 0 to quit) : ");
        scanf("%d %d %d", &year, &month, &day);
        if(year == 0 && month == 0 && day == 0)
            break;
        printf("date(%s %d, %d)",monthName[month],day,year);
        printf("%d-th day from Jan 1, 1.",Cul_day(year,month,day));
        printBirthStone(month);
        printf("\n");
        printCalendar(year,month,day);
        
    }
}





