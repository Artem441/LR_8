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


int DeleteStructure (Student *&student, int size) {
  std::cout << "выберите элемент по которому будете искать структуру, которую хочете удалить: " << '\n';
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
    std::cout << "введите средний балл, по которому удалить найти ученика: ";
    double GPA;
    while (!(std::cin >> GPA) || (std::cin.peek() != '\n') || GPA < 2 || GPA > 10) { 
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cout << "неправильный ввод:  " << std::endl;
    }
    for (int i = 0; i < size; ++i) {
      if (student[i].gpa.GPA == GPA) {
        ++count;
      }
    }
    for (;;) {
      proverka = true;
      for (int i = 0; i < size - 1; ++i) { // если найдена структура которую надо удалить то просто сместим остальные ячейки на 1 вниз и перевыд память с помощью realloc
        if (student[i].gpa.GPA == GPA && student[i].gpa.GPA != student[i + 1].gpa.GPA) {
          proverka = false;
          time = student[i].gpa.GPA;// сохраняю большее значение
          student[i].gpa.GPA = student[i + 1].gpa.GPA;
          student[i + 1].gpa.GPA = time;
          time = student[i].FamilyIncome;// сохраняю большее значение
          student[i].FamilyIncome = student[i + 1].FamilyIncome;
          student[i + 1].FamilyIncome = time;
          strcpy(Buffer, student[i].FirstName);
          strcpy(student[i].FirstName, student[i + 1].FirstName);
          strcpy(student[i + 1].FirstName, Buffer);
          strcpy(Buffer, student[i].SecondName);
          strcpy(student[i].SecondName, student[i + 1].SecondName);
          strcpy(student[i + 1].SecondName, Buffer);
          strcpy(Buffer, student[i].Patronymic);
          strcpy(student[i].Patronymic, student[i + 1].Patronymic);
          strcpy(student[i + 1].Patronymic, Buffer);
          strcpy(Buffer, student[i].GroupNumber);
          strcpy(student[i].GroupNumber, student[i + 1].GroupNumber);
          strcpy(student[i + 1].GroupNumber, Buffer);
        }
      }
      if (proverka == true) {
        break;
      }
    }
    student = (Student*)realloc(student, (size - count) * sizeof(Student));
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
        ++count;
      }
    }
    for (;;) {
      proverka = true;
      for (int i = 0; i < size - 1; ++i) { // если найдена структура которую надо удалить то просто сместим остальные ячейки на 1 вниз и перевыд память с помощью realloc
        if (student[i].FamilyIncome == FamilyIncome && student[i].FamilyIncome != student[i + 1].FamilyIncome) {
          proverka = false;
          time = student[i].gpa.GPA;// сохраняю большее значение
          student[i].gpa.GPA = student[i + 1].gpa.GPA;
          student[i + 1].gpa.GPA = time;
          time = student[i].FamilyIncome;// сохраняю большее значение
          student[i].FamilyIncome = student[i + 1].FamilyIncome;
          student[i + 1].FamilyIncome = time;
          strcpy(Buffer, student[i].FirstName);
          strcpy(student[i].FirstName, student[i + 1].FirstName);
          strcpy(student[i + 1].FirstName, Buffer);
          strcpy(Buffer, student[i].SecondName);
          strcpy(student[i].SecondName, student[i + 1].SecondName);
          strcpy(student[i + 1].SecondName, Buffer);
          strcpy(Buffer, student[i].Patronymic);
          strcpy(student[i].Patronymic, student[i + 1].Patronymic);
          strcpy(student[i + 1].Patronymic, Buffer);
          strcpy(Buffer, student[i].GroupNumber);
          strcpy(student[i].GroupNumber, student[i + 1].GroupNumber);
          strcpy(student[i + 1].GroupNumber, Buffer);
        }
      }
      if (proverka == true) {
        break;
      }
    }
    student = (Student*)realloc(student, (size - count) * sizeof(Student));
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
    count = 0;
    strcpy(Buffer,buffer.c_str());
    for (int i = 0; i < size; ++i) {
      buffer1.assign(student[i].SecondName);
      if (buffer == buffer1) {
        ++count;
      }
    }
    for (;;) {
      proverka = true;
      for (int i = 0; i < size - 1; ++i) { // если найдена структура которую надо удалить то просто сместим остальные ячейки на 1 вниз и перевыд память с помощью realloc
        buffer1.assign(student[i].SecondName);
        dop_buffer.assign(student[i + 1].SecondName);
        if (buffer == buffer1 && buffer != dop_buffer) {
          proverka = false;
          time = student[i].gpa.GPA;// сохраняю большее значение
          student[i].gpa.GPA = student[i + 1].gpa.GPA;
          student[i + 1].gpa.GPA = time;
          time = student[i].FamilyIncome;// сохраняю большее значение
          student[i].FamilyIncome = student[i + 1].FamilyIncome;
          student[i + 1].FamilyIncome = time;
          strcpy(Buffer, student[i].FirstName);
          strcpy(student[i].FirstName, student[i + 1].FirstName);
          strcpy(student[i + 1].FirstName, Buffer);
          strcpy(Buffer, student[i].SecondName);
          strcpy(student[i].SecondName, student[i + 1].SecondName);
          strcpy(student[i + 1].SecondName, Buffer);
          strcpy(Buffer, student[i].Patronymic);
          strcpy(student[i].Patronymic, student[i + 1].Patronymic);
          strcpy(student[i + 1].Patronymic, Buffer);
          strcpy(Buffer, student[i].GroupNumber);
          strcpy(student[i].GroupNumber, student[i + 1].GroupNumber);
          strcpy(student[i + 1].GroupNumber, Buffer);
        }
      }
      if (proverka == true) {
        break;
      }
    }
    student = (Student*)realloc(student, (size - count) * sizeof(Student));
    if (proverka == false) {
      std::cout << "не получилось найти ученика с фамилией - " << buffer << '\n';
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
    count = 0;
    strcpy(Buffer,buffer.c_str());
    for (int i = 0; i < size; ++i) {
      buffer1.assign(student[i].FirstName);
      if (buffer == buffer1) {
        ++count;
      }
    }
    for (;;) {
      proverka = true;
      for (int i = 0; i < size - 1; ++i) { // если найдена структура которую надо удалить то просто сместим остальные ячейки на 1 вниз и перевыд память с помощью realloc
        buffer1.assign(student[i].FirstName);
        dop_buffer.assign(student[i + 1].FirstName);
        if (buffer == buffer1 && buffer != dop_buffer) {
          proverka = false;
          time = student[i].gpa.GPA;// сохраняю большее значение
          student[i].gpa.GPA = student[i + 1].gpa.GPA;
          student[i + 1].gpa.GPA = time;
          time = student[i].FamilyIncome;// сохраняю большее значение
          student[i].FamilyIncome = student[i + 1].FamilyIncome;
          student[i + 1].FamilyIncome = time;
          strcpy(Buffer, student[i].FirstName);
          strcpy(student[i].FirstName, student[i + 1].FirstName);
          strcpy(student[i + 1].FirstName, Buffer);
          strcpy(Buffer, student[i].SecondName);
          strcpy(student[i].SecondName, student[i + 1].SecondName);
          strcpy(student[i + 1].SecondName, Buffer);
          strcpy(Buffer, student[i].Patronymic);
          strcpy(student[i].Patronymic, student[i + 1].Patronymic);
          strcpy(student[i + 1].Patronymic, Buffer);
          strcpy(Buffer, student[i].GroupNumber);
          strcpy(student[i].GroupNumber, student[i + 1].GroupNumber);
          strcpy(student[i + 1].GroupNumber, Buffer);
        }
      }
      if (proverka == true) {
        break;
      }
    }
    student = (Student*)realloc(student, (size - count) * sizeof(Student));
    if (proverka == false) {
      std::cout << "не получилось найти ученика с именем - " << buffer << '\n';
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
    count = 0;
    strcpy(Buffer,buffer.c_str());
    for (int i = 0; i < size; ++i) {
      buffer1.assign(student[i].Patronymic);
      if (buffer == buffer1) {
        ++count;
      }
    }
    for (;;) {
      proverka = true;
      for (int i = 0; i < size - 1; ++i) { // если найдена структура которую надо удалить то просто сместим остальные ячейки на 1 вниз и перевыд память с помощью realloc
        buffer1.assign(student[i].Patronymic);
        dop_buffer.assign(student[i + 1].Patronymic);
        if (buffer == buffer1 && buffer != dop_buffer) {
          proverka = false;
          time = student[i].gpa.GPA;// сохраняю большее значение
          student[i].gpa.GPA = student[i + 1].gpa.GPA;
          student[i + 1].gpa.GPA = time;
          time = student[i].FamilyIncome;// сохраняю большее значение
          student[i].FamilyIncome = student[i + 1].FamilyIncome;
          student[i + 1].FamilyIncome = time;
          strcpy(Buffer, student[i].FirstName);
          strcpy(student[i].FirstName, student[i + 1].FirstName);
          strcpy(student[i + 1].FirstName, Buffer);
          strcpy(Buffer, student[i].SecondName);
          strcpy(student[i].SecondName, student[i + 1].SecondName);
          strcpy(student[i + 1].SecondName, Buffer);
          strcpy(Buffer, student[i].Patronymic);
          strcpy(student[i].Patronymic, student[i + 1].Patronymic);
          strcpy(student[i + 1].Patronymic, Buffer);
          strcpy(Buffer, student[i].GroupNumber);
          strcpy(student[i].GroupNumber, student[i + 1].GroupNumber);
          strcpy(student[i + 1].GroupNumber, Buffer);
        }
      }
      if (proverka == true) {
        break;
      }
    }
    student = (Student*)realloc(student, (size - count) * sizeof(Student));
    if (proverka == false) {
      std::cout << "не получилось найти ученика с отчеством - " << buffer << '\n';
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
    count = 0;
    strcpy(Buffer,buffer.c_str());
    for (int i = 0; i < size; ++i) {
      buffer1.assign(student[i].GroupNumber);
      if (buffer == buffer1) {
        ++count;
      }
    }
    for (;;) {
      proverka = true;
      for (int i = 0; i < size - 1; ++i) { // если найдена структура которую надо удалить то просто сместим остальные ячейки на 1 вниз и перевыд память с помощью realloc
        buffer1.assign(student[i].GroupNumber);
        dop_buffer.assign(student[i + 1].GroupNumber);
        if (buffer == buffer1 && buffer != dop_buffer) {
          proverka = false;
          time = student[i].gpa.GPA;// сохраняю большее значение
          student[i].gpa.GPA = student[i + 1].gpa.GPA;
          student[i + 1].gpa.GPA = time;
          time = student[i].FamilyIncome;// сохраняю большее значение
          student[i].FamilyIncome = student[i + 1].FamilyIncome;
          student[i + 1].FamilyIncome = time;
          strcpy(Buffer, student[i].FirstName);
          strcpy(student[i].FirstName, student[i + 1].FirstName);
          strcpy(student[i + 1].FirstName, Buffer);
          strcpy(Buffer, student[i].SecondName);
          strcpy(student[i].SecondName, student[i + 1].SecondName);
          strcpy(student[i + 1].SecondName, Buffer);
          strcpy(Buffer, student[i].Patronymic);
          strcpy(student[i].Patronymic, student[i + 1].Patronymic);
          strcpy(student[i + 1].Patronymic, Buffer);
          strcpy(Buffer, student[i].GroupNumber);
          strcpy(student[i].GroupNumber, student[i + 1].GroupNumber);
          strcpy(student[i + 1].GroupNumber, Buffer);
        }
      }
      if (proverka == true) {
        break;
      }
    }
    student = (Student*)realloc(student, (size - count) * sizeof(Student));
    if (proverka == false) {
      std::cout << "не получилось найти ученика с отчеством - " << buffer << '\n';
    }
  }
  return (size - count);
}