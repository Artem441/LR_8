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


void ChangeStructure (Student *&student, int size) {
  std::cout << "выберите элемент по которому будете искать структуру, которую хочете изменить: " << '\n';
  std::cout << "\t1 - поиск по среднему балу " << '\n';
  std::cout << "\t2 - поиск по доходу на члена семьи " << '\n';
  std::cout << "\t3 - поиск по фамилии " << '\n';
  std::cout << "\t4 - поиск по имени " << '\n';
  std::cout << "\t5 - поиск по отчеству " << '\n';
  std::cout << "\t6 - поиск по номеру группы " << '\n';
  bool proverka = false;
  int count = 0, check = 0, choose;
  double time;
  char Buffer[128];
  std::string buffer, buffer1, dop_buffer;
  while (!(std::cin >> choose) || (std::cin.peek() != '\n') || choose < 1 || choose > 6) { 
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "неправильный ввод:  " << std::endl;
  }
  if (choose == 1) {
    std::cout << "введите средний балл, по которому изменить ученика: ";
    double GPA, GPA1;
    while (!(std::cin >> GPA) || (std::cin.peek() != '\n') || GPA < 2 || GPA > 10) { 
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cout << "неправильный ввод:  " << std::endl;
    }
    GPA1 = GPA;
    proverka = true;
    for (int i = 0; i < size - 1; ++i) { // если найдена структура которую надо удалить то просто сместим остальные ячейки на 1 вниз и перевыд память с помощью realloc
      if (student[i].gpa.GPA == GPA1) {
        proverka = false;
        std::cout << "введите новый средний балл студента: ";
        while (!(std::cin >> GPA) || (std::cin.peek() != '\n') || GPA < 2 || GPA > 10) { 
          std::cin.clear();
          std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
          std::cout << "не верю:  " << std::endl;
        }
          student[i].gpa.GPA = GPA;
        }
    }
    if (proverka == true) {
      std::cout << "не получилось найти ученика с средним балом - " << GPA << '\n';
    }
  }
  else if (choose == 2) {
    std::cout << "введите средний доход на члена семьи, по которому изменить ученика: ";
    double FamilyIncome, FamilyIncome1;
    while (!(std::cin >> FamilyIncome) || (std::cin.peek() != '\n') || FamilyIncome < 0) { 
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cout << "неправильный ввод:  " << std::endl;
    }
    FamilyIncome1 = FamilyIncome;
    proverka = true;
    for (int i = 0; i < size - 1; ++i) { // если найдена структура которую надо удалить то просто сместим остальные ячейки на 1 вниз и перевыд память с помощью realloc
      if (student[i].FamilyIncome == FamilyIncome1) {
        proverka = false;
        std::cout << "введите новый средний балл студента: ";
        while (!(std::cin >> FamilyIncome) || (std::cin.peek() != '\n') || FamilyIncome < 0) { 
          std::cin.clear();
          std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
          std::cout << "не верю:  " << std::endl;
        }
          student[i].FamilyIncome = FamilyIncome;
        }
    }
    if (proverka == true) {
      std::cout << "не получилось найти ученика со средним доходом на члена семьи - " << FamilyIncome1 << '\n';
    }
  }
  else if (choose == 3) {
    getchar();
    std::cout << "введите фамилию ученика, которую следует заменить: ";
    std::string SecondName, SecondName1;
    char buffer[128], buffer_1[128];// есть еще Buffer
    for (;;) { 
      check = 0;
      std::getline(std::cin, SecondName);
      while (count < SecondName.length()) { 
        if (isdigit(SecondName[count]) == 1 || SecondName.length() > 127) {
          SecondName.clear();
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
    SecondName1 = SecondName;
    proverka = true;
    strcpy(buffer_1,SecondName.c_str());
    for (int i = 0; i < size; ++i) {
      SecondName1.assign(student[i].SecondName);
      if (SecondName1 == SecondName) {
        proverka = false;
        std::cout << "введите новую фамилию студента: ";
        for (;;) { 
          check = 0;
          std::getline(std::cin, SecondName1);
          while (count < SecondName1.length()) { 
            if (isdigit(SecondName1[count]) == 1 || SecondName1.length() > 127) {
              SecondName1.clear();
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
        strcpy(buffer,SecondName1.c_str());
        strcpy(student[i].SecondName,buffer);
        }
    }
    if (proverka == true) {
      std::cout << "не получилось найти ученика с фамилией - " << SecondName1 << '\n';
    }
  }
  else if (choose == 4) {
    getchar();
    std::cout << "введите имя ученика, которую следует заменить: ";
    std::string FirstName, FirstName1;
    char buffer[128], buffer_1[128];// есть еще Buffer
    for (;;) { 
      check = 0;
      std::getline(std::cin, FirstName);
      while (count < FirstName.length()) { 
        if (isdigit(FirstName[count]) == 1 || FirstName.length() > 127) {
          FirstName.clear();
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
    FirstName1 = FirstName;
    strcpy(buffer_1,FirstName.c_str());
    proverka = true;
    for (int i = 0; i < size; ++i) {
      FirstName1.assign(student[i].SecondName);
      if (FirstName1 == FirstName) {
        proverka = false;
        std::cout << "введите новое имя студента: ";
        for (;;) { 
          check = 0;
          std::getline(std::cin, FirstName1);
          while (count < FirstName1.length()) { 
            if (isdigit(FirstName1[count]) == 1 || FirstName1.length() > 127) {
              FirstName1.clear();
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
        strcpy(buffer,FirstName1.c_str());
        strcpy(student[i].FirstName,buffer);
        }
    }
    if (proverka == true) {
      std::cout << "не получилось найти ученика с именем - " << FirstName1 << '\n';
    }
  }
  else if (choose == 5) {
    getchar();
    std::cout << "введите отчество ученика, которую следует заменить: ";
    std::string Patronymic, Patronymic1;
    char buffer[128], buffer_1[128];// есть еще Buffer
    for (;;) { 
      check = 0;
      std::getline(std::cin, Patronymic);
      while (count < Patronymic.length()) { 
        if (isdigit(Patronymic[count]) == 1 || Patronymic.length() > 127) {
          Patronymic.clear();
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
    Patronymic1 = Patronymic;
    strcpy(buffer_1,Patronymic.c_str());
    proverka = true;
    for (int i = 0; i < size; ++i) {
      Patronymic1.assign(student[i].Patronymic);
      if (Patronymic == Patronymic1) {
        proverka = false;
        std::cout << "введите новое отчество студента: ";
        for (;;) { 
          check = 0;
          std::getline(std::cin, Patronymic1);
          while (count < Patronymic1.length()) { 
            if (isdigit(Patronymic1[count]) == 1 || Patronymic1.length() > 127) {
              Patronymic1.clear();
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
        strcpy(buffer,Patronymic1.c_str());
        strcpy(student[i].Patronymic,buffer);
        }
    }
    if (proverka == true) {
      std::cout << "не получилось найти ученика с отчеством - " << Patronymic1 << '\n';
    }
  }
  else if (choose == 6) {
    std::string GroupNumber, GroupNumber1;
    char buffer[128], buffer_1[128];
    getchar();
    std::cout << "введите номер группы студента: по которой следует найти ученика: ";
    for (;;) { 
      check = 0;
      std::getline(std::cin, GroupNumber);
      while (count < GroupNumber.length()) { 
        if (isdigit(GroupNumber[count]) != 1 || GroupNumber.length() > 127) {
          GroupNumber.clear();
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
    GroupNumber1 = GroupNumber;
    strcpy(buffer_1,GroupNumber.c_str());
    proverka = true;
    for (int i = 0; i < size; ++i) {
      GroupNumber1.assign(student[i].GroupNumber);
      if (GroupNumber == GroupNumber1) {
        proverka = false;
        std::cout << "введите новую группу студента: ";
        for (;;) { 
          check = 0;
          std::getline(std::cin, GroupNumber1);
          while (count < GroupNumber1.length()) { 
            if (isdigit(GroupNumber1[count]) != 1 || GroupNumber1.length() > 127) {
              GroupNumber1.clear();
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
        strcpy(buffer,GroupNumber1.c_str());
        strcpy(student[i].GroupNumber,buffer);
        }
    }
    if (proverka == true) {
      std::cout << "не получилось найти ученика с номером группы - " << GroupNumber1 << '\n';
    }
  }
}