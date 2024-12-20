#include <iostream>
#include <cstring>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>

typedef struct Student { // иницаилизация структуры
  union{
    double GPA;
  }gpa;
  double FamilyIncome;
  char FirstName[128];
  char SecondName[128];
  char Patronymic[128];
  char GroupNumber[128];
} Student;

int InicialisationArrOfStructures (Student *&student, int size);
void OutArrOfStructures (Student *student, int size);
int AddStructures (Student *&student, int size);
void FindStructure (Student *student, int size);
void SortingAndOut (Student *student, int size);
int DeleteStructure (Student *&student, int size);
void ChangeStructure (Student *&student, int size);