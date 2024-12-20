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

int AddStructures (Student *&student, int size) {
  int count = 0, check = 0;
  std::string buffer;

  std::cout << "введите сколько студентов хочете добавить " << '\n';
  int add = 0;
  while (!(std::cin >> add) || (std::cin.peek() != '\n') || add < 1) { 
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "неправильный ввод:  " << std::endl;
  }
  student = (Student*)realloc(student, (add + size) * sizeof(Student));
  for (int i = size; i < size + add; ++i) {
    std::cout << "введите средний балл студента: ";
    double GPA;
    while (!(std::cin >> GPA) || (std::cin.peek() != '\n') || GPA < 2 || GPA > 10) { 
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cout << "не верю:  " << std::endl;
    }
    student[i].gpa.GPA = GPA;

    std::cout << "введите доход на члена семьи: ";
    double FamilyIncome;
    while (!(std::cin >> FamilyIncome) || (std::cin.peek() != '\n') || FamilyIncome < 0) { 
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cout << "не верю:  " << std::endl;
    }
    student[i].FamilyIncome = FamilyIncome;
    getchar();

    std::cout << "введите фамилию студента: ";
    for (;;) { 
      check = 0;
      std::getline(std::cin, buffer);
      while (count < buffer.length()) { 
        if (isdigit(buffer[count]) == 1 || buffer.length() > 127) {
          buffer.clear();
          count = 0;
          check = 1;
          std::cout <<"неверный ввод: " << '\n';
          break;
        }
        ++count;
      }
      if (check != 1) {
        break;
      }
    }
    strcpy(student[i].SecondName,buffer.c_str());
    count = 0;
    check = 0;

    std::cout << "введите имя студента: ";
    for (;;) { 
      check = 0;
      std::getline(std::cin, buffer);
      while (count < buffer.length()) { 
        if (isdigit(buffer[count]) == 1 || buffer.length() > 127) {
          buffer.clear();
          count = 0;
          check = 1;
          std::cout <<"неверный ввод: " << '\n';
          break;
        }
        ++count;
      }
      if (check != 1) {
        break;
      }
    }
    strcpy(student[i].FirstName,buffer.c_str());
    count = 0;
    check = 0;

    std::cout << "введите отчество студента: ";
    for (;;) { 
      check = 0;
      std::getline(std::cin, buffer);
      while (count < buffer.length()) { 
        if (isdigit(buffer[count]) == 1 || buffer.length() > 127) {
          buffer.clear();
          count = 0;
          check = 1;
          std::cout <<"неверный ввод: " << '\n';
          break;
        }
        ++count;
      }
      if (check != 1) {
        break;
      }
    }
    strcpy(student[i].Patronymic,buffer.c_str());
    count = 0;
    check = 0;

    std::cout << "введите номер группы студента: ";
    for (;;) { 
      check = 0;
      std::getline(std::cin, buffer);
      while (count < buffer.length()) { 
        if (isdigit(buffer[count]) != 1 || buffer.length() > 127) {
          buffer.clear();
          count = 0;
          check = 1;
          std::cout <<"неверный ввод: " << '\n';
          break;
        }
        ++count;
      }
      if (check != 1) {
        break;
      }
    }
    strcpy(student[i].GroupNumber,buffer.c_str());
    count = 0;
    check = 0;
    std::cout << "теперь данные следующего студента: " << '\n';
  }
  int end = size + add;
  return end;
}