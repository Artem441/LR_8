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