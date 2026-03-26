#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "Student.h"

void deleteStudentDB(StudentDB* pST_DB)
{
    if (pST_DB == NULL)
        return;

    if (pST_DB->students != NULL)
        free(pST_DB->students);

    free(pST_DB);
}

//학생 한명의 정보를 출력하는 함수
//printStudentDB를 위해 제작한 함수
void printStudent(Student* pST)
{
    if (pST == NULL)
        return;

    printf("ID    : %4d ", pST->st_id);
    printf("Name  : %4s ", pST->name);
    printf("Major : %4s ", pST->major);
    printf("GPA   : %4.2lf ", pST->GPA);
}

void printStudentDB(StudentDB* pST_DB)
{
    if (pST_DB == NULL)
        return;

    printf("DB Name : %s\n", pST_DB->name);                         //데이터 베이스 이름 출력
    printf("Number of students : %d\n", pST_DB->num_students);      //학생들의 수 출력 
    

    for (int i = 0; i < pST_DB->num_students; i++)                  //학생의 수 만큼 반복
    {
        printf("\n[%d] ", i + 1);
        printStudent(&pST_DB->students[i]);                         //1명씩 출력하는 학생 정보 함수 호출
    }
}

//랜덤 섞이 함수
void shuffleStudents(StudentDB* pST_DB)
{
    if (pST_DB == NULL || pST_DB->students == NULL || pST_DB->num_students <= 1)
        return;

    srand((unsigned int)time(NULL));                        //랜덤 초기 시드 값 설정, 시간을 기준으로 설정 하였음

    for (int i = pST_DB->num_students - 1; i > 0; i--)      //끝애서 부터 시작하여 앞으로 하나씩 이동하면서 확정한다.
    {
        int j = rand() % (i + 1);

        Student temp = pST_DB->students[i];             //DB에 있는 학생을 랜덤으로 섞는 알고리즘
        pST_DB->students[i] = pST_DB->students[j];
        pST_DB->students[j] = temp;
    }
}

void statisticsGPA(StudentDB* pST_DB)
{
    if (pST_DB == NULL || pST_DB->students == NULL || pST_DB->num_students <= 0)
        return;

    double sum = 0.0;
    double maxGPA = pST_DB->students[0].GPA;
    double minGPA = pST_DB->students[0].GPA;

    for (int i = 0; i < pST_DB->num_students; i++)
    {
        double gpa = pST_DB->students[i].GPA;
        sum += gpa;

        if (gpa > maxGPA)
            maxGPA = gpa;
        if (gpa < minGPA)
            minGPA = gpa;
    }

    printf("GPA Statistics\n");
    printf("Average GPA : %.2lf\n", sum / pST_DB->num_students);
    printf("Max GPA     : %.2lf\n", maxGPA);
    printf("Min GPA     : %.2lf\n", minGPA);
}

//두 학생을 비교하는 코드로 무엇을 기준으로 구분할건지 switch 문으로 구성된 함수
int compareStudents(Student* pST1, Student* pST2, ST_ATTR st_key, SORT_MODE sort_mode)
{
    if (pST1 == NULL || pST2 == NULL)
        return 0;

    int result = 0;

    switch (st_key)                             //switch 문으로 무엇을 기준으로 비교할 것인지 나타냄
    {
    case ST_ID:
        if (pST1->st_id < pST2->st_id)
            result = -1;
        else if (pST1->st_id > pST2->st_id)
            result = 1;
        else
            result = 0;
        break;

    case NAME:
        result = strcmp(pST1->name, pST2->name);
        break;

    case MAJOR:
        result = strcmp(pST1->major, pST2->major);
        break;

    case GPA:
        if (pST1->GPA < pST2->GPA)
            result = -1;            //strcmp에서 결과가 음수면 두번째 인자가 더 크다.
        else if (pST1->GPA > pST2->GPA)
            result = 1;             //strcmp에서 결과가 양수면 첫번째 인자가 더 크다.
        else
            result = 0;             //strcmp에서 결과가 0이면 동일하다는 뜻
        break;

    default:
        result = 0;
        break;
    }

    if (sort_mode == DECR)          //내림 차순이면 반대의 값 출력
        result = -result;

    return result;
}

//삽입 정렬을 이용하여 데이터 별로 정리하였다. 무엇을 기준으로 정렬한것인가, 오른차순인가 내림 차순인가는
//compareStudents함수의 인자로 활용되어 각 항목 별로 무엇을 기준으로 분류 할 것인지를 나타낸다. 
void sortStudents(StudentDB* pST_DB, ST_ATTR sort_key, SORT_MODE sort_mode)
{
    if (pST_DB == NULL || pST_DB->students == NULL || pST_DB->num_students <= 1)
        return;

    for (int i = 1; i < pST_DB->num_students; i++)
    {
        Student key = pST_DB->students[i];
        int j = i - 1;

        while (j >= 0 && compareStudents(&pST_DB->students[j], &key, sort_key, sort_mode) > 0)      //비교의 값이 0이상인 것은 정렬이 아직 더 필요하다는 뜻이다.
        {
            pST_DB->students[j + 1] = pST_DB->students[j];
            j--;
        }

        pST_DB->students[j + 1] = key;
    }
}

StudentDB* fgetStudentDB(FILE* fin)
{
    if (fin == NULL)
        return NULL;

    StudentDB* pST_DB = (StudentDB*)malloc(sizeof(StudentDB));
    if (pST_DB == NULL)
        return NULL;

    memset(pST_DB, 0, sizeof(StudentDB));
    strcpy(pST_DB->name, "Student DB from File");

    if (fscanf(fin, "%d", &pST_DB->num_students) != 1)
    {
        free(pST_DB);
        return NULL;
    }

    if (pST_DB->num_students <= 0)
    {
        free(pST_DB);
        return NULL;
    }

    pST_DB->students = (Student*)malloc(sizeof(Student) * pST_DB->num_students);
    if (pST_DB->students == NULL)
    {
        free(pST_DB);
        return NULL;
    }

    for (int i = 0; i < pST_DB->num_students; i++)
    {
        if (fscanf(fin, "%d %59s %19s %lf",
            &pST_DB->students[i].st_id,
            pST_DB->students[i].name,
            pST_DB->students[i].major,
            &pST_DB->students[i].GPA) != 4)
        {
            free(pST_DB->students);
            free(pST_DB);
            return NULL;
        }
    }

    return pST_DB;
}