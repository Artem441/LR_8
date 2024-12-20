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

void FindStructure (Student *student, int size) {
  std::cout << "выберите элемент по которому будете искать нужную структуру: " << '\n';
  std::cout << "\t1 - поиск по среднему балу " << '\n';
  std::cout << "\t2 - поиск по доходу на члена семьи " << '\n';
  std::cout << "\t3 - поиск по фамилии " << '\n';
  std::cout << "\t4 - поиск по имени " << '\n';
  std::cout << "\t5 - поиск по отчеству " << '\n';
  std::cout << "\t6 - поиск по номеру группы " << '\n';
  bool proverka = false;
  int count = 0, check = 0, choose;
  char CHECK[128];
  std::string buffer;
  std::string buffer1;
  while (!(std::cin >> choose) || (std::cin.peek() != '\n') || choose < 1 || choose > 6) { 
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "неправильный ввод:  " << std::endl;
  }
  if (choose == 1) {
    std::cout << "введите средний балл, по которому следует найти ученика: ";
    double GPA;
    while (!(std::cin >> GPA) || (std::cin.peek() != '\n') || GPA < 2 || GPA > 10) { 
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cout << "неправильный ввод:  " << std::endl;
    }
    for (int i = 0; i < size; ++i) {
      if (student[i].gpa.GPA == GPA) {
        std::cout << "СТУДЕНТ N" << i + 1 << ": " << '\n';
        std::cout << "средний балл учащегося: " << student[i].gpa.GPA << '\n';
        std::cout << "доход на члена семьи: " << student[i].FamilyIncome << '\n';
        std::cout << "имя студента: " << student[i].FirstName << '\n';
        std::cout << "фамилия студента: " << student[i].SecondName << '\n';
        std::cout << "отчество студента: " << student[i].Patronymic << '\n';
        std::cout << "номер группы студента: " << student[i].GroupNumber << '\n';
        proverka = true;
      }
    }
    if (proverka == false) {
      std::cout << "не получилось найти ученика с средним балом - " << GPA << '\n';
    }
  }
  else if (choose == 2) {
    std::cout << "введите доход на члена семьи, по которому следует найти ученика: ";
    double FamilyIncome;
    while (!(std::cin >> FamilyIncome) || (std::cin.peek() != '\n') || FamilyIncome < 0) { 
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cout << "неправильный ввод:  " << std::endl;
    }
    for (int i = 0; i < size; ++i) {
      if (student[i].FamilyIncome == FamilyIncome) {
        std::cout << "СТУДЕНТ N" << i + 1 << ": " << '\n';
        std::cout << "средний балл учащегося: " << student[i].gpa.GPA << '\n';
        std::cout << "доход на члена семьи: " << student[i].FamilyIncome << '\n';
        std::cout << "имя студента: " << student[i].FirstName << '\n';
        std::cout << "фамилия студента: " << student[i].SecondName << '\n';
        std::cout << "отчество студента: " << student[i].Patronymic << '\n';
        std::cout << "номер группы студента: " << student[i].GroupNumber << '\n';
        proverka = true;
      }
    }
    if (proverka == false) {
      std::cout << "не получилось найти ученика с доходом на члена семьи - " << FamilyIncome << '\n';
    }
  }
  else if (choose == 3) {
    getchar();
    std::cout << "введите фамилию студента:, по которой следует найти ученика: ";
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
    strcpy(CHECK,buffer.c_str());
    for (int i = 0; i < size; ++i) {
      buffer1.assign(student[i].SecondName);
      if (buffer1 == buffer) {
        std::cout << "СТУДЕНТ N" << i + 1 << ": " << '\n';
        std::cout << "средний балл учащегося: " << student[i].gpa.GPA << '\n';
        std::cout << "доход на члена семьи: " << student[i].FamilyIncome << '\n';
        std::cout << "имя студента: " << student[i].FirstName << '\n';
        std::cout << "фамилия студента: " << student[i].SecondName << '\n';
        std::cout << "отчество студента: " << student[i].Patronymic << '\n';
        std::cout << "номер группы студента: " << student[i].GroupNumber << '\n';
        proverka = true;
      }
    }
    if (proverka == false) {
      std::cout << "не получилось найти ученика с фамилией - " << CHECK << '\n';
    }
  }
  else if (choose == 4) {
    getchar();
    std::cout << "введите имя студента:, по которой следует найти ученика: ";
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
    strcpy(CHECK,buffer.c_str());
    for (int i = 0; i < size; ++i) {
      buffer1.assign(student[i].FirstName);
      if (buffer == buffer1) {
        std::cout << "СТУДЕНТ N" << i + 1 << ": " << '\n';
        std::cout << "средний балл учащегося: " << student[i].gpa.GPA << '\n';
        std::cout << "доход на члена семьи: " << student[i].FamilyIncome << '\n';
        std::cout << "имя студента: " << student[i].FirstName << '\n';
        std::cout << "фамилия студента: " << student[i].SecondName << '\n';
        std::cout << "отчество студента: " << student[i].Patronymic << '\n';
        std::cout << "номер группы студента: " << student[i].GroupNumber << '\n';
        proverka = true;
      }
    }
    if (proverka == false) {
      std::cout << "не получилось найти ученика с именем - " << CHECK << '\n';
    }
  }
  else if (choose == 5) {
    getchar();
    std::cout << "введите отчество студента:, по которой следует найти ученика: ";
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
    strcpy(CHECK,buffer.c_str());
    for (int i = 0; i < size; ++i) {
      buffer1.assign(student[i].Patronymic);
      if (buffer1 == buffer) {
        std::cout << "СТУДЕНТ N" << i + 1 << ": " << '\n';
        std::cout << "средний балл учащегося: " << student[i].gpa.GPA << '\n';
        std::cout << "доход на члена семьи: " << student[i].FamilyIncome << '\n';
        std::cout << "имя студента: " << student[i].FirstName << '\n';
        std::cout << "фамилия студента: " << student[i].SecondName << '\n';
        std::cout << "отчество студента: " << student[i].Patronymic << '\n';
        std::cout << "номер группы студента: " << student[i].GroupNumber << '\n';
        proverka = true;
      }
    }
    if (proverka == false) {
      std::cout << "не получилось найти ученика с отчеством - " << CHECK << '\n';
    }
  }
  else if (choose == 6) {
    getchar();
    std::cout << "введите номер группы студента:, по которой следует найти ученика: ";
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
    strcpy(CHECK,buffer.c_str());
    for (int i = 0; i < size; ++i) {
      if (strcmp(CHECK,student[i].GroupNumber) == 0) {
        std::cout << "СТУДЕНТ N" << i + 1 << ": " << '\n';
        std::cout << "средний балл учащегося: " << student[i].gpa.GPA << '\n';
        std::cout << "доход на члена семьи: " << student[i].FamilyIncome << '\n';
        std::cout << "имя студента: " << student[i].FirstName << '\n';
        std::cout << "фамилия студента: " << student[i].SecondName << '\n';
        std::cout << "отчество студента: " << student[i].Patronymic << '\n';
        std::cout << "номер группы студента: " << student[i].GroupNumber << '\n';
        proverka = true;
      }
    }
    if (proverka == false) {
      std::cout << "не получилось найти ученика с номером группы - " << CHECK << '\n';
    }
  }
}

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