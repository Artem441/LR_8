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

void OutArrOfStructures (Student *student, int size) {
  for (int i = 0; i < size; ++i) {
    std::cout << "СТУДЕНТ N" << i + 1 << ": " << '\n';
    std::cout << "средний балл учащегося: " << student[i].gpa.GPA << '\n';
    std::cout << "доход на члена семьи: " << student[i].FamilyIncome << '\n';
    std::cout << "имя студента: " << student[i].FirstName << '\n';
    std::cout << "фамилия студента: " << student[i].SecondName << '\n';
    std::cout << "отчество студента: " << student[i].Patronymic << '\n';
    std::cout << "номер группы студента: " << student[i].GroupNumber << '\n';
  }
}