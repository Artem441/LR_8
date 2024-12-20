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

void SortingAndOut (Student *student, int size) {
  char buffer[128];
  double time;
  bool check = true;
  for (;;) {
    for (int i = 0; i < size - 1; ++i) { // цикл проходит до предпоследней структуры ведь в if я проверяю текущую и след структуктуры
      if (student[i].FamilyIncome > student[i+1].FamilyIncome) { // делаем студента с меньш заработком выше в списке
        time = student[i].gpa.GPA;// сохраняю большее значение
        student[i].gpa.GPA = student[i + 1].gpa.GPA;
        student[i + 1].gpa.GPA = time;
        time = student[i].FamilyIncome;// сохраняю большее значение
        student[i].FamilyIncome = student[i + 1].FamilyIncome;
        student[i + 1].FamilyIncome = time;
        strcpy(buffer, student[i].FirstName);
        strcpy(student[i].FirstName, student[i + 1].FirstName);
        strcpy(student[i + 1].FirstName, buffer);
        strcpy(buffer, student[i].SecondName);
        strcpy(student[i].SecondName, student[i + 1].SecondName);
        strcpy(student[i + 1].SecondName, buffer);
        strcpy(buffer, student[i].Patronymic);
        strcpy(student[i].Patronymic, student[i + 1].Patronymic);
        strcpy(student[i + 1].Patronymic, buffer);
        strcpy(buffer, student[i].GroupNumber);
        strcpy(student[i].GroupNumber, student[i + 1].GroupNumber);
        strcpy(student[i + 1].GroupNumber, buffer);
        check = false;
      }
    }
    if (check == true) {
      break;
    }
    else {
      check = true;
    }
  }
}