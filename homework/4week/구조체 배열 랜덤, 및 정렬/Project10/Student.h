#pragma once
#ifndef STUDENT_H
#define STUDENT_H

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define MAX_NAME_LEN 60
#define MAX_MAJOR_LEN 20

typedef struct
{
    int st_id;
    char name[MAX_NAME_LEN];
    char major[MAX_MAJOR_LEN];
    double GPA; // Grade Point Average
} Student;

typedef struct
{
    char name[64]; // name of student DB
    int num_students;
    Student* students;
} StudentDB;

enum ST_ATTR { ST_ID, NAME, MAJOR, GPA };
enum SORT_MODE { INCR, DECR };
StudentDB* fgetStudentDB(FILE* fin);
void deleteStudentDB(StudentDB* pST_DB);
void printStudent(Student* pST);
void printStudentDB(StudentDB* pST_DB);
void shuffleStudents(StudentDB* pST_DB);
void statisticsGPA(StudentDB* pST_DB);
int compareStudents(Student* pST1, Student* pST2, ST_ATTR st_key, SORT_MODE sort_mode);
void sortStudents(StudentDB* pST_DB, ST_ATTR sort_key, SORT_MODE sort_mode);

#endif