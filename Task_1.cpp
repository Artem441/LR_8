#include <iostream>
#include <cstring>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include "func.h"

/*
int InicialisationArrOfStructures (Student *&student, int size);
void OutArrOfStructures (Student *student, int size);
int AddStructures (Student *&student, int size);
void FindStructure (Student *student, int size);
void SortingAndOut (Student *student, int size);
int DeleteStructure (Student *&student, int size);
void ChangeStructure (Student *&student, int size);
*/

int main () {
  int size = 0, counter = 0, func = 0;
  std::cout << "введите начальное количество студентов: ";
  while (!(std::cin >> size) || (std::cin.peek() != '\n') || size < 1) { 
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "неправильный ввод:  " << std::endl;
  }
  Student *student = (Student*) malloc(size * sizeof(Student));
  size = InicialisationArrOfStructures(student, size);
  for (;;) {
    std::cout << "выберите из предложенных функций: " << '\n';
    std::cout << "--------------------------------------Menu--------------------------------------" << '\n';
    std::cout << " 1 -> просмотр всех студентов" << '\n';
    std::cout << " 2 -> добавить новых cтудентов" << '\n';
    std::cout << " 3 -> поиск студента по определенному признаку" << '\n';
    std::cout << " 4 -> удаление студента с определенным признаком" << '\n';
    std::cout << " 5 -> изменение данных о студенте с определенным признаком" << '\n';
    std::cout << " 6 -> упорядочение студентов по среденму заработку на члена семьи" << '\n';
    std::cout << " 7 -> выход из программы" << '\n';
    while (!(std::cin >> func) || (std::cin.peek() != '\n') || func < 1 || func > 7) { 
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cout << "неправильный ввод:  " << std::endl;
    }
    if (func == 1) {
      OutArrOfStructures(student, size);
    }
    else if (func == 2) {
      size = AddStructures(student, size);
    }
    else if (func == 3) {
      FindStructure(student, size);
    }
    else if (func == 4) {
      size = DeleteStructure(student, size);
    }
    else if (func == 5) {
      ChangeStructure(student, size);
    }
    else if (func == 6) {
      SortingAndOut(student, size);
    }
    else if (func == 7) {
      break;
    }
  }
  free(student);
  return 0;
}
/*
int InicialisationArrOfStructures (Student *&student, int size) {
  typedef struct Temporary { // иницаилизация структуры
    union{
      double GPA;
    }gpa;
    double FamilyIncome;
    char FirstName[128];
    char SecondName[128];
    char Patronymic[128];
    char GroupNumber[128];
  } Temporary;
  Temporary *temporary = (Temporary*) malloc(1 * sizeof(Student));
  bool proverka = false;
  int count = 0, check = 0, choose, CHOOSE = 0;
  double time;
  char Buffer[128];
  std::string buffer, buffer1, dop_buffer;
  std::cout << "выберите 1 из 2 предложенных вариантов: " << '\n';
  std::cout << "1 -> задать параметр после встречи которого в структуры вы сможете прекратить ввод" << '\n';
  std::cout << "0 -> не задавать" << '\n';
  bool start = false;
  while (!(std::cin >> start) || (std::cin.peek() != '\n')) { 
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "неправильный ввод:  " << std::endl;
  }
  if (start == true) {
    std::cout << "выберите нужный элемент структуры: " << '\n';
    std::cout << "\t1 - поиск по среднему балу " << '\n';
    std::cout << "\t2 - поиск по доходу на члена семьи " << '\n';
    std::cout << "\t3 - поиск по фамилии " << '\n';
    std::cout << "\t4 - поиск по имени " << '\n';
    std::cout << "\t5 - поиск по отчеству " << '\n';
    std::cout << "\t6 - поиск по номеру группы " << '\n';
    while (!(std::cin >> choose) || (std::cin.peek() != '\n') || choose < 1 || choose > 6) { 
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cout << "неправильный ввод:  " << std::endl;
    }
    if (choose == 1) {
      CHOOSE = 1;
      std::cout << "введите средний балл после встречи которого, сможете прервать дальнейший ввод новых структу: ";
      double GPA;
      while (!(std::cin >> GPA) || (std::cin.peek() != '\n') || GPA < 2 || GPA > 10) { 
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "неправильный ввод:  " << std::endl;
      }
      temporary[0].gpa.GPA = GPA;
    }
    else if (choose == 2) {
      CHOOSE = 2;
      std::cout << "введите номер группы после встречи которого, сможете прервать дальнейший ввод новых структу: ";
      double FamilyIncome;
      while (!(std::cin >> FamilyIncome) || (std::cin.peek() != '\n') || FamilyIncome < 0) { 
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "неправильный ввод:  " << std::endl;
      }
      temporary[0].FamilyIncome = FamilyIncome;
    }
    else if (choose == 3) {
      CHOOSE = 3;
      getchar();
      std::cout << "введите фамилию после встречи которого, сможете прервать дальнейший ввод новых структу: ";
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
      strcpy(temporary[0].SecondName,buffer.c_str());
    }
    else if (choose == 4) {
      CHOOSE = 4;
      getchar();
      std::cout << "введите имя после встречи которого, сможете прервать дальнейший ввод новых структу: ";
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
      strcpy(temporary[0].FirstName,buffer.c_str());
    }
    else if (choose == 5) {
      CHOOSE = 5;
      getchar();
      std::cout << "введите отчество после встречи которого, сможете прервать дальнейший ввод новых структу: ";
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
      strcpy(temporary[0].Patronymic,buffer.c_str());
    }
    else if (choose == 6) {
      CHOOSE = 6;
      getchar();
      std::cout << "введите номер группы после встречи которого, сможете прервать дальнейший ввод новых структу: ";
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
      strcpy(temporary[0].GroupNumber,buffer.c_str());
    }
  }
  // начало заполнения 
  bool GroupInput = false, a = false;
  count = 0, check = 0;
  buffer.clear();
  for (int i = 0; i < size; ++i) {
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
    if (GroupInput == false) {
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
    }
    else {
      std::cout << "введите номер группы студента: ";
      std::cout << "это поле было заполнено автоматически" << '\n';
    }
    
    count = 0;
    check = 0;
    GroupInput = false;
    if (CHOOSE > 0) {
      if (temporary[0].gpa.GPA == student[i].gpa.GPA ) {
      GroupInput = true;
      }
      else if (temporary[0].FamilyIncome == student[i].FamilyIncome) {
        GroupInput = true;
      }
      else if (strcmp(temporary[0].SecondName, student[i].SecondName) == 0) {
        GroupInput = true;
      }
      else if (strcmp(temporary[0].FirstName, student[i].FirstName) == 0) {
        GroupInput = true;
      }
      else if (strcmp(temporary[0].Patronymic, student[i].Patronymic) == 0) {
        GroupInput = true;
      }
      else if (strcmp(temporary[0].GroupNumber, student[i].GroupNumber) == 0) {
        GroupInput = true;
      }
    }
    if (GroupInput == true) {
      if (CHOOSE == 1) {
        std::cout << "был встречен стредний бал ->" << student[i].gpa.GPA << '\n';
        if (i != size - 1) {
          std::cout << "0 -> прекратить ввод \n1 -> продолжить ввод несмотря на совпадение с заданным значением: " << '\n';
          bool stop_or_not = 0;
          while (!(std::cin >> stop_or_not) || (std::cin.peek() != '\n')) { //проверка на ввод количества структур
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "неправильный ввод:  " << std::endl;
          }
          if (stop_or_not != 1) {
            student = (Student*)realloc(student, (i + 1) * sizeof(Student));
            size = i + 1;
            break;
          }
        }
      }
      else if (CHOOSE == 2) {
        std::cout << "был встречен заработок на члена семьи ->" << student[i].FamilyIncome << '\n';
        if (i != size - 1) {
          std::cout << "0 -> прекратить ввод \n1 -> продолжить ввод несмотря на совпадение с заданным значением: " << '\n';
          bool stop_or_not = 0;
          while (!(std::cin >> stop_or_not) || (std::cin.peek() != '\n')) { //проверка на ввод количества структур
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "неправильный ввод:  " << std::endl;
          }
          if (stop_or_not != 1) {
            student = (Student*)realloc(student, (i + 1) * sizeof(Student));
            size = i + 1;
            break;
          }
        }
      }
      else if (CHOOSE == 3) {
        std::cout << "была встречена фамилия ->" << student[i].SecondName << '\n';
        if (i != size - 1) {
          std::cout << "0 -> прекратить ввод \n1 -> продолжить ввод несмотря на совпадение с заданным значением: " << '\n';
          bool stop_or_not = 0;
          while (!(std::cin >> stop_or_not) || (std::cin.peek() != '\n')) { //проверка на ввод количества структур
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "неправильный ввод:  " << std::endl;
          }
          if (stop_or_not != 1) {
            student = (Student*)realloc(student, (i + 1) * sizeof(Student));
            size = i + 1;
            break;
          }
        }
      }
      else if (CHOOSE == 4) {
        std::cout << "было встречено имя ->" << student[i].FirstName << '\n';
        if (i != size - 1) {
          std::cout << "0 -> прекратить ввод \n1 -> продолжить ввод несмотря на совпадение с заданным значением: " << '\n';
          bool stop_or_not = 0;
          while (!(std::cin >> stop_or_not) || (std::cin.peek() != '\n')) { //проверка на ввод количества структур
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "неправильный ввод:  " << std::endl;
          }
          if (stop_or_not != 1) {
            student = (Student*)realloc(student, (i + 1) * sizeof(Student));
            size = i + 1;
            break;
          }
        }
      }
      else if (CHOOSE == 5) {
        std::cout << "было встречено отчество ->" << student[i].Patronymic << '\n';
        if (i != size - 1) {
          std::cout << "0 -> прекратить ввод \n1 -> продолжить ввод несмотря на совпадение с заданным значением: " << '\n';
          bool stop_or_not = 0;
          while (!(std::cin >> stop_or_not) || (std::cin.peek() != '\n')) { //проверка на ввод количества структур
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "неправильный ввод:  " << std::endl;
          }
          if (stop_or_not != 1) {
            student = (Student*)realloc(student, (i + 1) * sizeof(Student));
            size = i + 1;
            break;
          }
        }
      }
      else if (CHOOSE == 6) {
        std::cout << "был встречен номер группы ->" << student[i].GroupNumber << '\n';
        if (i != size - 1) {
          std::cout << "0 -> прекратить ввод \n1 -> продолжить ввод несмотря на совпадение с заданным значением: " << '\n';
          bool stop_or_not = 0;
          while (!(std::cin >> stop_or_not) || (std::cin.peek() != '\n')) { //проверка на ввод количества структур
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "неправильный ввод:  " << std::endl;
          }
          if (stop_or_not != 1) {
            student = (Student*)realloc(student, (i + 1) * sizeof(Student));
            size = i + 1;
            break;
          }
        }
      }
      CHOOSE = 0;
      GroupInput = false;
    }
    else {
      if (i != size - 1) {
        std::cout << "введите 1 ,если хочете заполнить данные еще об 1 студенте или 0 если хочете прекратить ввод: " << '\n';
        bool stop_or_not = 0;
        while (!(std::cin >> stop_or_not) || (std::cin.peek() != '\n')) { //проверка на ввод количества структур
          std::cin.clear();
          std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
          std::cout << "неправильный ввод:  " << std::endl;
        }
        if (stop_or_not != 1) {
          student = (Student*)realloc(student, (i + 1) * sizeof(Student));
          size = i + 1;
          break;
        }
      }
    }
    if (i != size - 1) {
      std::cout << "учиться ли ученик, о котором вы хочете заполнить информацию, в одной группе с прошлым? " << '\n';
      std::cout << "1 -- заранее заполнить поле - номер группы студента, номер группы будет - " << student[i].GroupNumber << '\n';
      std::cout << "0 -- заполнить все самому: " << '\n';  
      a = false;
      while (!(std::cin >> a) || (std::cin.peek() != '\n')) { 
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "неправильный ввод:  " << std::endl;
      }
      if (a == true) {
        strcpy(student[i + 1].GroupNumber, student[i].GroupNumber);
        GroupInput = true;
      }
    }
  }
  count = 0;
  for (int i = 0; i < size; ++i) {
    if (student[i].FamilyIncome < 2.0 * 626) {
      ++count;
      if (count == 1) {
        std::cout << "\tCписок студентов у которых доход на члена семьи менше 2 минимальных зарплат РБ: " << '\n';
      }
      std::cout << "СТУДЕНТ N" << i + 1 << ": " << '\n';
      std::cout << "средний балл учащегося: " << student[i].gpa.GPA << '\n';
      std::cout << "доход на члена семьи: " << student[i].FamilyIncome << '\n';
      std::cout << "имя студента: " << student[i].FirstName << '\n';
      std::cout << "фамилия студента: " << student[i].SecondName << '\n';
      std::cout << "отчество студента: " << student[i].Patronymic << '\n';
      std::cout << "номер группы студента: " << student[i].GroupNumber << '\n';
    }
    else {
      break;
    }
  }
  free(temporary);
  return size;
}
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
*/